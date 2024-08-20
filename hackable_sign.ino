#include <WiFi.h>

const char *ssid = "ESP32 Acccess Point";
const char *password = "changeme";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFi.mode(WIFI_AP);

}

void loop() {
  // put your main code here, to run repeatedly:

}
