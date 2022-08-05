#include <iostream>
#include "FUTEK_USB_DLL.h"
#include <string.h>
#include <stdio.h>
#include <ctime>
#include <ratio>
#include <chrono>
#include <unistd.h>
#include <fstream>
#include <cmath>

using namespace std;
int main()
{
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


    double offsetValue = stod(dll.Get_Offset_Value(deviceHandle, channelNumber));
    double fullScaleLoad = stod(dll.Get_Fullscale_Load(deviceHandle, channelNumber));
    double offsetLoad = stod(dll.Get_Offset_Load(deviceHandle, channelNumber));
    double fullScaleValue = stod(dll.Get_Fullscale_Value(deviceHandle, channelNumber));
    double decimalPoint = stod(dll.Get_Decimal_Point(deviceHandle, channelNumber));

    cout << "Get_Offset_Value: " << offsetValue << endl;
    cout << "Get_Fullscale_Load: " << fullScaleLoad << endl;
    cout << "Get_Offset_Load: " << offsetLoad << endl;
    cout << "Get_Fullscale_Value: " << fullScaleValue << endl;
    cout << "Get_Decimal_Point: " << decimalPoint << endl;

    while(true)
    {
        double normalDataRequest = stod(dll.Normal_Data_Request(deviceHandle, channelNumber));
        //cout << "Normal_Data_Request: " << normalDataRequest << endl;

        float torque = (normalDataRequest - offsetValue)*((fullScaleLoad - offsetLoad)/(fullScaleValue-offsetValue)) / pow(10, decimalPoint);

        cout << "torque: " << torque << endl;
        usleep((unsigned int)500000);
    }
    dll.Close_Device_Connection(serialNumber);

}