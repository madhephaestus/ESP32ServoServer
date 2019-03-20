/*
 * ServoServer.cpp
 *
 *  Created on: Mar 1, 2019
 *      Author: jmmckinney
 */

#include "ServoServer.h"

ServoServer::ServoServer() :PacketEventAbstract(1962){
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

	for(int i=0;i<MAX_POSSIBLE_SERVOS;i++){
		//listOfServo[i].setPeriodHertz(100);
		listOfServo[i].attach(map[i], 1000, 2000);
		listOfServo[i].write(90);
	}
}

ServoServer::~ServoServer() {
	// TODO Auto-generated destructor stub
}

//User function to be called when a packet comes in
// Buffer contains data from the packet coming in at the start of the function
// User data is written into the buffer to send it back
void ServoServer::event(float * buffer){
	uint8_t * bBuffer = (uint8_t *)buffer;
	for(int i=0;i<MAX_POSSIBLE_SERVOS;i++){
		listOfServo[i].write(bBuffer[i]);
	}
}
