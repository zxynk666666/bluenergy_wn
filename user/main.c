/**
  ******************************************************************************
  * @file RTC/Calendar/main.c
  * @author  MCD Application Team
  * @version  V3.0.0
  * @date  04/06/2009
  * @brief  Main program body
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

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define TxBufferSize   (sizeof(TxBuffer))                  //统计发送数组元素个数
#define RxBufferSize   (sizeof(TxBuffer))                  //接收数组元素个数与发送数组一致


#ifdef _GNUC_
#define PUTCHAR_PROTOTYPE int _io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO uint32_t TimingDelay;
extern uint8_t KeyID[8];
uint8_t TxBuffer[8];     //发送数组
uint8_t RxBuffer[RxBufferSize];                      //接收数组
uint8_t DataSizeOfTransfer = 5;           //发送数据量等于发送数组元素个数
uint8_t DataSizeOfReceiver = RxBufferSize;           //接收数据量等于接收数组元素个数
uint8_t ACK_Data[6] = {0x7e, 0x00, 0x00, 0x01, 0x00, 0x00};
ComDataStruct ComData;
extern unsigned char gBattery[6][4608], gLock[3][4608]; 
                            
FlashDataInfoData_16 FLSH_PicData = {0x08040000, 0x08065fff, 77823, 0};

TMR       TmrTbl[TMR_MAX_TMR];          /* Table of timers managed by this module             */

/* Private function prototypes -----------------------------------------------*/
void uDelay(uint16_t nTime);
void delay(__IO uint32_t nTime);

/* Private functions ---------------------------------------------------------*/

static  void  ConmmunctionTimer (void *arg)
{
    arg = arg;
    ComData.CheckSum = 0;
    ComData.ComState = START;
    ComData.LenNum = 0;
    ComData.DataCount = 0;
    ComData.Length = 0;
    ComData.LastSeq = 0;
    ComData.Seq = 0;
    ComData.RevOK = REV_NORMAL;
}


TmrTaskConfig(void)
{
    TmrInit();
    TmrCfgFnct(FALSE, 0, ConmmunctionTimer, (void *)0);                  /* Execute when Timer #0 times out          */
	TmrSetMST(0, 0, 10, 0);                                 /* Set timer #0 to 0 min., 10 sec. 0/10 sec. */
    TmrStart(0);
}

/*******************************************************************************
* Function Name  : Time_Adjust
* Description    : Adjusts time.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void Time_Reset(void)
{
    /* Wait until last write operation on RTC registers has finished */
    RTC_WaitForLastTask();
    /* Change the current time */
    RTC_SetCounter(0);
    /* Wait until last write operation on RTC registers has finished */
    RTC_WaitForLastTask();
}
  
DisplayInfo companyName = {0, 0, 6, "西安维纳测控"},
		 	oilHight = {0, 4, 5, "0.345"};

/**
  * @brief  Main program.
  * @param  None
  * @retval : None
  */
int main(void)
{
	uint8_t test[6];
	SystemResourcesInit(RCC_INIT 
                        | FLASH_INIT
                        | USART_INIT
                        | GPIO_INIT
                        | SYSTICK_INIT
                        | TIMER_INIT
                        | SPI_INIT);
	LCD_RST_RESET;
  	delay(2);
  	LCD_RST_SET;
  	delay(2);

	lcdInit();	
    TmrTaskConfig();
	cleanScreen();
	//fullScreenDisplay(niu);
	//displayOneLine16x16(companyName);	
	//displayOneLine24x32(oilHight);
	getNum(1099, 2, test);
	displayOneLine24x32_with_paras(0, 4, 5, test);
    while(1)
    {
    	//TmrTask(0);
	}
}

/*******************************************************************************
* Function Name  : PUTCHAR_PROTOTYPE
* Description    : 重定义C语言的fprint函数
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
PUTCHAR_PROTOTYPE

{
    /* Write a character to the USART */
    USART_SendData(USART1, (uint8_t)ch);

    /* Loop until the end of transmission */
    while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
        ;

    return ch;
}

/**
 * @brief  Inserts a delay time.
 * @param nTime: specifies the delay time length, in milliseconds.
 * @retval : None
 */
void delay(__IO uint32_t nTime)
{
    TimingDelay = nTime;

    while(TimingDelay != 0);
}

/**
 * @brief  Inserts a delay time.
 * @param nTime: specifies the delay time length, in milliseconds.
 * @retval : None
 */
void uDelay(uint16_t nTime)
{
    uint16_t TIMCounter = nTime;

    TIM_Cmd(TIM2, ENABLE);
    TIM_SetCounter(TIM2, TIMCounter);
    while (TIMCounter > 1)
    {
        TIMCounter = TIM_GetCounter(TIM2);
    }
    TIM_Cmd(TIM2, DISABLE);
}

/**
* @brief  Decrements the TimingDelay variable.
* @param  None
* @retval : None
*/
void TimingDelay_Decrement(void)
{
    if (TimingDelay != 0x00)
    {
        TimingDelay--;
    }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* Infinite loop */
    while (1)
    {}
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
