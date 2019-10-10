#include <stdio.h>		//printf()
#include <stdlib.h>		//exit()
#include <signal.h>     //signal()

#include "DEV_Config.h"
#include <time.h>
#include "TSL2591.h"

void  Handler(int signo)
{
    //System Exit
    printf("\r\nHandler:exit\r\n");
    DEV_ModuleExit();

    exit(0);
}

int main(void)
{
    // Exception handling:ctrl + c
    signal(SIGINT, Handler);
    DEV_ModuleInit();
    
    TSL2591_Init();
    // TSL2591_SET_InterruptThreshold(0xff00, 0x0010);
    while(1){
        printf("Lux = %d\r\n",TSL2591_Read_Lux());
        TSL2591_SET_LuxInterrupt(50,200);
        printf("Infrared light: %d\r\n", TSL2591_Read_Infrared());
        printf("Visible light: %d\r\n", TSL2591_Read_Visible());
        printf("Full spectrum (IR + visible) light: %d\r\n\r\n", TSL2591_Read_FullSpectrum());
    }
	//System Exit
	DEV_ModuleExit();
	return 0;
	
}

