/*****************************************************************************
* | File      	:   Readme_CN.txt
* | Author      :   Waveshare team
* | Function    :   Help with use
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2019-09-24
* | Info        :   在这里提供一个中文版本的使用文档，以便你的快速使用
******************************************************************************/
这个文件是帮助您使用本例程。
在这里简略的描述本工程的使用：

1.基本信息：
本例程均在Raspberry Pi 3B+ 和 Jetson Nano 上进行了验证;
本例程使用TSL2591X_Light_Sensor模块进行了验证，你可以在工程的examples\中查看对应的测试例程;

2.管脚连接：
管脚连接你可以在\lib\Config\DEV_Config.c中查看，这里也再重述一次：
TSL25911    =>    Jetson Nano/RPI(BCM)
VCC         ->    3.3V
GND         ->    GND
SDA         ->    SDA
SCL         ->    SCL
INT         ->    4


3.安装库：
Raspberry Pi
    安装BCM2835
        1.	wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.60.tar.gz
        2.	tar zxvf bcm2835-1.60.tar.gz 
        3.	cd bcm2835-1.60/
        4.	sudo ./configure
        5.	sudo make
        6.	sudo make check
        7.	sudo make install
        8.	# 更多的可以参考官网：http://www.airspayce.com/mikem/bcm2835/
    安装wiringPi
        1.	sudo apt-get install wiringpi
        2.	#对于树莓派4B可能需要进行升级：
        3.	cd /tmp
        4.	wget https://project-downloads.drogon.net/wiringpi-latest.deb
        5.	sudo dpkg -i wiringpi-latest.deb
        6.	gpio -v
        7.	# 运行gpio -v会出现2.52版本，如果没有出现说明安装出错
        
Jetson Nano
    不需要安装任何库，但是只支持USE_DEV_LIB

在Makefile文件中有
    # USELIB = USE_BCM2835_LIB
    # USELIB = USE_WIRINGPI_LIB
    USELIB = USE_DEV_LIB
Raspberry Pi 支持BCM2835、WIRINGPI和DEV_LIB
Jetson Nano  支持DEV_LIB

4.基本使用：
测试程序在examples\目录中查看
Run:
    make clean 
    make
    sudo ./main



