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

std::string get_torque(){

    _FUTEK_USB_DLL::FUTEK_USB_DLL dll;

    PVOID deviceHandle ;
    BYTE channelNumber = 0;

    string sn = dll.Get_Device_Serial_Number(0);
    char *serialNumber = new char[sn.length() + 1];
    strcpy(serialNumber, sn.c_str());
    dll.Open_Device_Connection(serialNumber);
    deviceHandle = dll.DeviceHandle;

    string boardType = dll.Get_Type_of_Board(deviceHandle);
    string firmVersion = dll.Get_Firmware_Version(deviceHandle);
    string samplingRate = dll.Get_ADC_Sampling_Rate(deviceHandle, channelNumber);

    string adc = dll.Normal_Data_Request(deviceHandle, channelNumber);
    return adc;

}

PYBIND11_MODULE(bind_test, handle){
    handle.doc()="TEST";
    handle.def("python_name", &get_torque);
}