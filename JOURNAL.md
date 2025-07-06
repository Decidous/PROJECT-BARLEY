
Title: "Project: BARS" <br>
Author: "Decidous" <br>
Description: "AUV capable of delivering packages via the use of GPS coordinates!" <br>
Created_at: "2025-06-27" <br>

#Total Time: 32 Hours
# 2025-06-28
Started this project amidst a vacation outside of the United States, so time available to work on this project is limited daily. Started part outsourcing: I started looking at the parts needed, but got only the main ones down (aka ESP32-WROOM, accelerometer + barometer + magnometer, etc) planning to continue the GPS/autonomous parts selection of this project some future date. These are the main components I usually use for my rocketry projects.
## Allotted time: 2 hours

# 2025-06-29
First instances of modeling, started with the ribs of the frame for the drone. I’ve decided to allocate a lot of space in Teh fuselage to fit packages 6 inches X 6 inches, and while this might not be a lot of space, it still contains the basic potential concept of delivering packages 
![image](https://github.com/user-attachments/assets/8f77f4c7-f5d6-4931-bbc0-fb41a828faeb)
## allotted time: 2 hours

# 2025-06-30
I continued the modeling of the plane’s main airframe, and while doing some research, have decided that fiberglass is a fantastic middle ground of tensile strength and flexibility. I had 3 options from order of tensile strength and weight: aluminum, fiberglass, and carbon fiber. The availability of fiberglass rods I recalled from a ZNA video I watched a long time ago when he used it to make a bow and arrow.
![image](https://github.com/user-attachments/assets/aeffc98e-cd12-449a-8b41-b1b3f90b0e1d)

https://www.youtube.com/watch?v=0XofhpYmaEU
## allotted time: 2 hours

# 2025-07-01
I continued with the designs of the different parts for the drone: the gates needed to hold the packages, the connectors connecting the fiberglass rods of the wings to the fuselage, and the wing profiles. The wing profile I currently have is called the symmetrical airfoil, which is supposed to be good for “precision aerobatics”. I am choosing this one also because it is the simplest to construct.
Flight test airfoil explanations: https://www.flitetest.com/articles/what-airfoil-should-i-use
![image](https://github.com/user-attachments/assets/463baa57-82bc-405f-81cb-eec8ed5f2aff)
## allotted time: 4 hours

# 2025-07-02
focused on combining everything together: the wing profiles, the gates, and the connectors. The paneling of the plane, I anticipate, would be made of Kraft foam to lessen the weight. For the nose and tail design, which were a bit more tricky, I designed only the corners to be 3d printed, but the centers of the nose and tail would still be filled with Kraft foam.
![image](https://github.com/user-attachments/assets/8576ea4a-e994-4040-9117-1e5d46609e33)
## allotted time: 3 hours

# 2025-07-03
Originally I had planned an H shape for the tail, but I did some research and the more V and /\ shapes (like the tail from the RQ-7 Shadow) you have in the front cross section of the plane, the better it is for aerodynamic self-leveling to correct for yaw drift. While yaw control would still be needed, this greatly lessens the strain of servos, leading to a potentially longer battery life and flight endurance. I finished modeling the wing flaps and added a tail light mount. I then struggled for a few hours trying to figure out how to mount the brushless motor in the aft end of the fuselage, I will definitely be coming back to the design because lofting is not ideal for angled pieces to hold fiberglass rods.
Study focusing on Dihedral Effects: https://journals.sagepub.com/doi/full/10.1155/2013/308582
![image](https://github.com/user-attachments/assets/24456455-da07-4fb0-b21e-8787ee53a673)
## allotted time: 4 + 2 hours

# 2025-07-04
added color to assembly/fixed a few issues (dark = 3d printed framing, white = 3d printed shelling, orange = fiberglass rods for structure) + also researched more on GPS to focus on finalizing the BOM.
https://www.youtube.com/watch?v=F9lim5l9R7c -> GPS basic compass
https://www.youtube.com/watch?v=vi_cIuxDpcA&ab_channel=CircuitDigest -> sending to a cloud
## 5+ hours spent researching dif methods of wireless coms:
So, first I was thinking of using a wifi router + esp32, then realized i have no idea how internet works. I had to do a bunch of research to learn that the internet is basically provided via ethernet, and a wifi router serves as a well to that data. My challenge is that you need to be able to send data to a public server to track the location of the drone, and the methods to do that are:
1. cellular (with wifi -> https://www.youtube.com/watch?v=B96JGoWQOsE&t=1413s&ab_channel=Tesseract) 
2. Long-range radio (bps.space rocket telemetry -> https://www.youtube.com/watch?v=pZ572Rjj9vA&t=779s&ab_channel=BPS.space)
3. satelite data (wayyyy too expensive, but would work with ANY coordinate in the world)
4. sd card (simple hardware, but requires the drone to come back)
Cellular seems like the best bet due to its pretty good range (as long as there is a cell tower in proximity) as well as its affordability. Found a well-priced SIM 4G/5G modem that can be used to transmit data: "Puffin Smart 4G LTE-Advanced USB WiFi"

Also, finished a wiring schematic for the avionics:
![Screenshot 2025-07-05 162947](https://github.com/user-attachments/assets/6c0809b6-622c-4c4a-a868-6052969af5fd)
## allotted time: 7 hours

# 2025-07-05
Made adjustments to motor mount for tail, door hatch servo system for deploying disaster relief supplies, finalized 3d model and finished up shelling, added models for servo and brushless motor
![Screenshot 2025-07-05 160646](https://github.com/user-attachments/assets/4be03f4c-fa60-40e2-a2cf-153c1ab0fdf6)
![Screenshot 2025-07-05 161748](https://github.com/user-attachments/assets/69bb3873-3ed0-4c0b-b713-98e73c315a9b)
![image](https://github.com/user-attachments/assets/f32f8dc2-d467-45b8-b1ff-182942efee01)
## allotted time: 6 hours
