#include "Arduino.h"
#include <ESP32Servo.h>
#include <SimplePacketComs.h>
#include <WiFi.h>
#include <PacketEvent.h>
#include <Esp32SimplePacketComs.h>
#include <Preferences.h>
#include <wifi/WifiManager.h>
#include <server/NameCheckerServer.h>
#include "src/ServoServer.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include "src/GetIMU.h"
// SImple packet coms implementation useing WiFi
UDPSimplePacket coms;
// WIfi stack managment state machine
WifiManager manager;
//The setup function is called once at startup of the sketch
String * name = new String("hidDevice");
Adafruit_BNO055 bno;
GetIMU * sensor;
void setup()
{
	sensor = new GetIMU();
	/* Initialise the sensor
	if (!bno.begin()) {
		Serial.print(
				"Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
		delay(1000);
	}

	delay(1000);
	bno.setExtCrystalUse(true);
	sensor->startSensor(&bno);
	 * */

	manager.setup();
	coms.attach(new NameCheckerServer(name)); // @suppress("Method cannot be resolved")
	coms.attach(sensor);
	coms.attach(new ServoServer());
}

// The loop function is called in an endless loop
void loop()
{
	sensor->loop();
	manager.loop();
	if (manager.getState() == Connected)
		coms.server(); // @suppress("Method cannot be resolved")
	else {
		return;
	}
}
