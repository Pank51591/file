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
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{	
	/*ϵͳ�δ�ʱ����ʼ��*/
  SysTick_Init();
	
	/*TIM4��ʼ��*/
	GENERAL_TIM_Init();
	
	/*LED Init*/
	LED_GPIO_Config();
	
	/*������ʼ��*/
	Key_GPIO_Config();
	
  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  USART_Config();
	
	/*�����GPIO��ʼ��*/
	Digital_Tube_Config();   
	
	
	#if 0     //��ʱ�ر��������ʾ
		number_Display();  
	#endif
			
  while(1)
	{	
		  /*10ms��һ��*/
			if(gc10mscount >= 10)
			{
				gc10mscount = 0;
				gc250mscount++;				
				
				/*key*/
				Key_Process();
				
				/*250ms����һ��*/
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
