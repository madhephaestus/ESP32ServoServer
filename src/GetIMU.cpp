/*
 * GetIMU.cpp
 *
 *  Created on: Jun 7, 2018
 *      Author: hephaestus
 */

#include "GetIMU.h"
#include <Wire.h>
//User function to be called when a packet comes in
// Buffer contains data from the packet cming in at the start of the function
// User data is written into the buffer to send it back
void GetIMU::event(float * buffer) {
	if (!started)
		return;
	for (int i = 0; i < NUM_IMU_VALUES; i++) {
		buffer[i] = bufferINTERNAL[i];
	}

}
boolean GetIMU::loop() {
	if (!started)
		return true;
	imu::Vector<3> a;
	imu::Vector<3> v;
	imu::Vector<3> g;
	imu::Vector<3> e;
	switch (updateIndex) {
	case (0):
		a = bno->getVector(Adafruit_BNO055::VECTOR_LINEARACCEL);
		bufferINTERNAL[0] = a.z();
		bufferINTERNAL[1] = a.y();
		bufferINTERNAL[2] = a.x();
		break;
	case (1):
		v = bno->getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);
		bufferINTERNAL[3] = v.z();
		bufferINTERNAL[4] = v.y();
		bufferINTERNAL[5] = v.x();
		break;
	case 2:
		g = bno->getVector(Adafruit_BNO055::VECTOR_GRAVITY);
		bufferINTERNAL[6] = g.z();
		bufferINTERNAL[7] = g.y();
		bufferINTERNAL[8] = g.x();
		break;
	case 3:
		e = bno->getVector(Adafruit_BNO055::VECTOR_EULER);
		bufferINTERNAL[9] = e.z();// tilt
		bufferINTERNAL[10] = e.y();// elevation
		bufferINTERNAL[11] = e.x();// azimuth
	}
	updateIndex++;
	if (updateIndex == 4) {
		updateIndex = 3;
		return true;
	}
	return false;
}
void GetIMU::setXPosition(float x){
	bufferINTERNAL[12] =x;
}
void GetIMU::setYPosition(float y){
	bufferINTERNAL[13] =y;
}
void GetIMU::setZPosition(float z){
	bufferINTERNAL[14] =z;
}
float GetIMU::getLINEARACCEL_X() {
	return bufferINTERNAL[0];
}
float GetIMU::getLINEARACCEL_Y() {
	return bufferINTERNAL[1];
}
float GetIMU::getLINEARACCEL_Z() {
	return bufferINTERNAL[2];
}
float GetIMU::getGYROSCOPE_X() {
	return bufferINTERNAL[3];
}
float GetIMU::getGYROSCOPE_Y() {
	return bufferINTERNAL[4];
}
float GetIMU::getGYROSCOPE_Z() {
	return bufferINTERNAL[5];
}
float GetIMU::getGRAVITY_X() {
	return bufferINTERNAL[6];
}
float GetIMU::getGRAVITY_Y() {
	return bufferINTERNAL[7];
}
float GetIMU::getGRAVITY_Z() {
	return bufferINTERNAL[8];
}
float GetIMU::getEULER_azimuth() {
	return bufferINTERNAL[11];
}
float GetIMU::getEULER_elevation() {
	return bufferINTERNAL[10];
}
float GetIMU::getEULER_tilt() {
	return bufferINTERNAL[9];
}

void GetIMU::startSensor(Adafruit_BNO055 * _bno) {

	bno = _bno;
	started = true;
	//Serial.print(started);

}
void GetIMU::print() {
	if (!started)
		return;
	Serial.print("\r\n Euler= " + String(bufferINTERNAL[9]) + " , "
					+ String(bufferINTERNAL[10]) + " , "
					+ String(bufferINTERNAL[11]) + "\r\n ");
	/* Display calibration status for each sensor. */
	/*
	 uint8_t system, gyro, accel, mag = 0;
	 bno->getCalibration(&system, &gyro, &accel, &mag);
	 Serial.print("\r\n CALIBRATION: Sys=");
	 Serial.print(system, DEC);
	 Serial.print(" Gyro=");
	 Serial.print(gyro, DEC);
	 Serial.print(" Accel=");
	 Serial.print(accel, DEC);
	 Serial.print(" Mag=");
	 Serial.println(mag, DEC);
	 */
}
