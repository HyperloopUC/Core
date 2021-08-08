
#ifndef _SENSORS_CURRENT_SENSOR_H_
#define _SENSORS_CURRENT_SENSOR_H_

//includes---------------------------------------------------------------------
#include "Status/DeviceStatus.h"
#include "Status/SuManager.h"
#include "Arduino.h"
#include "IO/AnalogWire.h"

class CurrentSensor{

    public:

    /**
     * @brief Default contstructor 
     * 
     */

    CurrentSensor();

    /**
     * @brief Intitializes the sensor
     * 
     * @param SuIdManager the software unit manager
     * @param pin the analog pin 
     * 
     * @returns the status of of the function
     */

    DeviceStatus Intitialize(SuIdManager* manager, uint16_t pin);

    /**
     * @brief reads current value from sensor
     * 
     * @param current the returned current reading in milliamps
     * @returns the status of the function
     */

    DeviceStatus ReadCurrent(uint16_t* current);

    private:

    DeviceStatus MyStatus = DeviceStatus(SuId_CurrentSensor);

    AnalogWire MySignal;

};    

#endif