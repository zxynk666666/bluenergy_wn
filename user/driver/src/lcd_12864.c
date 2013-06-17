/**
  ******************************************************************************
  * @file lcd_12864.c 
  * @author  MCD Application Team
  * @version  V3.0.0
  * @date  04/06/2009
  * @brief  This file provides a set of functions needed to drive the 
  *         IS61WV51216BLL SRAM memory mounted on STM3210E-EVAL board.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2009 STMicroelectronics</center></h2>
  */

/* Includes ------------------------------------------------------------------*/
#include "include.h"
#include "GB1616.h"
#include "GB2432.h"

/* Private define ------------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private functions ---------------------------------------------------------*/
uint8_t *getGB1616(uint8_t code[2], const typFNT_GB1616 GB_16[]);
uint8_t *getGB2432(uint8_t code, const typFNT_GB2432 GB_2432[]);
void setBaseXY(uint8_t startX, uint8_t startY);
void copy(uint8_t *src, uint8_t *dst, uint8_t times, uint8_t offset);




/* Private function prototypes -----------------------------------------------*/
void lcdInit()
{
	lcdWriteCom(DISPLAY_ON);			//Display on
  	lcdWriteCom(RAM_START_ADDR);		//RAM起始地址
  	lcdWriteCom(ADC_NORMAL);			//左右反转 正常    
  	lcdWriteCom(DISPLAY_NORMAL);		//反白效果 正常 
  	lcdWriteCom(DISPLAY_ALL_POINT_OFF);	//全屏显示 关
  	lcdWriteCom(LCD_BIAS_SET_9);		//LCD 的偏压比 1/9  
  	lcdWriteCom(OUTPUT_MODE_REVERSE);	//上下反转 反向
  	lcdWriteCom(INNER_POWER_ON);		//开关内部电路的电源 
  	lcdWriteCom(V0);					//对比度(0X24 是比较合适)
  	lcdWriteCom(LIGHT_SET);				//亮度设定入口 
  	lcdWriteCom(LIGHT_VALUE);			//亮度值 
  	lcdWriteCom(RAM_START_ADDR);		//RAM起始地址
}

void lcdWriteCom(uint8_t command) 
{  
	LCD_CS_RESET;  						//片选拉低，选中LCD 
	LCD_A0_RESET;    	//设置为写命令    
	SPI_I2S_SendData(SPI1, command);	//SPI写数据   
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) != RESET);	//等待发送完�
	LCD_CS_SET;     //片选拉高，释放LCD  �   
}

void lcdWriteData(uint8_t data)
{ 
	LCD_CS_RESET;  						//片选拉低，选中LCD 
	LCD_A0_SET;   //设置为写数据    
	SPI_I2S_SendData(SPI1, data); //SPI写数据   
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) != RESET); //等待发送完成  
	LCD_CS_SET;     //片选拉高，释放LCD  
}

void cleanScreen()
{
	uint8_t page, i;

	for(page = 0; page < 8; page++)
	{
		lcdWriteCom(BASE_PAGE_ADDR + page);
		lcdWriteCom(COLUMN_SET_H);		//列高4位
		lcdWriteCom(COLUMN_SET_L);		//列低4位（A3-A0）
		for(i = 0; i< 128; i++) 
		{
	  		lcdWriteData(0x00);
	 	}
	}
}

void fullScreenDisplay(uint8_t *pic)
{
	uint8_t page, i;

	for(page = 0; page < 8; page++)
	{
		lcdWriteCom(BASE_PAGE_ADDR + page);
		lcdWriteCom(COLUMN_SET_H);		//列高4位
		lcdWriteCom(COLUMN_SET_L);		//列低4位（A3-A0）
		for(i = 0; i< 128; i++) 
		{
	  		lcdWriteData(*pic++);
	 	}
	}

}

void displayOne16x16(DisplayInfo displayInfo)
{
	uint8_t *gb1616, i;	
	uint8_t page;
	uint8_t gb[2][16];

	gb1616 = getGB1616(displayInfo.data, tGB_16);
	copy(gb1616, gb[0], 2, GB1616_SIZE);

	for(page = displayInfo.y; page < displayInfo.y + 2; page++)
	{
		setBaseXY(displayInfo.x, displayInfo.y);
		lcdWriteCom(BASE_PAGE_ADDR + page);
		for(i = 0; i< 16; i++) 
		{
	  		lcdWriteData(gb[page][i]);
	 	}
	}
}

void displayOneLine16x16(DisplayInfo displayInfo)
{
	uint8_t *gb1616, i, k;	
	uint8_t page;
	uint8_t gb[2][16];
	
	for(page = 0; page < 2; page++)
	{		
		setBaseXY(displayInfo.x, displayInfo.y);
		lcdWriteCom(BASE_PAGE_ADDR + page + displayInfo.y);
		for(i = 0; i < displayInfo.length; i++)
		{
			gb1616 = getGB1616(displayInfo.data + i * 2, tGB_16);
			copy(gb1616, gb[0], 2, GB1616_SIZE);
			for(k = 0; k < 16; k++)
			{
				lcdWriteData(gb[page][k]);
			}			
		}
	}
}

void displayOneLine24x32(DisplayInfo displayInfo)
{
	uint8_t *gb2432, i, k;	
	uint8_t page;
	uint8_t gb[4][24];
	
	for(page = 0; page < 4; page++)
	{		
		setBaseXY(displayInfo.x, displayInfo.y);
		lcdWriteCom(BASE_PAGE_ADDR + page + displayInfo.y);
		for(i = 0; i < displayInfo.length; i++)
		{
			gb2432 = getGB2432(displayInfo.data[i], tGB_24);
			copy(gb2432, gb[0], 4, GB2432_SIZE);
			for(k = 0; k < GB2432_SIZE / 4; k++)
			{
				lcdWriteData(gb[page][k]);
			}			
		}
	}
}

/* Private func */

void setBaseXY(uint8_t startX, uint8_t startY)
{
	//lcdWriteCom(RAM_START_ADDR + 63 - startY);		//RAM起始地址
	lcdWriteCom(COLUMN_SET_H + ((startX & 0xf0) >> 4));	//列高4位
	lcdWriteCom(COLUMN_SET_L + (startX & 0x0f));		//列低4位（A3-A0）
}

void copy(uint8_t *src, uint8_t *dst, uint8_t times, uint8_t size)
{
	uint8_t i, offset = size / times;
	for(i = 0; i < times; i++)
	{
		memcpy(dst + i * offset, src + i * offset, offset);
	}
}

uint8_t *getGB1616(uint8_t code[2], const typFNT_GB1616 GB_16[])
{
	uint8_t gb16[GB1616_SIZE], k;
	for (k = 0; k < GB1616_MAXSIZE; k++) //64标示自建汉字库中的个数，循环查询内码
    {
        if ((GB_16[k].Index[0] == code[0]) && (GB_16[k].Index[1] == code[1]))
        {
            memcpy(gb16, GB_16[k].Msk, GB1616_SIZE);			
		}
    }
	return gb16;							  	
}

uint8_t *getGB2432(uint8_t code, const typFNT_GB2432 GB_2432[])
{
	uint8_t gb2432[GB2432_SIZE], k;
	
	for (k = 0; k < GB2432_MAXSIZE; k++) //64标示自建汉字库中的个数，循环查询内码
    {
        if (GB_2432[k].Index == code)
        {
            memcpy(gb2432, GB_2432[k].Msk, GB2432_SIZE);			
		}
    }
	return gb2432;							  	
}

void numToString()
{
	
}
