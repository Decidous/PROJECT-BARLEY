# PROJECT: BARS
![Screenshot 2025-07-05 160646](https://github.com/user-attachments/assets/ba66c7da-d65c-43fe-bd49-112b2f5330d7)
![Screenshot 2025-07-05 161748](https://github.com/user-attachments/assets/5b323947-18f0-4abf-86c7-b22ad91e4d52)

## Description
Project Barley, or B.A.R.S., short for Barangay Aerial Relief System, is a project that combines drones with the capabilities of GPS. In particular, the project is an autonomous, self-navigating drone using multiple sensors to reach a coordinate and return back home, all with one goal: to deliver relief packages of local places in need (AKA food, medical supplies, etc.). This project is my attempt to combine the resources currently available to autonomous vehicle designing on the internet, and companies like Zipline, to make my own version of an AUV. 

## The way it works is simple:
1. User packs a package in its fuselage, utilizing a disposable parachute to slow it’s decent to target coordinates
User uploads target coordinates
2. Drone is sent off, calculating a simple route towards the coordinates
3. After coordinates are reached, it’s hatches below open and perform a 180 clockwise fight reroute back home
4. Drone is caught with a net for simplicity sake
## Why I built it
* Project has been halted for a whole year
I started designing this project a year ago, but then I stopped because I was too focused on rocketry. I am focusing on this project again now because it has a lot of potential for real-world applications. 
* This tech is not very available around the world
Zipline is my biggest inspiration, but they have limited hubs. I’d like to simplify this technology a ton so that implementation of this drone in other countries is less of a burden. 
* I think aerospace is cool
Everything aerospace related is super interesting to me, and although I switched my major from aerospace engineering to chemistry, I still super like the industry’s challenges and what they strive to solve. This is a main reason why I do rocketry and is trying to expand on my experiences on the field.

#BOM
| Platform                          | Description                                                | Price per listed lot | # of parts per listed lot | Lots to purchase | Final Price (CAD) | Final Price (USD) | Already Owned? | Comments | Link |
|----------------------------------|------------------------------------------------------------|-----------------------|----------------------------|------------------|--------------------|--------------------|----------------|----------|------|
| (2x) SG90 Servo                  | Heavier, larger load servo type for wing flap control     | $7.99                 | 4                          | 1                | 10.86              | 7.99               | no            |          | [Link](https://www.amazon.com/Micro-Servos-Helicopter-Airplane-Controls/dp/B07MLR1498/ref=sr_1_6) |
| MG996R Servo Motor              | Lighter, smaller load servo type for hatch control        | $9.99                 | 2                          | 1                | 13.59              | 9.99               | no             |          | [Link](https://www.amazon.com/AEDIKO-MG996R-Control-Digital-Helicopter/dp/B09BZ5955Z/ref=sr_1_3) |
| ESP32-WROOM                     | Wifi + Cloud capabilities for real-time location data     | $11.99                | 3                          | 1                | 16.03              | 11.99              | no             |          | [Link](https://www.amazon.com/ESP-WROOM-32-Development-Dual-Mode-Microcontroller-Compatible/dp/B0D53M13NS) |
| NEO-6M GPS Module ZC323200      | Listens to GPS location + calculations                    | $8.99                 | 2                          | 1                | 12.23              | 8.99               | no             |          | [Link](https://www.amazon.com/HiLetgo-GY-NEO6MV2-Controller-Ceramic-Antenna/dp/B01D1D0F5M) |
| Passive Buzzer CYT1008          | Emits sound for pre/post-flight procedures                | $5.99                 | 10                         | 1                | 8.15               | 5.99               | no             |          | [Link](https://www.amazon.com/Cylewet-Terminals-Electronic-Electromagnetic-Impedance/dp/B01NCOXB2Q/ref=sr_1_1) |
| BMP280 Barometer                | Consistent Altitude reading                                | $5.99                 | 5                          | 1                | 8.15               | 5.99               | no             |          | [Link](https://www.amazon.com/KOOBOOK-GY-BMP280-3-3-Precision-Atmospheric-Barometric/dp/B07S98QBTQ/ref=sr_1_1) |
| MPU6050 Accelerometer           | Orientation calibration                                    | $9.59                 | 3                          | 1                | 13.04              | 9.59               | no             |          | [Link](https://www.amazon.com/EC-Buying-Accelerometer-Gyroscope-Module16-Bit/dp/B0B3D6D1KD/ref=sr_1_2) |
| Puffin Smart 4G LTE-Advanced USB WiFi | Utilizes a SIM card for 4G cellular communication to the ESP32 | $41.00         | 1                          | 1                | 55.76              | 41.00              | no             |          | [Link](https://www.amazon.com/Puffin-Smart-LTE-Advanced-Dongle-Hotspot/dp/B0DSJZ8KVB/ref=sr_1_8) |
| GY-273 Magnetometer             | Functions as a compass for 2D navigation                   | $7.99                 | 2                          | 1                | 10.87              | 7.99               | no             |          | [Link](https://www.amazon.com/Comimark-QMC5883L-Compass-Magnetometer-Arduino/dp/B0855TZV1J/ref=sr_1_1) |
| A2212 Brushless Motor Propeller | 10 inch propellers                                         | $9.99                 | 2                          | 1                | 13.59              | 9.99               | no             |          | [Link](https://www.amazon.com/uxcell-Propellers-2-Vane-Airplane-Adapter/dp/B07YYV9Q2X/ref=sr_1_4) |
| Bullet Adapters                 | 3.17 mm shaft adapters                                     | $7.99                 | 4                          | 1                | 10.87              | 7.99               | no             |          | [Link](https://www.amazon.com/RuiLing-3-17mmxM5-Airplane-Propeller-Electric/dp/B07HR7JPCK/ref=sr_1_1) |
| Carbon Fiber tube               | 20mm diameter, 1 meter long                                | $22.99                | 1                          | 1                | 31.27              | 22.99              | no             |          | [Link](https://speedyfpv.com/products/1000mm-3k-carbon-fiber-tubes-16-18-20-25mm-matte-glossy-1mm-2mm-walls) |

