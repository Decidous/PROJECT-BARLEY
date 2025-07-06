#include <Servo.h>
#include <Wire.h>
#include <MPU6050.h>
#include <HardwareSerial.h>
#include <TinyGPS++.h>
#include <math.h>

#define HMC5883L_ADDRESS 0x1E // I2C address for HMC5883L

Servo myServo;
MPU6050 mpu;
TinyGPSPlus gps;
HardwareSerial GPSserial(1);

int buzzerPin = 2;

float pitch = 0;
unsigned long lastTime = 0;

// target coordinates
const float targetLat = 37.7749;   // example: perris california house address idk
const float targetLon = -122.4194;

void setup() {
  Serial.begin(115200);
  GPSserial.begin(9600, SERIAL_8N1, 16, 17);
  Wire.begin(21, 22);  // ESP32 I2C pins

  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed");
    while (1);
  }
  
  myServo.attach(27);
  myServo.write(90); // Start centered
  
  // Initialize HMC5883L magnetometer
  Wire.beginTransmission(HMC5883L_ADDRESS);
  Wire.write(0x00);
  Wire.write(0x70);
  Wire.endTransmission();

  Wire.beginTransmission(HMC5883L_ADDRESS);
  Wire.write(0x01);
  Wire.write(0xA0);
  Wire.endTransmission();

  Wire.beginTransmission(HMC5883L_ADDRESS);
  Wire.write(0x02);
  Wire.write(0x00);
  Wire.endTransmission();

  // Startup buzzer tones
  tone(buzzerPin, 400, 80);
  delay(80);
  noTone(buzzerPin);
  tone(buzzerPin, 500, 80);
  delay(80);
  noTone(buzzerPin);
  tone(buzzerPin, 600, 80);
  delay(80);
  noTone(buzzerPin);
  delay(1000);
  tone(buzzerPin, 800, 120);

  lastTime = millis();
}

void loop() {
  // 1. Read magnetometer data and calculate heading
  int16_t mx, my, mz;
  Wire.beginTransmission(HMC5883L_ADDRESS);
  Wire.write(0x03);
  Wire.endTransmission();
  Wire.requestFrom(HMC5883L_ADDRESS, 6);
  float heading = -1;
  if (Wire.available() == 6) {
    mx = Wire.read() << 8 | Wire.read();
    mz = Wire.read() << 8 | Wire.read();
    my = Wire.read() << 8 | Wire.read();
    heading = atan2(my, mx) * 180.0 / PI;
    if (heading < 0) heading += 360;
    Serial.print("Heading: ");
    Serial.println(heading);
  }

  // 2. Read MPU6050 pitch (optional, you can use this if needed for servo stabilization)
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  float axg = ax / 16384.0;
  float azg = az / 16384.0;
  float gyRate = gy / 131.0;
  float pitchAcc = atan2(-axg, azg) * 180.0 / PI;
  unsigned long now = millis();
  float dt = (now - lastTime) / 1000.0;
  lastTime = now;
  pitch = 0.98 * (pitch + gyRate * dt) + 0.02 * pitchAcc;
  Serial.print("Pitch: ");
  Serial.println(pitch);

  // 3. Read GPS data
  while (GPSserial.available() > 0) {
    gps.encode(GPSserial.read());
  }

  if (gps.location.isUpdated()) {
    float droneLat = gps.location.lat();
    float droneLon = gps.location.lng();
    Serial.print("GPS Lat: "); Serial.println(droneLat, 6);
    Serial.print("GPS Lon: "); Serial.println(droneLon, 6);

    // 4. Calculate bearing to target
    float bearingToTarget = calculateBearing(droneLat, droneLon, targetLat, targetLon);
    Serial.print("Bearing to target: ");
    Serial.println(bearingToTarget);

    // 5. Calculate difference between target bearing and current heading
    float angleDiff = bearingToTarget - heading;

    // Normalize angle difference to range -180 to +180
    if (angleDiff > 180) angleDiff -= 360;
    if (angleDiff < -180) angleDiff += 360;

    Serial.print("Angle difference: ");
    Serial.println(angleDiff);

    // 6. Map angle difference to servo angle (example: center = 90)
    // Adjust mapping as per your servo orientation and drone setup
    int servoAngle = map(angleDiff, -180, 180, 0, 180);
    servoAngle = constrain(servoAngle, 0, 180);
    myServo.write(servoAngle);
  }

  delay(200); // Adjust delay as needed
}

// --- Bearing calculation function ---
float deg2rad(float deg) {
  return deg * PI / 180.0;
}

float rad2deg(float rad) {
  return rad * 180.0 / PI;
}

float calculateBearing(float lat1, float lon1, float lat2, float lon2) {
  float dLon = deg2rad(lon2 - lon1);
  lat1 = deg2rad(lat1);
  lat2 = deg2rad(lat2);

  float y = sin(dLon) * cos(lat2);
  float x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(dLon);

  float brng = atan2(y, x);
  brng = rad2deg(brng);
  brng = fmod((brng + 360.0), 360.0); // Normalize to 0-360

  return brng;
}
