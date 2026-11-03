# SeatSense
Library seat occupancy detection prototype using micro:bit and Arduino
## Project Overview
- Project Name: SeatSense
- Project Background: It is difficult to directly check seat availability in the open study areas of the UTS Library, and students may have to search floor by floor for an open seat.
- Project Objective: To explore the feasibility of using sensors to determine seat availability.
- Final Functionality: Utilizes ultrasonic sensors to measure distance and displays the detection results via the Arduino’s onboard LED.
- Project Scope: An experimental prototype, rather than a seat management system ready for actual deployment.
## Development Versions
Version    Main Content
V1 — Initial Simulation    Use a micro:bit and Python to simulate pressure data via a button and determine whether a seat is occupied based on a threshold.
V2 — Improved Simulation    Add a pressure accumulation mechanism and use two thresholds to implement three states: EMPTY, LIGHT, and OCCUPIED.
V3 — Distance Sensor Testing    Switched to the Arduino UNO R4 Minima and the HC-SR04 ultrasonic sensor to measure actual distance and display the results via the Serial Monitor.
V4 — Final Prototype    Added LED status feedback, set a detection threshold of 20 cm, and reduced status changes caused by occasional anomalies by counting consecutive invalid readings.
## Hardware Components
Device    Purpose
micro:bit    Programming and simulation for V1 and V2
Arduino UNO R4 Minima    Main control board for V3 and V4
HC-SR04 Ultrasonic Sensor    Measures the distance between objects and the sensor
Breadboard    Helps connect circuits
Jumper Wires    Connect the Arduino to sensors
USB Cable    Connects to a computer, uploads programs, and provides power
Built-in LED    Status indicator for V4
## Wiring Connections
HC-SR04     Arduino UNO R4 Minima
VCC         5V
GND         GND
Trig        D9
Echo        D10
## How to Run
V1–V2: micro:bit Python
1. Open the micro:bit Python Editor.
2. Import the corresponding .py file.
3. Run the code on the simulator or a compatible micro:bit device.
4. Use Button A and Button B to simulate different pressure levels.
5. Observe how the LED patterns change.
V3–V4: Arduino C++
1. Prepare an Arduino UNO R4 Minima and an HC-SR04.
2. Complete the wiring according to the Wiring Connections section.
3. Open the Arduino IDE or Arduino Cloud Editor.
4. Select the correct board and port.
5. Open the corresponding .ino file and upload it.
6. Open the Serial Monitor and set the baud rate to 9600.
7. Move an object and observe the distance reading.
## Limitations
First, the sensor measurements are unstable.
When testing with a palm, the sensor occasionally displays “No reading,” but readings are more stable when using an iPad case with a relatively smooth surface.
Second, it cannot distinguish between people and ordinary objects.The HC-SR04 primarily measures the distance to an object and cannot independently identify whether it has detected a person, a backpack, or some other object.
Third, testing in a real-world seating environment has not yet been conducted.
The current 20 cm threshold is an experimental parameter and has not yet been fully validated on actual library seats.
Therefore, SeatSense can currently only demonstrate basic object distance detection and status feedback; it cannot guarantee accurate determination of whether a seat is available.
## Acknowledgements
UTS Creative Coding    Classroom instruction, teacher-recommended sensor selections, and hardware equipment loaned by the school
micro:bit Python Editor    Programming environment used for V1 and V2
Arduino Cloud Editor    Programming and code-upload environment used for V3 and V4
Google Search    Used to look up programming concepts and resources related to Arduino and sensors
ChatGPT (OpenAI)    Used to assist with learning the basics of Arduino C++, understanding code, and discussing debugging issues
