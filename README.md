# Smart-Geyzer
Implementation of Smart Geyzer for home application is described as follows.

In this project I will share how the Smart Geyzer circuit was designed and used as a Plug-n-Play solution to existing conventional Geyzer at home. You can find Bill of Materials, Source Code, Curcuit Diagram and couple of Pictures of Implementation and Important Notes below.

Important Notes:
1. I used a NodeMCU for this application, hence used Arduino IDE to write the code.
2. I used Node MCU for this project. Realised later that any other ESP-8266 Module consuming lower power would suffice. Example - ESP-8266-01 (Also it would have consumed lesser current :P)
3. I used a Relay Module and not just a Relay. Relay Module will run on 3.3V input whereas a Relay componenet mostly needs 5v to work.

Bill of Materials:

1. Node MCU
2. 20A relay module (Any relay module above 16A rating will suffice to control any Geyzer)
3. 3-Pin Electrical Sockets (One Male and One Female)
4. Temperature Sensor - DS18B20 - This module is perfect for any temperature measurment application
5. 220V-5V step down converter for the NodeMCU, Temperature Sensor, Relay Module to work
6. Copper board, Wires, Soldering Kit

Source Code:

To get the source code running, first put make a new folder called "smartGeyzerCode" and then put the smartGeyzerCode.ino file in it. Now, you need to install the following libraries before compiling and uploading the code to your microcontroller. Go to Tools-->ManageLibraries-->Search for the following libraries and install them.
1. OneWire library
2. Dallas Temperature

Circuit Diagram:
![1621756292563](https://user-images.githubusercontent.com/54372026/119252443-ed5c4580-bbc9-11eb-8174-5c7ac7730786.jpg)

Pictures of Implementation:
