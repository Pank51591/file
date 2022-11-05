#ifndef BSP_KEY_H_
#define BSP_KEY_H_

/*key GPIO*/
#include "stm32f10x.h"


#define    KEY1_GPIO_CLK     RCC_APB2Periph_GPIOA
#define    KEY1_GPIO_PORT    GPIOA			   
#define    KEY1_GPIO_PIN		 GPIO_Pin_0

#define    KEY2_GPIO_CLK     RCC_APB2Periph_GPIOC
#define    KEY2_GPIO_PORT    GPIOA		   
#define    KEY2_GPIO_PIN		  GPIO_Pin_5

#define Key1_Read   GPIO_ReadInputDataBit(KEY1_GPIO_PORT,KEY1_GPIO_PIN)
#define Key2_Read   GPIO_ReadInputDataBit(KEY2_GPIO_PORT,KEY2_GPIO_PIN)


#if 0
#define KEY_ON	0      /*Low level detected*/
#define KEY_OFF	1

uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);

#else
	/*Key Value*/
	#define  Key1   0x01
	#define  Key2   0x02
	#define  Keycom1   0x08
	#define  Key1_3s   0x10
	#define  Key2_3s   0x20

#endif

void Key_GPIO_Config(void);
uint8_t Key_Check(void);
void Key_Process(void);





#endif
