#ifndef _STATUS_SU_MANAGER_H_
#define _STATUS_SU_MANAGER_H_

//includes---------------------------------------------------------------------
#include "DeviceStatus.h"
#include "SuIds.h"

class SuIdManager{

    public:

    /**
     * @brief Default contructor 
     */
    SuIdManager();
 
    /**
     * @brief Registers the software uniit
     *
     * @param softwareUnit the pointer to the device status 
     * @returns the status of the function
     */
    SuStatus RegisterUnit(DeviceStatus* softwareUnit);

    /**
     * @brief Removes software unit from registry
     * 
     * @param softwareUnit the pointer to the device status
     * @returns the status of the function
     */
    SuStatus UnRegisterUnit(DeviceStatus* softwareUnit);

    private:

    uint16_t SoftwareInstances[SuId_SuIdCount];

};

#endif