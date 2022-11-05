#include "stm32f10x.h"
#include "bsp_usart.h"
#include "digital_led.h"
#include "bsp_GeneralTim.h"
#include "bsp_SysTick.h"
#include "bsp_key.h"
#include  "bsp_LED.h"
#include "bsp_buzzer.h"
#include "TimerProcess.h"


uint8_t gc10mscount = 0; 
uint8_t gc250mscount = 0;
uint16_t gi1scount = 0;



/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
	/*系统滴答定时器初始化*/
  SysTick_Init();
	
	/*TIM4初始化*/
	GENERAL_TIM_Init();
	
	/*LED Init*/
	LED_GPIO_Config();
	
	/*按键初始化*/
	Key_GPIO_Config();
	
  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  USART_Config();
	
	/*数码管GPIO初始化*/
	Digital_Tube_Config();   
	
	
	#if 0     //暂时关闭数码管显示
		number_Display();  
	#endif
			
  while(1)
	{	
		  /*10ms进一次*/
			if(gc10mscount >= 10)
			{
				gc10mscount = 0;
				gc250mscount++;				
				
				/*key*/
				Key_Process();
				
				/*250ms运行一次*/
			  if(gc250mscount >= 25)
				{
					gc250mscount = 0;
					#if 0
						Time_Process();
					#endif
				}
				
			}
	}
}
/*********************************************END OF FILE**********************/
