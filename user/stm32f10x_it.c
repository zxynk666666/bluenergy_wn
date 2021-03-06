/**
  ******************************************************************************
  * @file RTC/Calendar/stm32f10x_it.c
  * @author  MCD Application Team
  * @version  V3.0.0
  * @date  04/06/2009
  * @brief  Main Interrupt Service Routines.
  *         This file provides template for all exceptions handler and
  *         peripherals interrupt service routine.
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
#include "Menu.h"

unsigned int cal;
extern Menu menus[];
extern uint8_t windowPointer, currentMenu;

COM com2;

/** @addtogroup StdPeriph_Examples
  * @{
  */

/** @addtogroup RTC_Calendar
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern __IO uint32_t TimeDisplay;

extern unsigned char  TxBuffer[];             //发送数组定义成全局变量
extern unsigned char  RxBuffer[];             //接收数组定义成全局变量
extern unsigned char  DataSizeOfTransfer;     //发送数据量定义成全局变量
extern unsigned char  DataSizeOfReceiver;     //接收数据量定义成全局变量
unsigned char  ReceiveComplete = 0;           //接收完成标志位
unsigned char  TxCounter = 0;                 //发送计数器
unsigned char  RxCounter = 0;                 //接收计数器

extern ComDataStruct ComData;
extern uint8_t ACK_Data[];
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval : None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval : None
  */
void HardFault_Handler(void)
{
    /* Go to infinite loop when Hard Fault exception occurs */
    while (1)
    {}
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval : None
  */
void MemManage_Handler(void)
{
    /* Go to infinite loop when Memory Manage exception occurs */
    while (1)
    {}
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval : None
  */
void BusFault_Handler(void)
{
    /* Go to infinite loop when Bus Fault exception occurs */
    while (1)
    {}
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval : None
  */
void UsageFault_Handler(void)
{
    /* Go to infinite loop when Usage Fault exception occurs */
    while (1)
    {}
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval : None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval : None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles PendSV_Handler exception.
  * @param  None
  * @retval : None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval : None
  */
void SysTick_Handler(void)
{
    TmrDiDa();
	TimingDelay_Decrement();
}

/******************************************************************************/
/*            STM32F10x Peripherals Interrupt Handlers                        */
/******************************************************************************/

/**
  * @brief  This function handles RTC global interrupt request.
  * @param  None
  * @retval : None
  */
void RTC_IRQHandler(void)
{
    if (RTC_GetITStatus(RTC_IT_SEC) != RESET)
    {
        /* Clear the RTC Second interrupt */
        RTC_ClearITPendingBit(RTC_IT_SEC);
        /* Toggle GPIO_LED pin 6 each 1s */
        GPIO_WriteBit(GPIO_LED, GPIO_Pin_6, (BitAction)(1 - GPIO_ReadOutputDataBit(GPIO_LED, GPIO_Pin_6)));
        /* Enable time update */
        /* Wait until last write operation on RTC registers has finished */
        RTC_WaitForLastTask();
        /* Reset RTC Counter when Time is 23:59:59 */
        if (RTC_GetCounter() == 0x00015180)
        {
            RTC_SetCounter(0x0);
            /* Wait until last write operation on RTC registers has finished */
            RTC_WaitForLastTask();
        }
    }
}

/******************************************************************************
                            接口设备中断处理函数
  当要添加中断处理函数时，对应的函数名位于启动文件startup_stm32f10x_hd.s
                       的中断向量表Vector Table
******************************************************************************/
void USART2_IRQHandler(void)                                        //串口1中断处理函数
{
	// 串口接收
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
    {		
		/* Clear the USART1 Receive interrupt */
	  	USART_ClearITPendingBit(USART2, USART_IT_RXNE);
	  	
	  	/* Read one byte from the receive data register */
	  	com2.recBuf[com2.RecCnt++] = USART_ReceiveData(USART2);
	  	//com2.RecTimeOutCnt = 0;					/*清超时计数器*/
	  	//com2.RecFstFlg = 1;						/*接收到起始字符时，开始计数超时时间*/
	  	TmrCfg(USART_REC_TIMEOUT_TIMER, ModbusRecTimeoutTimerHanler, (void *)0, 0, 0, (uint8_t)GetData(MT_ADDR), FALSE, TRUE);
    }
	// 串口发送
    if(USART_GetITStatus(USART2, USART_IT_TXE) != RESET)
    {
  
	  	USART_ClearFlag(USART2, USART_FLAG_TC);
	  	if(com2.TrCnt >= com2.TrLen)
	  	{
	  		com2.TrCnt = 0;
	  		com2.TrOk = 1;
			com2.TrLen = 0;
	  		/* Disable the USART1 Transmit interrupt */
	  	  	USART_ITConfig(USART2, USART_IT_TXE, DISABLE);
			uDelay(1);
			RS485_RW_Select(RS485_READ);
	  	}
	  	else
	   	{
	  		
	  		/* Write one byte to the transmit data register */
	  		usartSendData(com2.trBuf[com2.TrCnt++]); //发送下一个字
	  	}
  
    }
}
/******************************************************************************
                            接口设备中断处理函数                           
  当要添加中断处理函数时，对应的函数名位于启动文件startup_stm32f10x_hd.s
                       的中断向量表Vector Table                               
******************************************************************************/
void EXTI15_10_IRQHandler(void)										  //外部中断0号线中断处理函数
{																  
  
  
  if(EXTI_GetITStatus(EXTI_Line13) != RESET)						  //检测是否发生了0号线中断
  {
    EXTI_ClearITPendingBit(EXTI_Line13);							  //清除0号线中断标志位

	for(cal=0;cal<100000;cal++);								  //简单延时，按键消抖
	if(!GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13))				  //检测是否是S1按下
	{
		TmrReset(MENU_TIMEOUT_TIMER);
		menus[currentMenu].optFun(UP);
	}      	
  } else if(EXTI_GetITStatus(EXTI_Line14) != RESET)						  //检测是否发生了0号线中断
  {
    EXTI_ClearITPendingBit(EXTI_Line14);							  //清除0号线中断标志位

	for(cal=0;cal<100000;cal++);								  //简单延时，按键消抖
	if(!GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14))				  //检测是否是S1按下
	{
		TmrReset(MENU_TIMEOUT_TIMER);
		menus[currentMenu].optFun(DOWN);
	}      	
  } else if(EXTI_GetITStatus(EXTI_Line15) != RESET)						  //检测是否发生了0号线中断
  {
    EXTI_ClearITPendingBit(EXTI_Line15);							  //清除0号线中断标志位

	for(cal=0;cal<100000;cal++);								  //简单延时，按键消抖
	if(!GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_15))				  //检测是否是S1按下
	{		
		TmrReset(MENU_TIMEOUT_TIMER);
		menus[currentMenu].optFun(ENTER);
	}      	
  }
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval : None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
