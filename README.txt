These instructions are for enabling the FUTEK USB devices in Ubuntu 14.04 and 16.04.  The FUTEK USB library has been tested with Ubuntu 14.04 and 16.04 for i386 and x86_64.

Install the FTDI D2XX Drivers
-----------------------------
1.  Download the FTDI D2XX Drivers from the FTDI website here:  http://www.ftdichip.com/Drivers/D2XX.htm

2.  Inside the downloaded folder, follow the instructions in the README file to install the drivers.

3.  Be sure to test that the drivers are working by following the examples in the README file.

Installing the FUTEK USB Library
---------------------------
1.  Unpack the downloaded archive:
	tar -xvzf FUTEK_USB-x86_64.tar.gz

2.  Navigate to FUTEK_USB-x86_64 folder:
	cd FUTEK_USB-x86_64

3.  Promote to super user for installation permissions:
	sudo su

4.  Copy the library to /usr/local/lib:
	cp libFUTEK_USB-x86_64.so.1.0.0 /usr/local/lib

5.  Allow non-root access to library:
	chmod 0755 /usr/local/lib/libFUTEK_USB-x86_64.so.1.0.0

6.  Create symbolic link to library:
	ln -sf /usr/local/lib/libFUTEK_USB-x86_64.so.1.0.0 /usr/local/lib/libFUTEK_USB-x86_64.so

7.  Update shared library cache:
	ldconfig

8.  Copy header files to /usr/local/include:
	cp FUTEK_USB_DLL.h /usr/local/include


Running Examples
----------------
1.  The examples provided assume that the FTDI header files, ftd2xx.h and WinTypes.h, are located in /usr/local/includes. Please 	navigate to the extracted release folder from the FTDI download and run the following commands:

	sudo cp ftd2xx.h /usr/local/include
	sudo cp WinTypes.h /usr/local/include
	
3.  Navigate to examples folder FUTEK_USB-x86_64/examples/GetDeviceInformation

4.  Build the example:
	make

5.  Run the program:
	sudo ./main

	If you receive errors for all of the outputs, check to ensure that the module ftdi_sio is removed. If it is still showing 		errors, then try removing the module usbserial.

		sudo lsmod | grep ftdi_sio 
		sudo rmmod ftdi_sio
		sudo rmmod usbserial

	If you wish to keep the ftdi_sio module running, please read the instructions below on how to create a udev rule to unbind 		your device from the ftdi_sio module.

6.  Navigate to FUTEK_USB-x86_64/examples/GetReading

7.  Build the example:
	make

8.  Run the program:
	sudo ./main

Creating udev rule to unbind device from ftdi_sio module when enabled.
--------------------------------------------------------------

As seen when testing the D2XX drivers and running the FUTEK examples, the module ftdi_sio needs to be removed before successful communication can take place with device.  To have a device automatically unbind from this module instead of manually removing the module each time a device is enabled, a udev rule needs to be created.

1.  In /etc/udev/rules.d/ create a file named 99-FUTEKUSB.rules and add the following line:

SUBSYSTEM=="usb", ATTRS{idVendor}=="0403", ATTRS{idProduct}=="6001", ATTRS{serial}=="DEVICE_SERIAL_NUMBER", RUN+="/bin/sh -c 'echo -n $kernel > /sys/bus/usb/drivers/ftdi_sio/unbind'"

2.  Reinsert the device to enable the rule. 

3.  Navigate back to the examples in FUTEK_USB-x86_64/examples.

4.  Run the programs again.

5.  The programs can now run without removing the ftdi_sio module.

Note:  DEVICE_SERIAL_NUMBER is the serial number of the device.  Find this number on the physical device and insert it in the line. The line inserted into the .rules file is a single line with no line breaks.  Do no put this rule on two separate lines in the file as it will not work.


Accessing FTDI device without root permissions.
-----------------------------------------------

A udev rule needs to be created if a device needs to be communicated with and a user does not have root permissions.  This rule will point the device to a group and allow that group to communicate with it.

1.  In /etc/udev/rules.d/ create a file called 10-FUTEKUSB.rules and add the following line:

SUBSYSTEM=="usb", ATTRS{idVendor}=="0403", ATTRS{idProduct}=="6001", ATTRS{serial}=="DEVICE_SERIAL_NUMBER",GROUP="GROUP_NAME", MODE="0666"

2.  Reinsert the device to enable the rule. 

3.  Navigate back to the examples in FUTEK_USB-x86_64/examples.

4.  Run the programs again without sudo prefix.

Note:  DEVICE_SERIAL_NUMBER is the serial number of the device.  Find this number on the physical device and insert it in the line. The GROUP_NAME is the name of the group that will have access to the device.  The line inserted into the .rules file is a single line with no line breaks.  Do no put this rule on two separate lines in the file as it will not work.
 
