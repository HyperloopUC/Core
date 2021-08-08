#ifndef _IO_ANALOG_WIRE_H_
#define _IO_ANALOG_WIRE_H_

//includes---------------------------------------------------------------------
#include "Status/DeviceStatus.h"
#include "Status/SuManager.h"
#include "Arduino.h"

class AnalogWire{

    public:

    /**
     * @brief Default Constructor
     * 
     */

    AnalogWire();

    /** 
     * @brief Initializes the analog pin
     * 
     * @param SuIdManager the software unit manager
     * @param pin the analog pin
     * 
     * @returns the status of the function
     */
    DeviceStatus Initialize(SuIdManager* manager, uint16_t pin);


    private:

    DeviceStatus MyStatus = DeviceStatus(SuId_AnalogWire);

    uint16_t pin;

};
#endif