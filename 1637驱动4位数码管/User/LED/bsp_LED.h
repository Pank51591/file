#ifndef BSP_LED_H_
#define BSP_LED_H_

#include "stm32f10x.h"

#define LED1_PIN                  GPIO_Pin_1                
#define LED1_GPIO_PORT            GPIOA                     

#define LED2_PIN                  GPIO_Pin_2                
#define LED2_GPIO_PORT            GPIOA                     

#define LED3_PIN                  GPIO_Pin_3                
#define LED3_GPIO_PORT            GPIOA                     

#define LED4_PIN                  GPIO_Pin_4                
#define LED4_GPIO_PORT            GPIOA                     


#define	digitalHi(p,i)			 {p->BSRR=i;}	
#define digitalLo(p,i)			 {p->BSRR=(uint32_t)i << 16;}		
#define digitalToggle(p,i)		{p->ODR ^=i;}	

#define LED1_TOGGLE		digitalToggle(LED1_GPIO_PORT,LED1_PIN)
#define LED1_ON		digitalHi(LED1_GPIO_PORT,LED1_PIN)
#define LED1_OFF			digitalLo(LED1_GPIO_PORT,LED1_PIN)

#define LED2_TOGGLE		digitalToggle(LED2_GPIO_PORT,LED2_PIN)
#define LED2_ON		digitalHi(LED2_GPIO_PORT,LED2_PIN)
#define LED2_OFF			digitalLo(LED2_GPIO_PORT,LED2_PIN)

#define LED3_TOGGLE		digitalToggle(LED3_GPIO_PORT,LED3_PIN)
#define LED3_ON		digitalHi(LED3_GPIO_PORT,LED3_PIN)
#define LED3_OFF			digitalLo(LED3_GPIO_PORT,LED3_PIN)

#define LED4_TOGGLE		digitalToggle(LED4_GPIO_PORT,LED4_PIN)
#define LED4_ON		digitalHi(LED4_GPIO_PORT,LED4_PIN)
#define LED4_OFF			digitalLo(LED4_GPIO_PORT,LED4_PIN)

#define LED_OFF	  LED1_OFF;LED2_OFF;LED3_OFF;LED4_OFF

void LED_GPIO_Config(void);


#endif
