#include "FUTEK_USB_DLL.h"
#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;
int main(){
    _FUTEK_USB_DLL::FUTEK_USB_DLL dll;

    PVOID deviceHandle ;
    BYTE channelNumber = 0;


    cout << "Start" << endl;
    string sn = dll.Get_Device_Serial_Number(0);
    cout << "After Get_Device_Serial_NUmber" << endl;
    char *serialNumber = new char[sn.length() + 1];
    strcpy(serialNumber, sn.c_str());
    cout << "After stcpy" << endl;
    dll.Open_Device_Connection(serialNumber);
    cout << "After Open_Device_Connection" << endl;
    deviceHandle = dll.DeviceHandle;
    cout << "After DeviceHandle" << endl;

    cout << "Device Information" << endl;
    cout << endl;
    string deviceCount = dll.Get_Device_Count();
    cout << "Device Count: " << deviceCount << endl;
    cout << "Serial Number: " << sn << endl;
    string boardType = dll.Get_Type_of_Board(deviceHandle);

    cout << "Board Type: " << boardType << endl;

    string samplingRate = dll.Get_ADC_Sampling_Rate(deviceHandle, channelNumber);
    cout << "Sampling Rate: " << samplingRate << endl;

    // string resetBoard = dll.Reset_Board(deviceHandle);
    // cout << "Reset Board: " << resetBoard << endl;

    string unitCode = dll.Get_Unit_Code(deviceHandle, channelNumber);
    cout << "Unit Code: " << unitCode << endl;

    string decPoints = dll.Get_Decimal_Point(deviceHandle, channelNumber);
    cout << "Decimal Points: " << decPoints << endl;

    //Calibration Information
    string calibrationCode = dll.Get_Calibration_Code(deviceHandle,channelNumber);
    cout << "Calibration Code: " << calibrationCode << endl;

    string calDay = dll.Get_Calibration_Day(deviceHandle);
    string calMonth = dll.Get_Calibration_Month(deviceHandle);
    string calYear = dll.Get_Calibration_Year(deviceHandle);

    cout << "Calibration Date DD/MM/YY: " << calDay << "/" << calMonth << "/" << calYear << endl;

    string averageSetting = dll.Get_Average_Setting(deviceHandle, channelNumber);
    cout << "Average Setting: " << averageSetting << endl;

    string bridgeResistance = dll.Get_Bridge_Resistance(deviceHandle, channelNumber);
    cout << "Bridge Resistance: " << bridgeResistance << endl;
    string direction = dll.Get_Direction(deviceHandle, channelNumber);
    cout << "Direction: " << direction << endl;
    string hardwareVersion = dll.Get_Hardware_Version(deviceHandle);
    cout << "Hardware Version: " << hardwareVersion << endl;
    string sensitivity = dll.Get_Sensitivity(deviceHandle, channelNumber);
    cout << "Sensitivity: " << sensitivity << endl;
    string adcPGASetting = dll.Get_ADC_PGA_Setting(deviceHandle, channelNumber);
    cout << "ADC PGA Setting: " << adcPGASetting << endl;
    string sensorIDNumber = dll.Get_Sensor_Identification_Number(deviceHandle);
    cout << "Sensor Identification Number: " << sensorIDNumber << endl;
    string shuntValue = dll.Get_Shunt_Value(deviceHandle);
    cout << "Shunt value: " << shuntValue << endl;
    
    cout << endl;
        //Firmware information
    cout << "Firmware information" << endl;
    cout << endl;

    string firmVersion = dll.Get_Firmware_Version(deviceHandle);
    cout << "Firmware Version: " << firmVersion << endl;

    string firmYear = dll.Get_Firmware_Year(deviceHandle);
    cout << "Firmware Year: " << firmYear << endl;

    string firmMonth = dll.Get_Firmware_Month(deviceHandle);
    cout << "Firmware Month: " << firmMonth << endl;

    cout << endl;
    //Loads and ADC Values
    cout << "Loads and Values" << endl;
    cout << endl;

    string numLoadingPoints = dll.Get_Number_of_Loading_Points(deviceHandle);
    cout << "Number of loading points: " << numLoadingPoints << endl; 

    string offsetLoad = dll.Get_Offset_Load(deviceHandle, channelNumber);
    cout << "Offset Load: " << offsetLoad << endl;

    string fullscaleLoad = dll.Get_Fullscale_Load(deviceHandle, channelNumber);
    cout << "Fullscale Load: " << fullscaleLoad << endl;

    string fullscaleValue = dll.Get_Fullscale_Value(deviceHandle, channelNumber);
    cout << "Fullscale Value: " << fullscaleValue << endl;
    cout << endl;

    int numPoints = atoi(numLoadingPoints.c_str());
    for(int i = 0; i < numPoints; ++i)
    {
        string loadingPointLoad = dll.Get_Load_of_Loading_Point(deviceHandle, i);
        string loadingPoint = dll.Get_Loading_Point(deviceHandle, i);
        cout << "Point: [Load, ADC] > " << i << ": [" << loadingPointLoad << "," << loadingPoint << "]";
        cout << endl;
    }
    cout << endl;

    if(boardType == "11")
    {

        cout << "Rotation Value Information" << endl;
        cout << endl;

        string rotationValue = dll.Get_Rotation_Values(deviceHandle);
        cout << "Rotation Value: " << rotationValue << endl;

        int angleValue = dll.Get_Angle_Value();
        int rpmValue = dll.Get_RPM_Value();
        cout << "Angle Value: " << angleValue << endl;
        cout << "RPM Value: " << rpmValue << endl;

        string outputType = dll.Get_Output_Type(deviceHandle, channelNumber);
        cout << "Output Type: " << outputType << endl; 
        string pulsesPerRotation = dll.Get_Pulses_Per_Rotation(deviceHandle, channelNumber);
        cout << "Pulses per rotation: " << pulsesPerRotation << endl;
        string crossTalk = dll.Get_CrossTalk(deviceHandle, channelNumber);
        cout << "Cross Talk: " << crossTalk << endl;
        string voltageOutput = dll.Get_Voltage_Output(deviceHandle, channelNumber);
        cout << "Voltage Output: " << voltageOutput << endl;
        string numberOfActiveChannels = dll.Get_Number_of_Active_Channels(deviceHandle, channelNumber);
        cout << "Number of Active Channels: " << numberOfActiveChannels << endl;
        string typeOfCalibration = dll.Get_Type_of_Calibration(deviceHandle, channelNumber);
        cout << "Type of Calibration: " << typeOfCalibration << endl;
        string activePageNumber = dll.Get_Active_Page_Number(deviceHandle, channelNumber);
        cout << "Active Page Number: " << activePageNumber << endl;
        
    }

    cout << endl;

    dll.Close_Device_Connection(serialNumber);
}
