#include <WiFi.h>
#include <WebServer.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "config.h"

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 14
#define DATA_PIN 27
#define CLK_PIN 12

MD_Parola display = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

//set wifi ssid and password
static const char *ssid = "ESP32 Acccess Point";
static const char *http_username = "admin";
static const char *http_password = "1337";

//Configure networking
IPAddress local_ip(192,168,4,1);
IPAddress gateway(192,168,4,1);
IPAddress subnet(255,255,255,0);

//Configure server to run on port 80, the default port for http
WebServer server(80);

void serve_page() {
    int maxLen = 1000;
    char code[maxLen];
    snprintf(code, maxLen,
      "<!DOCTYPE html>"
      "<html>"
        "<head><title>CONTROL DISPLAY</title></head>"
        "<body>"
          "<div>"
            "<form action='/' method='post'>"
                "<p>New Text: </p>"
                "<input type='text' name='%i' placeholder='What would you like to tell the world?'>"
                "<br>"
                "<select name='%i'>"
                    "<option value='Effect 1'>" //change to function that will do all these for me
                    "<option value='Effect 2'>" //change to function that will do all these for me
                "</select>"
                "<br>"
                "<input type='submit' value='Change'>"
            "</form>"
          "</div>"
        "</body>"
      "</html>", UPDATE_DISPLAY, UPDATE_ACTION);

      server.send(200, "text/html", code);
}


void update_effect() {

}


void update_display() {
    display.displayClear(); // Clear the display
    // Scroll the new text
    Serial.print("New text test: ");
    Serial.println(server.arg(UPDATE_DISPLAY).c_str());
    display.displayScroll(server.arg(UPDATE_DISPLAY).c_str(), PA_RIGHT, PA_SCROLL_LEFT, 50); 
}


void handle_connect() {
    if(!server.authenticate(http_username, http_password)) { //make sure user has logged in with username and password
        return server.requestAuthentication();
    }

    const int numArgs = server.args();
    Serial.print("Arg count: ");
    Serial.println(server.arg(0));
    
    if(numArgs > 0) {
        for(int i = 0; i < numArgs; i++) {
            switch(server.arg(i).toInt()) {
                case 0: //update display
                    update_display(); 
                    break;
                case 1:
                    update_effect();
                    break;
            }
        } 
      }

    Serial.println("Sending webpage");
    serve_page();
    //server.send(200, "text/html", code);
}


void setup() {
    Serial.begin(115200); //Init serial connection so we can read output in terminal

    static const char *default_text = "~~ Hack The Planet!!!!";
    display.begin();
    display.setIntensity(10); // Change brightness from 0 to 15
    display.displayClear();
    display.displayScroll(default_text, PA_RIGHT, PA_SCROLL_LEFT, 50);

    Serial.println("Configuring Access Point");
    WiFi.mode(WIFI_AP); //Configure ESP to be an access point rather than a client
    WiFi.softAP(ssid); //Configure ssid and password of the acces point
    WiFi.softAPConfig(local_ip, gateway, subnet);

    server.on("/", handle_connect); //Run this when a client connects

    server.begin(); //Start access point
}

void loop() {
  server.handleClient();

  if(display.displayAnimate()) {
    display.displayReset();
  }
}
