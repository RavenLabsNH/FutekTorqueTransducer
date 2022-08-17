#include <pybind11/pybind11.h>
#include <iostream>
#include "FUTEK_USB_DLL.h"
#include <string.h>
#include <stdio.h>
#include <ctime>
#include <ratio>
#include <chrono>
#include <unistd.h>
#include <fstream>

namespace py = pybind11;

using namespace std;

_FUTEK_USB_DLL::FUTEK_USB_DLL dll;

class Interface
{

public:
    Interface();
    bool connect();
    float getTorque();
    void closeConnection();

private:
    PVOID deviceHandle;
    BYTE channelNumber = 0;
    double offsetValue;
    double fullScaleLoad;
    double offsetLoad;
    double fullScaleValue;
    double decimalPoint;

};

Interface::Interface(){    
}

bool Interface::connect()
{
    try{
        string sn = dll.Get_Device_Serial_Number(0);
        char *serialNumber = new char[sn.length() + 1];
        strcpy(serialNumber, sn.c_str());
        dll.Open_Device_Connection(serialNumber);
        deviceHandle = dll.DeviceHandle;

        string deviceCount = dll.Get_Device_Count();
        string boardType = dll.Get_Type_of_Board(deviceHandle);
        string firmVersion = dll.Get_Firmware_Version(deviceHandle);
        string samplingRate = dll.Get_ADC_Sampling_Rate(deviceHandle, channelNumber);


        offsetValue = stod(dll.Get_Offset_Value(deviceHandle, channelNumber));
        fullScaleLoad = stod(dll.Get_Fullscale_Load(deviceHandle, channelNumber));
        offsetLoad = stod(dll.Get_Offset_Load(deviceHandle, channelNumber));
        fullScaleValue = stod(dll.Get_Fullscale_Value(deviceHandle, channelNumber));
        decimalPoint = stod(dll.Get_Decimal_Point(deviceHandle, channelNumber));
    }
    catch (...){
        return false;
    }

    return true;
    
    
}

float Interface::getTorque(){

    float torque;
    try{
        double normalDataRequest = stod(dll.Normal_Data_Request(deviceHandle, channelNumber));
        torque = (normalDataRequest - offsetValue)*((fullScaleLoad - offsetLoad)/(fullScaleValue-offsetValue)) / pow(10, decimalPoint);
    }
    catch (...){
        torque = -1.0;
    }

    return torque;

}

void Interface::closeConnection(){

    dll.Close_Device_Connection(deviceHandle);
}


PYBIND11_MODULE(futek, handle){
    handle.doc()="TEST";
    py::class_<Interface>(handle, "Interface")
        .def(py::init<>())
        .def("connect", &Interface::connect)
        .def("get_torque", &Interface::getTorque)
        .def("close_connection", &Interface::closeConnection);
}
