
#include "bsp_LED.h"

void LED_GPIO_Config(void)
{		 
    GPIO_InitTypeDef  GPIO_InitStruct;
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);	
	
    GPIO_InitStruct.GPIO_Pin = (LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN);	
   
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;  
   
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStruct);	 															      	
    GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStruct);	   															   	
    GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStruct);		
    GPIO_Init(LED4_GPIO_PORT, &GPIO_InitStruct);	
	
    LED_OFF;
}

