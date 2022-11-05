#ifndef BSP_BUZZER_H_
#define BSP_BUZZER_H_

#include "stm32f10x.h"
#include "bsp_GeneralTim.h"

#define Set_41KHzBuzzer  GENERAL_TIM_Mode_Config(50,99,175);
#define Set_33KHzBuzzer GENERAL_TIM_Mode_Config(50,99,217);
#define Set_2KHzBuzzer GENERAL_TIM_Mode_Config(50,99,359);


#define Clr_Buzzer  GENERAL_TIM_Mode_Config(0,99,359);  // GPIO_ResetBits(GENERAL_TIM_CH3_PORT,GENERAL_TIM_CH3_PIN);

void Buzzer_Process(void);

#endif

