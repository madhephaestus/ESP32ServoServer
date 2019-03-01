/*
 * ServoServer.h
 *
 *  Created on: Mar 1, 2019
 *      Author: jmmckinney
 */

#ifndef SRC_SERVOSERVER_H_
#define SRC_SERVOSERVER_H_
#include <SimplePacketComs.h>
#include <ESP32Servo.h>
#define MAX_POSSIBLE_SERVOS 16
#include <stdint.h>

class ServoServer : public PacketEventAbstract {
private :
	Servo listOfServo[MAX_POSSIBLE_SERVOS];
	int map [MAX_POSSIBLE_SERVOS];

public:
	ServoServer();
	virtual ~ServoServer();
	//User function to be called when a packet comes in
	// Buffer contains data from the packet coming in at the start of the function
	// User data is written into the buffer to send it back
	void event(float * buffer);
};

#endif /* SRC_SERVOSERVER_H_ */
