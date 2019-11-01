/*
 * GetIMU.h
 *
 *  Created on: Jun 7, 2018
 *      Author: hephaestus
 */

#ifndef LIBRARIES_MEDIUMKATFIRMWARE_SRC_GETIMU_H_
#define LIBRARIES_MEDIUMKATFIRMWARE_SRC_GETIMU_H_


#include <SimplePacketComs.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#define NUM_IMU_VALUES 15
class GetIMU: public PacketEventAbstract {
private:
	Adafruit_BNO055 * bno;
//	imu::Vector<3> v;
//	imu::Vector<3> a;
//	imu::Vector<3> g;
//	imu::Vector<3> e;
	volatile float  bufferINTERNAL[NUM_IMU_VALUES];
	bool started;
	int updateIndex=0;
public:
	// Packet ID needs to be set
	GetIMU() :
		PacketEventAbstract(1804)	// Address of this event
{
		started=false;
		bno=NULL;
		setXPosition(0);
		setYPosition(0);
		setZPosition(0);
}
	//User function to be called when a packet comes in
	// Buffer contains data from the packet cming in at the start of the function
	// User data is written into the buffer to send it back
	void event(float * buffer);
	bool loop();
	void startSensor(Adafruit_BNO055 * _bno);
	void print();

	float getLINEARACCEL_X();
	float getLINEARACCEL_Y();
	float getLINEARACCEL_Z();
	float getGYROSCOPE_X();
	float getGYROSCOPE_Y();
	float getGYROSCOPE_Z();
	float getGRAVITY_X();
	float getGRAVITY_Y();
	float getGRAVITY_Z();
	float getEULER_azimuth();
	float getEULER_elevation();
	float getEULER_tilt();

	void setXPosition(float x);
	void setYPosition(float y);
	void setZPosition(float z);
};


#endif /* LIBRARIES_MEDIUMKATFIRMWARE_SRC_GETIMU_H_ */
