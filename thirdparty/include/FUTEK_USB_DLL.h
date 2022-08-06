//
//  FUTEK_USB_DLL.h
//  FUTEK_USB_DLL
//
//  Created by Brandon King on 11/18/14.
//  Copyright (c) 2014 FUTEK Advanced Sensor Technology, Inc. All rights reserved.
//

#ifndef __FUTEK_USB_DLL__FUTEK_USB_DLL__
#define __FUTEK_USB_DLL__FUTEK_USB_DLL__

#include "ftd2xx.h"
#include <stdio.h>
#include <string>
#include <limits>
#include <cmath>
#include <ctime>

#ifdef __cplusplus
extern "C" {
#endif
    
#pragma GCC visibility push(hidden)
    
    class FUTEK_FTD2XX
    {
        
    public:
        FT_DEVICE FT_Device;
        FT_HANDLE FT_Handle;
        FT_STATUS FT_Status;
        
        FT_DEVICE_LIST_INFO_NODE *FT_Device_List_Info_Node;
        
        DWORD FT_Device_Count;
        
        char FT_Serial_Number[16];
        char FT_Description[64];
        
        //char FT_RX_Buffer[256];
        //char FT_TX_Buffer[256];
        
        unsigned char FT_RX_Buffer[1024];
        unsigned char FT_TX_Buffer[1024];
        
        DWORD FT_VID = 0x0403;
        DWORD FT_PID = 0x6001;
        
        DWORD FT_RXQ_Bytes;
        DWORD FT_TXQ_Bytes;
        
        FUTEK_FTD2XX();
        
        void FUTEK_FT_SetVIDPID();
        void FUTEK_FT_GetVIDPID();
        
        void FUTEK_FT_CreateDeviceInfoList();
        void FUTEK_FT_GetDeviceInfoList();
        
        void FUTEK_FT_GetDeviceCount();
        void FUTEK_FT_GetDeviceSerialNumber(PVOID DeviceIndex);
        void FUTEK_FT_GetDeviceDescription(PVOID DeviceIndex);
        
        void FUTEK_FT_OpenByIndex(int DeviceIndex);
        void FUTEK_FT_OpenExBySerialNumber();
        void FUTEK_FT_OpenExByDescription();
        
        void FUTEK_FT_Close();
        
        void FUTEK_FT_GetDeviceInfo();
        void FUTEK_FT_Purge();
        void FUTEK_FT_SetTimeouts(DWORD ReadTimeout, DWORD WriteTimeout);
        
        void FUTEK_FT_Read(DWORD BytesToRead);
        void FUTEK_FT_Write(DWORD BytesToWrite);
        
        void FUTEK_FT_SetLatencyTimer(UCHAR LatencyTimer);
        void FUTEK_FT_GetLatencyTimer();
        
        void FUTEK_FT_SetUSBParameters(DWORD InTransferSize, DWORD OutTransferSize);
        
        void FUTEK_FT_GetStatus();
        
    private:
        
    protected:
        
    };
    
#pragma GCC visibility pop
    
    
#pragma GCC visibility push(default)
    namespace _FUTEK_USB_DLL{
        class FUTEK_USB_DLL
        {
            
        public:
            
            FUTEK_FTD2XX DriverInterface;
            
            PVOID DeviceHandle;
            ULONG DeviceStatus;
            
            std::string PacketSent;
            std::string PacketReceived;
            
            char ErrorDescription[64];
            
            std::string DisplayPage;
            std::string LCDLine1;
            std::string LCDLine2;
            std::string LCDLine3;
            std::string LCDLine4;
            
            BYTE DataSignByte;
            BYTE DataHighByte;
            BYTE DataMiddleByte;
            BYTE DataLowByte;
            
            BOOL VirtualMode = false;
            
            int VirtualSerialNumber = 123456;
            
            int DataLogging_Counter;
            int DataLogging_Value1;
            int DataLogging_Value2;
            int DataLogging_Value3;
            int DataLogging_Value4;
            
            //void Open_Device_Connection(char* SerialNumber);
            FUTEK_USB_DLL();
            void Open_Device_Connection(char SerialNumber[16]);
            void Close_Device_Connection(PVOID DeviceHandle);
            
            std::string Slave_Activity_Inquiry(PVOID DeviceHandle);
            
            std::string Set_ADC_Configuration(PVOID DeviceHandle, BYTE SamplingRate, BYTE ChannelNumber);
            std::string Set_ADC_Configuration2(PVOID DeviceHandle, BYTE ADCConfiguration, BYTE ChannelNumber);
            
            std::string Get_Offset_Value(PVOID DeviceHandle, BYTE ChannelNumber);
            std::string Get_Fullscale_Value(PVOID DeviceHandle, BYTE ChannelNumber);
            std::string Normal_Data_Request(PVOID DeviceHandle, BYTE ChannelNumber);
            
            std::string Version_of_Board(PVOID DeviceHandle);
            std::string Reset_Board(PVOID DeviceHandle);
            
            std::string Get_Device_Count();
            std::string Get_Device_Serial_Number(PVOID DeviceIndex);
            
            std::string Get_Offset_Load(PVOID DeviceHandle, BYTE ChannelNumber);
            
            std::string Get_Fullscale_Load(PVOID DeviceHandle, BYTE ChannelNumber);
            
            std::string Get_Unit_Code(PVOID DeviceHandle, BYTE ChannelNumber);
            
            std::string Get_Decimal_Point(PVOID DeviceHandle, BYTE ChannelNumber);
            
            std::string Read_EEPROM_Register(PVOID DeviceHandle, BYTE Address);
            
            std::string Read_Channel_Register(PVOID DeviceHandle, BYTE ChannelNumber, BYTE Address);
            
            std::string Read_Memory_Register(PVOID DeviceHandle, BYTE Address);
            
            std::string Get_Loading_Point(PVOID DeviceHandle, int Point, BYTE ChannelNumber = 0, int TypeOfCalibration = 0);
            std::string Get_Load_of_Loading_Point(PVOID DeviceHandle, int Point, BYTE ChannelNumber = 0);
            std::string Get_Calibration_Code(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Calibration_Day(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Calibration_Month(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Calibration_Year(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_CrossTalk(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Firmware_Month(PVOID DeviceHandle);
            std::string Get_Firmware_Version(PVOID DeviceHandle);
            std::string Get_Firmware_Year(PVOID DeviceHandle);
            std::string Get_Active_Page_Number(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_ADC_PGA_Setting(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_ADC_Sampling_Rate(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Analog_Voltage_Output(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Average_Setting(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Bridge_Resistance(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Data_Logging(PVOID DeviceHandle, int Counter);
            std::string Get_Destination_IP_Address(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Destination_MAC_Address(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Destination_Port_Number(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Direction(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Display_Page(PVOID DeviceHandle);
            std::string Get_Excitation(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Gain_Switch(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Hardware_Version(PVOID DeviceHandle);
            std::string Get_Internal_Register(PVOID DeviceHandle, int Register);
            std::string Get_Number_of_Active_Channels(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Number_of_Loading_Points(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Output_Type(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Polarity(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Pulses_Per_Rotation(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Rotation_Values(PVOID DeviceHandle);
            std::string Get_Sensitivity(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Sensor_Identification_Number(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Sensor_Sensitivity(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Shunt_Resistor(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Shunt_Value(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Source_IP_Address(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Source_MAC_Address(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Source_Port_Number(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Span_1_Potentiometer(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Span_2_Potentiometer(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Type_of_Board(PVOID DeviceHandle);
            std::string Get_Type_of_Calibration(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Voltage_Output(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Get_Zero_Potentiometer(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            
            std::string Read_Page_Register(PVOID DeviceHandle, BYTE PageNumber);
            std::string Read_TEDS_Register(PVOID DeviceHandle, BYTE HighAddress, BYTE LowAddress);
            std::string Reset_Angle(PVOID DeviceHandle, BYTE ChannelNumber = 0);
            std::string Write_Memory_Register(PVOID DeviceHandle, BYTE Address, BYTE Data);
            std::string Write_Channel_Register(PVOID DeviceHandle, BYTE ChannelNumber, BYTE Address, BYTE Data);
            std::string Write_EEPROM_Register(PVOID DeviceHandle, BYTE Address, BYTE HighByte, BYTE LowByte);
            std::string Write_TEDS_Register(PVOID DeviceHandle, BYTE HighAddress, BYTE LowAddress, BYTE Data);
            
            std::string Create_Back_Up(PVOID DeviceHandle, int SourcePageNumber, int DestinationPageNumber);
            std::string Restore_Back_Up(PVOID DeviceHandle, int DestinationPageNumber, int SourcePageNumber);
            
            std::string Set_Active_Page_Number(PVOID DeviceHandle, int ActivePageNumber, BYTE ChannelNumber = 0);
            std::string Set_Average_Setting(PVOID DeviceHandle, int AverageSetting, BYTE ChannelNumber = 0);
            std::string Set_Bridge_Resistance(PVOID DeviceHandle, int BridgeResistance, BYTE ChannelNumber = 0);
            std::string Set_Calibration_Code(PVOID DeviceHandle, int CalibrationCode, BYTE ChannelNumber = 0);
            std::string Set_Calibration_Day(PVOID DeviceHandle, int CalibrationDay, BYTE ChannelNumber = 0);
            std::string Set_Calibration_Mode(PVOID DeviceHandle, BYTE PotentiometerNumber, BYTE Adjustment, BYTE ChannelNumber = 0);
            std::string Set_Calibration_Month(PVOID DeviceHandle, int CalibrationMOnth, BYTE ChannelNumber = 0);
            std::string Set_Calibration_Register(PVOID DeviceHandle, BYTE Register, BYTE HighByte, BYTE LowByte, BYTE ChannelNumber = 0);
            std::string Set_Calibration_Year(PVOID DeviceHandle, int CalibrationYear, BYTE ChannelNumber = 0);
            std::string Set_CrossTalk(PVOID DeviceHandle, int CrossTalk, BYTE ChannelNumber = 0);
            std::string Set_Decimal_Point(PVOID DeviceHandle, int DecimalPoint, BYTE ChannelNumber = 0);
            std::string Set_Destination_IP_Address(PVOID DeviceHandle, BYTE Address1, BYTE Address2, BYTE Address3, BYTE Address4, BYTE ChannelNumber = 0);
            std::string Set_Destination_MAC_Address(PVOID DeviceHandle, BYTE Address1, BYTE Address2, BYTE Address3, BYTE Address4, BYTE Address5, BYTE Address6, BYTE ChannelNumber = 0);
            std::string Set_Destination_Port_Number(PVOID DeviceHandle, int PortNumber, BYTE ChannelNumber = 0);
            std::string Set_Digital_Components(PVOID DeviceHandle, BYTE SwitchNumber, BYTE HighByte, BYTE LowByte, BYTE ChannelNumber = 0);
            std::string Set_Direction(PVOID DeviceHandle, int Direction, BYTE ChannelNumber = 0);
            std::string Set_Load_of_Loading_Point(PVOID DeviceHandle, int LoadingPoint, int LoadValue, BYTE ChannelNumber = 0);
            std::string Set_Load_Switch(PVOID DeviceHandle, int SimulatedLoad, BYTE ChannelNumber = 0);
            std::string Set_Loading_Point(PVOID DeviceHandle, int LoadingPoint, BYTE ChannelNumber = 0);
            std::string Set_Number_of_Active_Channels(PVOID DeviceHandle, int NumberOfActiveChannels, BYTE ChannelNumber = 0);
            std::string Set_Number_of_Loading_Points(PVOID DeviceHandle, int NumberOfLoadingPoints, BYTE ChannelNumber = 0);
            std::string Set_Pulses_Per_Rotation(PVOID DeviceHandle, int PulsesPerRotation, BYTE ChannelNumber = 0);
            std::string Set_Sensitivity(PVOID DeviceHandle, int Sensitivity, BYTE ChannelNumber = 0);
            std::string Set_Sensor_Configuration(PVOID DeviceHandle, int SensorConfiguration, BYTE ChannleNumber = 0);
            std::string Set_Sensor_Identification_Number(PVOID DeviceHandle, int SerialNumber, BYTE ChannelNumber = 0);
            std::string Set_Shunt_Value(PVOID DeviceHandle, int ShuntValue, BYTE ChannelNumber = 0);
            std::string Set_Source_IP_Address(PVOID DeviceHandle, BYTE Address1, BYTE Address2, BYTE Address3, BYTE Address4, BYTE ChannelNumber = 0);
            std::string Set_Source_Port_Number(PVOID DeviceHandle, int PortNumber, BYTE ChannelNumber = 0);
            std::string Set_Type_of_Calibration(PVOID DeviceHandle, int TypeOfCalibration, BYTE ChannelNumber = 0);
            std::string Set_Unit_Code(PVOID DeviceHandle, int UnitCode, BYTE ChannelNumber = 0);
            std::string Set_Voltage_Output(PVOID DeviceHandle, int VoltageOutput, BYTE ChannelNumber = 0);
            std::string Set_Zero_Correction(PVOID DeviceHandle, int Point, int ZeroCorrectionValue, BYTE ChannelNumber = 0, int TypeOfCalibration = 0);
            std::string Fast_Data_Request(PVOID DeviceHandle, int DelimitedStyle, int DeviceNumber, std::string BoardType, std::string SamplingRate, std::string FirmwareVersion, BYTE ChannelNumber = 0);
            
            std::string Change_Battery_Enter(PVOID DeviceHandle);
            std::string Change_Display_Back(PVOID DeviceHandle);
            std::string Change_Hold_Down(PVOID DeviceHandle);
            std::string Change_Menu(PVOID DeviceHandle);
            std::string Change_Reset_Left(PVOID DeviceHandle);
            std::string Change_Shunt_Exit(PVOID DeviceHandle);
            std::string Change_Tare_Up(PVOID DeviceHandle);
            std::string Change_Unit_Right(PVOID DeviceHandle);
            int Get_Angle_Value();
            int Get_RPM_Value();
        private:
            
            int VirtualOffsetValue = 8386698;
            int VirtualFullscaleValue = 12530488;
            
            int VirtualOffsetLoad = 0;
            int VirtualFullscaleLoad = 2;
            
            int VirtualNumberOfLoadingPoints = 1;
            
            int VirtualNormalDataRequest = ((12530488 - 8386698) * 0.5) + 8386698;
            //std::string VirtualFastDataRequest = &"1,1," [ VirtualNormalDataRequest] + ",,,," + CurrentDate + "," & CurrentTime + ",";
            
            int VirtualPGASetting = 7;
            int VirtualSamplingRate = 0;
            
            int VirtualUnitCode = 34;
            int VirtualDirection = 0;
            int VirtualShuntValue = 2986902;
            int VirtualDecimalPoint = 0;
            
            int VirtualCalibrationCode = 0;
            int VirtualCalibrationDay = 21;
            int VirtualCalibrationMonth = 7;
            int VirtualCalibrationYear = 11;
            
            int VirtualPulsesPerRotation = 360;
            
            int VirtualVoltageOutput = 0;
            
            int VirtualAverageSetting = 0x22;
            
            int VirtualTypeOfBoard = 2;
            int VirtualHardwareVersion = 1;
            int VirtualFirmwareVersion = 4;
            int VirtualFirmwareYear = 11;
            int VirtualFirmwareMonth = 1;
            
            const int AdditionalPacketSize = 257;
            
            static const int MaximumNumberOfSamples = 64;
            
            //Packet Frame Data
            BYTE PacketNumber = 0;
            BYTE PacketSize;
            BYTE Channel;
            BYTE Command;
            BYTE EndOfPacket;
            
            //Packet Frame Sizes
            BYTE PacketNumberReceived;
            BYTE PacketSizeReceived;
            BYTE CommandReceived;
            BYTE MaximumPacketSize = 8;
            
            BYTE PacketSizeFragment;
            BYTE PacketSizeRemaining;
            
            //Data Placeholders
            BYTE Data1;
            BYTE Data2;
            BYTE Data3;
            BYTE Data4;
            BYTE Data5;
            BYTE Data6;
            BYTE Data7;
            BYTE Data8;
            
            //Read/Write Statuses
            std::string ReadStatus;
            std::string WriteStatus;
            std::string ReadFastStatus;
            
            //ADC Configuration Settings
            BYTE PGA_Setting;
            BYTE Sampling_Rate_Setting;
            
            //Version of Board Settings
            std::string Type_of_Board_Setting;
            std::string Hardware_Version_Setting;
            std::string Firmware_Version_Setting;
            std::string Firmware_Year_Setting;
            std::string Firmware_Month_Setting;
            
            std::string CrossTalk;
            std::string NumberOfActiveChannels;
            std::string TypeOfCalibration;
            std::string VoltageOutput;
            
            int TypeofBoardValue;
            std::string NumberOfLoadingPoints;
            std::string Sensitivity;
            std::string ActivePageNumber;
            std::string UnitCode;
            std::string BridgeResistance;
            std::string Direction;
            
            BYTE MemoryLocation1;
            BYTE MemoryLocation2;
            BYTE MemoryLocation3;
            BYTE MemoryLocation4;
            
            BYTE SignByte;
            BYTE HighByte;
            BYTE MiddleByte;
            BYTE LowByte;
            
            BYTE DestinationMACAddress1;
            BYTE DestinationMACAddress2;
            BYTE DestinationMACAddress3;
            BYTE DestinationMACAddress4;
            BYTE DestinationMACAddress5;
            BYTE DestinationMACAddress6;
            
            BYTE DestinationIPAddress1;
            BYTE DestinationIPAddress2;
            BYTE DestinationIPAddress3;
            BYTE DestinationIPAddress4;
            
            BYTE DestinationPortNumber1;
            BYTE DestinationPortNumber2;
            
            BYTE SourceMACAddress1;
            BYTE SourceMACAddress2;
            BYTE SourceMACAddress3;
            BYTE SourceMACAddress4;
            BYTE SourceMACAddress5;
            BYTE SourceMACAddress6;
            
            BYTE SourceIPAddress1;
            BYTE SourceIPAddress2;
            BYTE SourceIPAddress3;
            BYTE SourceIPAddress4;
            
            BYTE SourcePortNumber1;
            BYTE SourcePortNumber2;
            
            BYTE AdditionalPacket[257];
            
            int ArrayCounter;
            int FastDataLoggingCounter[16][4];
            int FastDataLoggingSampleNumber[16][4][MaximumNumberOfSamples + 1];
            int FastDataLoggingNumberOfSamples[16][4][MaximumNumberOfSamples + 1];
            int FastDataLoggingADCValue[16][4][MaximumNumberOfSamples + 1];
            std::string FastDataLoggingDateAndTime[16][4][MaximumNumberOfSamples + 1];
            std::string NumberFormat;
            std::string TimeFormat;
            std::string DateFormat;
            std::string CurrentDate;
            std::string CurrentTime;
            std::string DateAndTime;
            
            
            int AngleValue;
            int RPMValue;
            
            void NextPacketNumber();
            
            void GetErrorDescription(ULONG ErrorCode);
            
            void ReadPacket(int Timeout);
            void GetPacketReceived();
            
            void WritePacket(BOOL PageNumberIncluded);
            void GetPacketSent();
            
            void Get_Version_of_Board(PVOID DeviceHandle);
            
            std::string Get_ADC_Configuration(BYTE MemoryLocation, BYTE ChannelNumber);
            
            std::string Calculate_ADC_Value(BYTE Data1, BYTE Data2, BYTE Data3, BYTE Data4);
            std::string Calculate_IHH_ADC_Value(BYTE Data1, BYTE Data2, BYTE Data3);
            std::string Calculate_IHH_ADC_Value2(BYTE Data1, BYTE Data2, BYTE Data3);
            void LoadAdditionalPacket();
            void ReadAdditionalPacket();
            void GetDisplayPage(int StartIndex);
            void Delay2(double Input);
            void ReadFastPacket(double TimeOut);
            void ReadFastPacketFragment(double TimeOut);
            std::string Calculate_ADC_Value_Fast_Data_Request(BYTE Data1, BYTE Data2, BYTE Data3);
            std::string Calculate_ADC_Value_Fast_Data_Request2(BYTE Data1, BYTE Data2);
            BYTE PacketFragment[257];
        protected:
            
        };
    }
    
#pragma GCC visibility pop
    
#ifdef __cplusplus
}
#endif /* defined(__cplusplus) */

#endif /* defined(__FUTEK_USB_DLL__FUTEK_USB_DLL__) */
