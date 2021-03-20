#ifndef _COMMS_SERIAL_CONSOLE_H_
#define _COMMS_SERIAL_CONSOLE_H_

#define BAUD_RATE 9600
//includes---------------------------------------------------------------------
#include "Status/DeviceStatus.h"
#include "Status/SuManager.h"
#include "Arduino.h"
#include <string.h>

class SerialConsole{

    public:

    /**
     * @brief Default Constructor
     * 
     */
    SerialConsole();

    /**
     * @brief Initializes the serial console
     * 
     * @returns the status of the function
     */
    DeviceStatus Initialize(SuIdManager* manager);

    /**
     * @brief Prints to serial console
     * 
     * @param message the string to print 
     * @returns the status of printing the message
     */
    DeviceStatus Print(String message);

    private:

    DeviceStatus MyStatus = DeviceStatus(SuId_SerialConsole);
};

#endif