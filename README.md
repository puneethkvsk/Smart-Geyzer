# Smart-Geyzer
Implementation of Smart Geyzer for home application is described as follows.

In this project I will share how the Smart Geyzer circuit was designed and used as a Plug-n-Play solution to existing conventional Geyzer at home. You can find Bill of Materials, Source Code, Curcuit Diagram and couple of Pictures of Implementation and Important Notes below.

**Important Notes:**
1. I used a NodeMCU for this application, hence used Arduino IDE to write the code.
2. Also, I realised later that any other ESP-8266 Module consuming lower power would suffice. Example-ESP-8266-01 (Also it would have consumed lesser current :P)
4. I used a Relay Module and not just a Relay. Relay Module will run on 3.3V input whereas a Relay component mostly needs 5v to work.
5. Blynk application was used to set up the User Interface to control the Geyzer from phone. Please check any youtube video to set up the Blynk app. Once you set up a Blynk account, I will be glad to help you with using the Blynk app for this project in case you have any issues. Please email me on puneeth.kvsk@gmail.com

**Bill of Materials:**
1. Node MCU
2. 20A relay module (Any relay module above 16A rating will suffice to control any Geyzer)
3. 3-Pin Electrical Sockets (One Male and One Female)
4. Temperature Sensor - DS18B20 - This module is perfect for any temperature measurment application
5. 220V-5V step down converter for the NodeMCU, Temperature Sensor, Relay Module to work
6. Copper board, Wires, Soldering Kit

**Source Code:**

To get the source code running, make a New Folder called "smartGeyzerCode" and then put the smartGeyzerCode.ino file in it. Now, you need to install the following libraries before compiling and uploading the code to your microcontroller. Go to Tools, then ManageLibraries and search for the following libraries:
1. OneWire library
2. Dallas Temperature
3. ESP8699WiFi
4. Blynk (This will automatically have BlynkSimpleESP8266 which we want to use)

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


