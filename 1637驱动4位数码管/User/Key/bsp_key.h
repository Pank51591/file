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

struct Flag_Class
{
	uint8_t Key1Down;
	uint8_t Key2Down;
	uint8_t Key1_2Down;
	uint8_t KeyReturn;

}MyFlag;

#define Key1Dowm_Flag       MyFlag.Key1Down
#define Set_Key1Down_Flag   MyFlag.Key1Down = 1;
#define Clr_Key1Down_Flag   MyFlag.Key1Down = 0;

#define Key2Dowm_Flag       MyFlag.Key2Down
#define Set_Key2Down_Flag   MyFlag.Key2Down = 1;
#define Clr_Key2Down_Flag   MyFlag.Key2Down = 0;

#define Key1_2Dowm_Flag       MyFlag.Key1_2Down
#define Set_Key1_2Down_Flag   MyFlag.Key1_2Down = 1;
#define Clr_Key1_2Down_Flag   MyFlag.Key1_2Down = 0;

#define KeyReturn_Flag          MyFlag.KeyReturn
#define Set_KeyReturn_Flag      MyFlag.KeyReturn = 1;
#define Clr_KeyReturn_flag      MyFlag.KeyReturn = 0;

#

#if 0
#define KEY_ON	0      /*Low level detected*/
#define KEY_OFF	1

uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);

#else
	/*Key Value*/
	#define  Key1   0x01
	#define  Key2   0x02
	#define  Keycom1   0x03
	#define  Key1_3s   0x10
	#define  Key2_3s   0x20

#endif

void Key_GPIO_Config(void);
uint8_t Key_Check(void);






#endif
