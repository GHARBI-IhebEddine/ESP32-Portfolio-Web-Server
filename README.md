# ESP32 Portfolio Web Server

## Overview

This repository contains the source code for an ESP32-based Portfolio Web Server. The project serves as a personal portfolio showcasing HTML, CSS, JavaScript, images, and other files stored on the ESP32's SPIFFS filesystem.

## Project Features

- **Web Server:** Utilizes the ESPAsyncWebServer library to create an asynchronous web server on the ESP32.
- **SPIFFS Filesystem:** Files such as HTML, CSS, JavaScript, images, and more are stored on the ESP32's SPIFFS filesystem.
- **Port Forwarding:** Set up port forwarding on your router to make your portfolio accessible to the public.

## Prerequisites

Before getting started, ensure you have the following:

- Arduino IDE with ESP32 support
- ESP32 board installed in Arduino IDE
- ESP32FS tool (e.g., [ESP32FS-1.1](https://github.com/me-no-dev/arduino-esp32fs-plugin)) installed for uploading files to SPIFFS
- WiFi network with internet access

## Portfolio Files

The portfolio content is stored in the `data` folder. This folder contains HTML, CSS, JavaScript, images, and other files that make up your portfolio.

## Installation Steps

1. **Upload Files to SPIFFS:**
   - Use the ESP32FS tool to upload your HTML, CSS, JavaScript, images, and other files to the ESP32's SPIFFS filesystem.

2. **Configure WiFi:**
   - Update the `ssid` and `password` variables in the code with your WiFi credentials.

3. **Adjust IP Configuration:**
   - Optionally, configure the static IP address, gateway, and subnet in the code based on your network preferences.

4. **Port Forwarding:**
   - Set up port forwarding on your router to forward external traffic on a specific port (e.g., 80) to the local IP address of your ESP32.

5. **Compile and Upload:**
   - Compile and upload the code to your ESP32 using the Arduino IDE.

6. **Access Your Portfolio:**
   - Open a web browser and navigate to your public IP address or domain name with the specified port (e.g., `http://your_public_ip:80`).

## Contributions

Contributions are welcome! If you encounter any issues or have suggestions for improvements, feel free to open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).
