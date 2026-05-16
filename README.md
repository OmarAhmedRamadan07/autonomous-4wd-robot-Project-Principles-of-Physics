# Recommended Repository Name: autonomous-obstacle-avoiding-robot

---

# Autonomous 4WD Obstacle Avoiding Robot 🚗🤖

An intelligent, autonomous 4-Wheel Drive (4WD) robot car built using Arduino. The robot is designed to navigate its environment independently by detecting and avoiding obstacles in real-time using ultrasonic sensors and a servo-mounted scanning mechanism.

Developed as an academic Physics/Robotics project at **El Sewedy University of Technology (SUT)**.

---

## 🔬 Physics Principles Applied

This project practically demonstrates the **Time of Flight** and **Speed of Sound** principles. 
The primary sensors (Ultrasonic HC-SR04) emit high-frequency sound waves (above the human hearing range). The sensor calculates the distance to an object by measuring the exact time it takes for the sound wave to bounce back after hitting the obstacle.

---

## 🚀 Features & Core Logic

* **Autonomous Navigation:** The robot moves forward continuously until an obstacle is detected within the threshold distance (e.g., 20 cm - 45 cm).
* **Environmental Scanning:** Upon detecting an obstacle, the robot stops, and the servo motor sweeps the ultrasonic sensor left and right to evaluate the surroundings.
* **Intelligent Decision Making:** The system compares the distances on both sides and automatically commands the L298N motor driver to turn the robot towards the clearest path.
* **Dual-Sensor Protection:** Utilizes both front and rear ultrasonic sensors to prevent collisions while reversing.

---

## 🛠️ Hardware Components

* **Microcontroller:** Arduino Uno
* **Motor Driver:** L298N Dual H-Bridge Motor Controller
* **Chassis:** 4WD Smart Robot Car Chassis Kit (Double Deck with 4 DC Motors)
* **Sensors:** Ultrasonic Sensors (Front and Rear)
* **Actuator:** Servo Motor (for 180-degree sensor sweeping)
* **Power Supply:** 12V Battery / Adapter

---

## 💻 Software & Libraries

The project is coded in C++ using the Arduino IDE. It relies on the following standard libraries:
* `<Servo.h>`: To control the scanning movement of the ultrasonic sensor.
* `<NewPing.h>` (Optional/Alternative): For optimized and accurate ultrasonic distance calculations.

---

## ⚙️ Future Improvements (Commercial Scalability)
As discussed in the project's theoretical framework, moving this prototype to a commercial product would involve:
1. Upgrading the microcontroller to **ESP32** or **STM32** for faster processing, more memory, and built-in Wi-Fi/Bluetooth capabilities.
2. Replacing standard ultrasonic sensors with waterproof or industrial-grade sensors for higher precision and durability.

---

## 👤 Author

* **Omar Ahmed Ramadan**
