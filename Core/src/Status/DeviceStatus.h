#ifndef _STATUS_DEVICE_STATUS_H_
#define _STATUS_DEVICE_STATUS_H_

//Includes---------------------------------------------------------------------
#include "stdint.h"
#include "SuIds.h"

enum SuStatus{
    Status_Ok = 0,
    Status_Not_Initialized,
    Status_Overflow,
    Status_Divide_By_Zero,
    Status_Invalid_Index,
    Status_Segmentation_Fault,
    Status_Memory_Limit_Exceeded,
    Status_Timeout,
    Status_Null_Pointer,
    Status_Buffer_Full,
    Status_Type_Missmatch,
    Status_Device_Initialization_Failed,
    Status_Port_Closed,

    Status_Count,
};

class DeviceStatus{

    public:

    /**
     * @brief Default constructor
     * 
     */ 
    DeviceStatus();

    /**
     * @brief Default constructor
     * 
     * @param suId the software unit Id
     * @param Status the status of the software unit
     */
    DeviceStatus(uint16_t suId);

    /**
     * @brief Initiailizes DeviceStatus object
     * 
     * @param suId the software unit Id
     * @param Status the status of the software unit
     */ 
    void Initialize(uint16_t suId); 

    /**
     * @brief Gets the software unit Id
     * 
     * @returns the software unit Id
     */
    uint16_t GetSuId();

     /**
     * @brief Gets the instance Id
     * 
     * @returns the software unit Id
     */   
    uint16_t GetInstanceId();

    /**
     * @brief Gets the status
     * 
     * @returns the status of the software unit
     */
    uint16_t GetStatus();

    /**
     * @brief Gets the software unit Id
     * 
     * @param suId the pointer to store the returned SuId
     * @returns the suId
     */
    void GetSuId(uint16_t* suId);

    /**
     * @brief Gets the instance Id 
     * 
     * @param instanceId the pointer to store the returned instance id
     * @returns the instance id
     */
    void GetInstanceId(uint16_t* instanceId);

    /**
     * @brief Gets the status
     * 
     * @param status the pointer to store the returned status
     * @returns the status
     */
    void GetStatus(uint16_t* status);

    /**
     * @brief checks if status is in an error state
     * 
     * @returns if the status is in an error state or not
     */
    bool IsError();

    /**
     * @brief checks if the status software unit Id is a valid one
     * 
     * @returns if the suId is valid or not
     */
    bool IsSuId();

    /**
     * @brief Sets the status 
     * 
     * @param status the status to be assigned
     */
    void SetStatus(SuStatus status);
    
    private:

    /**
     * SuId the software unit Id, identifies the Su type
     */
    uint16_t SuId;

    /**
     * InstanceId Stores the instance number for the softare unit
     */
    uint16_t InstanceId;
    
    /**
     * Status Stores the status enum 
     */
    SuStatus Status = Status_Not_Initialized;
};

#endif