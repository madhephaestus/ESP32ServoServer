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

// SImple packet coms implementation useing WiFi
UDPSimplePacket coms;
// WIfi stack managment state machine
WifiManager manager;
//The setup function is called once at startup of the sketch
String * name = new String("KChef");

void setup()
{
	manager.setup();
	coms.attach(new NameCheckerServer(name)); // @suppress("Method cannot be resolved")
	coms.attach(new ServoServer());
}

// The loop function is called in an endless loop
void loop()
{
	manager.loop();
	if (manager.getState() == Connected)
		coms.server(); // @suppress("Method cannot be resolved")
	else {
		return;
	}
}
