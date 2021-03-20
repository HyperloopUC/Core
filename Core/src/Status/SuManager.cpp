//Includes--------------------------------------------------------------------
#include "SuManager.h"

SuIdManager::SuIdManager(){

    for(int i = 0; i < SuId_SuIdCount; i++){
        SoftwareInstances[i] = 0;
    }

    SoftwareInstances[SuId_SuManager]++;
}

SuStatus SuIdManager::RegisterUnit(DeviceStatus* softwareUnit){

    SuStatus funcStatus = Status_Ok;

    if(!softwareUnit){
        funcStatus = Status_Null_Pointer;
        return funcStatus;
    }

    if(softwareUnit->IsSuId() == false){
        funcStatus = Status_Invalid_Index;
        return funcStatus;
    }

    SoftwareInstances[softwareUnit->GetSuId()]++;
    funcStatus = Status_Ok;
    return funcStatus;
}

SuStatus SuIdManager::UnRegisterUnit(DeviceStatus* softwareUnit){
    SuStatus funcStatus = Status_Ok;

    if(!softwareUnit){
        funcStatus = Status_Null_Pointer;
        return funcStatus;
    }

    if(softwareUnit->IsSuId() == false){
        funcStatus = Status_Invalid_Index;
        return funcStatus;
    }

    SoftwareInstances[softwareUnit->GetSuId()]--;
    funcStatus = Status_Ok;
    return funcStatus;
}