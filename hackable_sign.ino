#include <WiFi.h>
#include <WebServer.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "config.h"

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 5

//clk connectes to pin 18
//din connects to pin 23

/*
    TODO:
    Check for memory leaks
    Add functions to change scroll speed and text location
*/

MD_Parola display = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

//set wifi ssid and password
static const char *ssid = "ESP32 Acccess Point";
static const char *http_username = "admin";
static const char *http_password = "1337";
const char *default_text = "~~ Hack The Planet!!!!";
char *displayed_text = NULL;

//Configure networking
IPAddress local_ip(192,168,4,1);
IPAddress gateway(192,168,4,1);
IPAddress subnet(255,255,255,0);

//Configure server to run on port 80, the default port for http
WebServer server(80);
int curTime = millis();
EspClass esp;

void serve_page() {
    server.send(200, "text/html", code);
}


void check_heap() {
    Serial.print("Heap size: ");
    Serial.println(esp.getHeapSize());
    Serial.print("Free heap: ");
    Serial.println(esp.getFreeHeap());
    Serial.println();
}


char* update_display(String str) {
    char *newStr;
    display.displayClear(); // Clear the display

    int strLen = str.length()+1; //add 1 to include string null terminator
    newStr = (char*)malloc(strLen); //allocate needed memory for string
    Serial.println("Allocating memory for new display string");
    memcpy(newStr, str.c_str(), strLen); //copy string into allocated memory

    //display.displayScroll(newStr, PA_RIGHT, EFFECTS[lastEffect], 50); //update display
    return newStr;
}


int update_effect(String effect) {
    int effectNum = effect.toInt();

    if(effectNum <= MAX_EFFECT) {
        return effectNum;
    }
    return 17;
}


void handle_connect() {
    //set to null to signify that memory has not been allocated
    //static keyword means this will keep its value while out of scope
    //this allows memory to be freed in later calls of this function
    //static char *displayed_text = NULL;
    static int lastEffect = 15; //default scroll left effect
    Serial.println("Handle connect called");

    if(!server.authenticate(http_username, http_password)) { //make sure user has logged in with username and password
        return server.requestAuthentication();
    }
    if(server.args() > 0) {
        if(server.arg("display").length() > 0) {
            if(displayed_text != NULL) { //make sure memory is allocated before attempting to free
                Serial.println("Freeing space of previous display string");
                free(displayed_text); //free memory before allocating more
                displayed_text = NULL;
                //check_heap();
            }
            displayed_text = update_display(server.arg("display"));
            //Serial.print("String recieved: ");
            //Serial.println(server)
            //check_heap();
        }

        if(server.arg("effect") != "") {
            lastEffect = update_effect(server.arg("effect"));
        }
       
        if(displayed_text != NULL) {
            display.displayScroll(displayed_text, PA_RIGHT, EFFECTS[lastEffect], 50); //update display
        }
        else {
            display.displayScroll(default_text, PA_RIGHT, EFFECTS[lastEffect], 50); //update display
        }

    }

    Serial.println("Sending webpage");
    serve_page();
}


void setup() {
    Serial.begin(115200); //Init serial connection so we can read output in terminal

    displayed_text = update_display(default_text);
    display.begin();
    display.setIntensity(10); // Change brightness from 0 to 15
    display.displayClear();
    display.displayScroll(displayed_text, PA_RIGHT, PA_SCROLL_LEFT, 50);

    Serial.println("Configuring Access Point");
    WiFi.mode(WIFI_AP); //Configure ESP to be an access point rather than a client
    WiFi.softAP(ssid); //Configure ssid and password of the acces point
    if(WiFi.softAPConfig(local_ip, gateway, subnet)) { //verify ap config succeeded
        Serial.println("AP config succeeded");
    }

    //void (*connectPtr)(char*) = &handle_connect;

    server.on("/", handle_connect); //Run this when a client connects

    server.begin(); //Start access point
}


void loop() {
  server.handleClient();

  if(display.displayAnimate()) {
    display.displayReset();
  }
}
