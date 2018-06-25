# tshirtRF
New t-shirt cannon code for both Arduinos using the RF system.

Lots of cool info to be added...

Now, for the cool info :)

So, Reciever_NEW contains all of the files for the reciever on the t-shirt cannon, an arduino UNO. Note that the whole folder is required, and must be named the same as the main scetch (Reciever_UNO). Further, to upload this to the arduino, the shield must be removed. The XBee (RF module) uses the same Rx and Tx pins on the arduino UNO as the USB, so it interferes. A potential way to fix this is to add switches to disable the connection between the XBee and the arduino while the shield is still connected.

The transmitter is much simpler, as it utilizes an arduino MEGA, with multiple serial interfaces. You can just upload Transmitter_MEGA directly, but the one catch is that the library provided (RGB-master) must be included. If using the desktop interface, you can just download the RGB-master folder and move it to the libraries folder of arduino's documents. If using the cloud and plugin, well, you'll just have to figure it out on your own.





Also, fun fact. You may have noticed the receiver was spelled reciever everywhere. Deal with it.
