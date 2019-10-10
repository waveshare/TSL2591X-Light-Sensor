/*****************************************************************************
* | File      	:   Readme_CN.txt
* | Author      :   Waveshare team
* | Function    :   Help with use
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2019-09-24
* | Info        :   Here is an English version of the documentation for your quick use.
******************************************************************************/
This file is to help you use this Demo.
A brief description of the use of this project is here:

1. Basic information:
This Demo has been verified on the Raspberry Pi 3B+ and Jetson Nano;
This Demo has been verified using the e-paper Driver HAT module. 
You can view the corresponding test routines in the examples\ of the project;

2. Pin connection:
Pin connections can be viewed in \lib\waveshare_TSL2591\TSL2591.py and will be repeated here:
TSL25911    =>    Jetson Nano/RPI(BCM)
VCC         ->    3.3V
GND         ->    GND
SDA         ->    SDA
SCL         ->    SCL
INT         ->    4

3.Installation library
    sudo apt-get update
    sudo apt-get install python-pip
    sudo apt-get install python-pil
    sudo pip install RPi.GPIO
    sudo pip install smbus

or
    sudo apt-get update
    sudo apt-get install python3-pip
    sudo apt-get install python3-pil
    sudo pip3 install RPi.GPIO
    sudo pip3 install smbus

4. Basic use:
Test the program in the examples\ directory:
python2
    sudo python main.py

python3
    sudo python3 main.py