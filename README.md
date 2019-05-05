# ESP32ServoServer
A simplePacketComs server for servos on ESP32

# Depenencies
In the Arduino Library Manager, search for and install:

```
Esp32SimplePacketComs
Esp32WifiManager
SimplePacketComs
ESP32Servo
Adafruit_BNO055
Adafruit Unified Sensor Library
```
# Index Mapping

```
	map[0]= 15;
	map[1]= 2;
	map[2]= 4;
	map[3]= 16;
	map[4]= 17;
	map[5]= 5;
	map[6]= 19;
	map[7]= 23;
	map[8]= 13;
	map[9]= 12;
	map[10]= 14;
	map[11]= 27;
	map[12]= 26;
	map[13]= 25;
	map[14]= 33;
	map[15]= 32;
  ```
  
# Limb Use Mapping

<p>Attach the servos on the following pins:</p>

<p>RearLeft </p>





<ol><li>basePan = 2</li><li>baseTilt = 4</li><li>elbow = 15</li></ol>





<p>FrontRight&nbsp;</p>





<ol><li>basePan = 5</li><li>baseTilt = 17</li><li>elbow = 16</li></ol>





<p>FrontLeft&nbsp;</p>







<ol><li>basePan = 23</li><li>baseTilt = 19</li><li>elbow = 32</li></ol>





<p>RearRight&nbsp;</p>







<ol><li>basePan = 13</li><li>baseTilt = 12</li><li>elbow = 14</li></ol>





<p>Head&nbsp;</p>







<ol><li>basePan = 27</li><li>baseTilt = 26</li></ol>





<p>Tail&nbsp;</p>







<ol><li>basePan = 33</li><li>baseTilt = 25</li></ol>
