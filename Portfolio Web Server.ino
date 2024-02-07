/*
  Author: GHARBI Iheb Eddine
  Project: ESP32 Portfolio Web Server
  Description: This is an open-source portfolio web server running on an ESP32. 
               It serves HTML, CSS, JavaScript, images, and other files to showcase your portfolio.

  Hardware: ESP32

  Note: This code assumes the SPIFFS filesystem is used to store web files on the ESP32.

  Instructions:
  - Configure the WiFi credentials (ssid, password).
  - Upload HTML, CSS, JavaScript, image, and other files to the SPIFFS filesystem.

  Dependencies:
  - ESPAsyncWebServer library
  - SPIFFS library
  - WiFi library

  Special Thanks to the ESPAsyncWebServer library contributors.

*/

#include "WiFi.h"
#include "SPIFFS.h"
#include "ESPAsyncWebServer.h"

#define FORMAT_SPIFFS_IF_FAILED true

const char* ssid = "YourWiFiSSID";
const char* password =  "YourWiFiPassword!";

AsyncWebServer server(80);
// Define the IP address configuration for the ESP32
IPAddress local_IP(0, 0, 0, 0);  // Set the desired local IP address
IPAddress gateway(0, 0, 0, 0);     // Set the gateway IP address
IPAddress subnet(0, 0, 0, 0);    // Set the subnet mask


const char* files[] = {
  "/bootstrap.min.css",
  "/main.png",
  // Add other file routes here
};

const char* types[] = {
  "text/css",
  "image/png",
  // Add other MIME types here
};

void setup() {
  // Initialize SPIFFS
  if(!SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED)){
    return;
  }

  // Configure WiFi
  if (!WiFi.config(local_IP, gateway, subnet)) {
    return;
  }
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  // Route to serve the main index page ("/")
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", "text/html");
  });

  // Register handlers for each file route
  for (size_t i = 0; i < sizeof(files) / sizeof(files[0]); ++i) {
    server.on(files[i], HTTP_GET, [i](AsyncWebServerRequest *request){
      request->send(SPIFFS, files[i], types[i]);
    });
  }

  // Start the server
  server.begin();
}

void loop() {}
