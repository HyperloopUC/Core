//Includes--------------------------------------------------------------------
#include "SerialConsole.h"

SerialConsole::SerialConsole(){

    MyStatus.SetStatus(Status_Not_Initialized);
}

DeviceStatus SerialConsole::Initialize(SuIdManager* manager){

    SuStatus FunctionStatus = Status_Not_Initialized;
    if(!manager){
        FunctionStatus = Status_Null_Pointer;
    }else{
        manager->RegisterUnit(&MyStatus);
        Serial.begin(BAUD_RATE);
        if(!Serial){
            FunctionStatus = Status_Port_Closed;
        }else{
            FunctionStatus = Status_Ok;
        }
    }
    MyStatus.SetStatus(FunctionStatus);
    return MyStatus;
}

DeviceStatus SerialConsole::Print(String message){

    SuStatus FunctionStatus = Status_Ok;
    if(!Serial){
        FunctionStatus = Status_Port_Closed;
    }else{
        Serial.println(message);
        FunctionStatus = Status_Ok;
    }
    MyStatus.SetStatus(FunctionStatus);
    return MyStatus;
}