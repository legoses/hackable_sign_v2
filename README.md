# Hackable Sign V2
This electronic sign project uses an ESP32 broadcasting an SSID. It allows users to connect to the network where they can interact with a web server that allows an authenticated user to change the text on a dot matrix display (MAX7219). Non-authenticated users can attempt to hack the web server to change the text.

Most of the code used to communicate to the MAX7219 dot matrix display was taken from Micro Controllers Lab https://microcontrollerslab.com/install-esp32-arduino-ide/.

NOTE: This project is intentionally insecure. It is meant to be hacked. 

## Hardware requirements
- ESP32
- MAX7219 Dot Matrix Display
- Micro USB cable
- Computer with the Arduino IDE (or PlatformIO; however, the instructions below will use the Arduino IDE)
- Wires

## Default settings:
- SSID: ESP32 Access Point
- Web portal: http://192.168.4.1
- Web portal username: admin
- Web portal password: 31337

## Variables you may want to change:
On line  you can find the default text. This is the text that the device will display on boot. There is no persistence when you change the text from the web interface. 
```String text = "HACK THE PLANET!!!";```

On lines 25 and 26 you'll find the web console default credentials. There is no password to connect to the sign via WiFi. The credentials are only for when you actually try to change the text. 
```const char* http_username = "admin";```
```const char* http_password = "31337";```

On line 32 you'll find the IP address of the web interface. You should be able to change it to anything you want within the 192.168.4.0/24 range but this is not very important. The important thing to know is that this will be how you access the web interface to change the text. By default you'd go to http://192.168.4.1. 
```IPAddress local_IP(192, 168, 4, 1);```

Lastly on line 24 you can change the SSID. The default is "ESP32 Access Point".
```const char* ssid = "ESP32 Access Point";```

## Connect MAX7219 to ESP32
The following table shows how to connect the pins on the MAX7219 display to the ESP32 using wires. If the ESP32 has pins pre-sodered you can use the female to female wires that typically come bundled with the MAX7219. 
```
+---------------------+
|  MAX7219 |  ESP32   |
+---------------------+
|    VCC   |   3.3V   |
|    GND   |   GND    |
|    DIN   |   D23    |
|    CS    |   D5     |
|    CLK   |   D18    |
+---------------------+
```

## Arduino Setup
#### Add the ESP32 board to the Arduino IDE (from https://espressif.github.io/arduino-esp32/package_esp32_index.json)
- [Download and install Arduino IDE 1.x or 2.x](https://www.arduino.cc/en/software)
- Start Arduino and open the Preferences window 
- Enter ```https://espressif.github.io/arduino-esp32/package_esp32_index.json``` into the File>Preferences>Additional Boards Manager URLs field of the Arduino IDE. You can add multiple URLs, separating them with commas.
- Open Boards Manager from Tools > Board menu and install esp32 platform (and don't forget to select your ESP32 board from Tools > Board menu after installation).

#### Install libraries
- In Arduino IDE go to Tools>Manage Libraries (CTRL + SHFT + I)
- You will need to install two libraries: ```MD_MAX72xx``` and ```MD_Parola``` 
- Search for ```MD_MAX72xx``` and install the library. 
	- You will be asked if you want to install "ALL" dependencies. Select "Install ALL"
	- If you do not select "Install ALL" you will need to also install the library ```MD_Parola``` 

