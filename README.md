# Smart-Geyzer
Implementation of Smart Geyzer for home application is described as follows. First of all......DISCLAIMER! This is a long file to read. It is this long only because I have tried to make it as easy as I can for those of you who are starting out.

In this file I will share how the Smart Geyzer circuit was designed and used as a Plug-n-Play solution to existing conventional Geyzer at home. You can find all the information required to implement the project below.

**Important Notes:**

1. If you don't understand the meaning of any WORD mentioned in this file, please google it. You need to understand the terms if you want to do this project.
2. Blynk application was used to set up the User Interface to control the Geyzer from phone. Please check any youtube video to set up the Blynk app. Once you set up a Blynk account, find notes below on Blynk to understand more. I will be glad to help you with using the Blynk app for this project in case you have any issues. 
3. It took me sometime to figure out how I can put my temperature sensor inside the Geyzer and how to set-up the circuit near the Geyzer. If you have any questions, please email them to puneeth.kvsk@gmail.com. I will be glad to help you with any type of queries.
4. Why are the uploaded pictures so big on Github??? * *facepalm* *


**Bill of Materials:**

1. Node MCU
2. 20A relay module (Any relay module above 16A rating will suffice to control any Geyzer)
3. 3-Pin Electrical Sockets (One Male and One Female)
4. Temperature Sensor - DS18B20 - This module is perfect for any temperature measurment application
5. 220V-5V step down converter for the NodeMCU, Temperature Sensor, Relay Module to work
6. Copper board, Wires, Connectors, Soldering Kit and other miscellaneous stuff
7. Software - Arduino IDE was used. Follow the steps mentioned under the Source Code Notes section.

**Explaination for each component Start:**

**NodeMCU-** 

I used NodeMCU to make my project. But frankly, NodeMCU is a really powerful micro-controller which can do much more than just this Smart Geyzer project. Hence, any other ESP-8266 module consuming lower power would have actually sufficed. Example-ESP-8266-01. Same code can be used for both ESP8266-01 and NodeMCU for this project. We need an USB-UART converter to program the ESP-8266-01 module. Please find the notes under "Programming ESP-8266-01" to understand how you can implement this project using ESP-8266-01.

**Relay-**

A **Relay component** works on 5V supply whereas a **Relay Module** mostly works on 3V supply. Hence using a Relay Module is advantageous for this project since the output of the ESP Module is 3.3V.

**Blynk app-**

Blynk app is really useful when it comes to building these personal projects. It's free to use for your first Project. You can use this link to download the Blynk app on your phone: //Put the Blynk app link here

After downloading the Blynk app, you need to create a new project. I named my project as Smart Geyzer. Now open Smart Geyzer and on the right-top corner, you'll find an Add button using which you can add Widgets. Check out the User Interface of my project below to find the widgets I used.

![WhatsApp Image 2021-05-24 at 3 23 52 PM](https://user-images.githubusercontent.com/54372026/119330703-249f2500-bca4-11eb-9527-2cd5dd16742d.jpeg)

The following **Widget Options section** is only for the people who are blindly copying my code. For others, I suggest you put your own settings and try tweaking the User Interface to your satisfaction.

*Widget Options Section Start:*

*NOTE:*  You need to declare specific Virtual Pins to use these Widgets for this app. If you're using the code I attached in this repo, then you HAVE TO use the same Widgets I used. Duh, that's why you're still reading this.

As you can see, I used a GUAGE, LCD DISPLAY and SLIDER widgets for the project.

*Setting up the Widget options:*

On the Blynk App, after selecting the Widget settings set each Widget's options exactly as shown below.

GUAGE - 

![WhatsApp Image 2021-05-24 at 3 32 39 PM (2)](https://user-images.githubusercontent.com/54372026/119331787-64b2d780-bca5-11eb-8826-f191e3e0d20f.jpeg)

LCD DISPLAY -

![WhatsApp Image 2021-05-24 at 3 32 39 PM (1)](https://user-images.githubusercontent.com/54372026/119331977-99269380-bca5-11eb-9596-85b0b19ea502.jpeg)

SLIDER -

![WhatsApp Image 2021-05-24 at 3 32 39 PM](https://user-images.githubusercontent.com/54372026/119331997-a04da180-bca5-11eb-8f81-20aa8b1a3c5c.jpeg)

*Widget Options Section End:*

**Explaination for each component Start:**

**Software and Source Code Notes Start:**

To get the source code running, make a New Folder called "smartGeyzerCode" and then put the smartGeyzerCode.ino file in it. Now, you need to install the following libraries before compiling and uploading the code to your microcontroller. Go to Tools, then ManageLibraries and search for the following libraries:
1. OneWire library
2. Dallas Temperature
3. ESP8699WiFi
4. Blynk (This will automatically have BlynkSimpleESP8266 which we want to use)

**Software and Source Code Notes End:**


**Circuit Diagram:**

Note: S1-Socket 1, S2-Socket 2
![1621756892625](https://user-images.githubusercontent.com/54372026/119252729-60b28700-bbcb-11eb-9855-f02c77ba375e.jpg)


**Implementation:**

**Here is a link to the video of the set-up:**

https://drive.google.com/file/d/1Jqz6hd2vjtD2o2p1hl0gsFlotfA9h_1t/view?usp=sharing

**And here are some pictures of how I set it up:**

![1621759033635](https://user-images.githubusercontent.com/54372026/119253772-678fc880-bbd0-11eb-83fd-6e75657df036.jpg)

![1621759033626](https://user-images.githubusercontent.com/54372026/119253788-7aa29880-bbd0-11eb-8ea1-a500c870451f.jpg)

![1621759033630](https://user-images.githubusercontent.com/54372026/119253809-9017c280-bbd0-11eb-88b4-3e31180c2e7a.jpg)


