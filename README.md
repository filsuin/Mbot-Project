# Mbot Project

This project allows you to control an ESP8266 robot via a web interface. The robot can move forward, backward, turn left, turn right, and stop.

## Required Hardware

- ESP8266
- Motors connected to the GPIO pins of the ESP8266

## Pin Configuration

The GPIO pins used to control the motors are defined as follows:

- IN1: D1 (GPIO5)
- IN2: D2 (GPIO4)
- IN3: D5 (GPIO14)
- IN4: D6 (GPIO12)

## Installation

1. Clone this repository or download the files.
2. Open the `mbot.ino` file in the Arduino IDE.
3. Make sure you have the following libraries installed:
   - ESP8266WiFi
   - ESPAsyncWebServer
4. Connect your ESP8266 to your computer.
5. Upload the code to your ESP8266.

## Usage

1. Once the code is uploaded, the ESP8266 will create a Wi-Fi access point with the SSID `ESP-Robot`.
2. Connect to this Wi-Fi network (no password required).
3. Open a web browser and go to the IP address displayed in the serial monitor (usually `192.168.4.1`).
4. Use the web interface to control the robot.

## Available Commands

- **Forward**: The robot moves forward.
- **Backward**: The robot moves backward.
- **Left**: The robot turns left.
- **Right**: The robot turns right.
- **Stop**: The robot stops.