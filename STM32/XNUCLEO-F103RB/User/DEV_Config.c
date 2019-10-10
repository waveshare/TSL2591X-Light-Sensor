/*****************************************************************************
* | File      	:   DEV_Config.c
* | Author      :   Waveshare team
* | Function    :   Hardware underlying interface
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2019-09-17
* | Info        :   Basic version
*
******************************************************************************/
#include "DEV_Config.h"

uint8_t DEV_SPI_Device = 0, DEV_I2C_Device = 0;
uint8_t I2C_ADDR;
/******************************************************************************
function:	GPIO Function initialization and transfer
parameter:
Info:
******************************************************************************/
void DEV_GPIO_Mode(GPIO_TypeDef* GPIO_Port, UWORD Pin, UWORD mode)
{
    /*
        0:  INPT   
        1:  OUTP
    */
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = Pin;
	if(mode == GPIO_MODE_INPUT || mode == 0){
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	}else if(mode == GPIO_MODE_OUTPUT_PP || mode == 1){
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	}else{
		GPIO_InitStruct.Mode = mode;
	}
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIO_Port, &GPIO_InitStruct);
}


/**
 * delay x ms
**/
void DEV_Delay_ms(UDOUBLE xms)
{
	HAL_Delay(xms);
}


void GPIO_Config(void)
{
    //DEV_GPIO_Mode(INT_PIN, 0);
}

/******************************************************************************
function:	SPI Function initialization and transfer
parameter:
Info:
******************************************************************************/
void DEV_SPI_Init()
{
#if DEV_SPI 
	DEV_SPI_Device = 1;
#endif
}

void DEV_SPI_WriteByte(uint8_t Value)
{
#if DEV_SPI 
	
#endif
}

void DEV_SPI_Write_nByte(uint8_t *pData, uint32_t Len)
{
#if DEV_SPI 
	
#endif
}
/******************************************************************************
function:	I2C Function initialization and transfer
parameter:
Info:
******************************************************************************/
void DEV_I2C_Init(uint8_t Add)
{
#if DEV_I2C 
	DEV_I2C_Device = 1;
	I2C_ADDR =  Add;
#endif
}

void I2C_Write_Byte(uint8_t Cmd, uint8_t value)
{
#if DEV_I2C 
	UBYTE Buf[1] = {0};
	Buf[0] = value;
	HAL_I2C_Mem_Write(&hi2c1, I2C_ADDR, Cmd, I2C_MEMADD_SIZE_8BIT, Buf, 1, 0x20);
#endif
}

int I2C_Read_Byte(uint8_t Cmd)
{
#if DEV_I2C 
	UBYTE Buf[1]={0};
	HAL_I2C_Mem_Read(&hi2c1, I2C_ADDR+1, Cmd, I2C_MEMADD_SIZE_8BIT, Buf, 1, 0x20);
	return Buf[0];
#endif
}

int I2C_Read_Word(uint8_t Cmd)
{
#if DEV_I2C 
	UBYTE Buf[2]={0, 0};
	HAL_I2C_Mem_Read(&hi2c1, I2C_ADDR+1, Cmd, I2C_MEMADD_SIZE_8BIT, Buf, 2, 0x20);
	return ((Buf[1] << 8) | (Buf[0] & 0xff));
#endif
}
/******************************************************************************
function:	Module Initialize, the library and initialize the pins, SPI protocol
parameter:
Info:
******************************************************************************/
UBYTE DEV_ModuleInit(void)
{
		GPIO_Config();
    DEV_I2C_Init(0x29<<1);
    return 0;
}

/******************************************************************************
function:	Module exits, closes SPI and BCM2835 library
parameter:
Info:
******************************************************************************/
void DEV_ModuleExit(void)
{
	
}

