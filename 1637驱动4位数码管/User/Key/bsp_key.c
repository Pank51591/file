#include "bsp_key.h"

uint8_t gcKeyState = 0;
uint8_t gcKeyCount = 0;
uint8_t gcKeyValue = 0;


void Key_GPIO_Config (void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK|KEY2_GPIO_CLK,ENABLE); 
	
	GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = KEY2_GPIO_PIN; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;              //¸¡¿ÕÊäÈë
	GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure);	
}


#if 0
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON )  
	{	 
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON);   
		return 	KEY_ON;	 
	}
	else
		return KEY_OFF;
}
#endif

void Get_Key_Value(void)
{
	if(Key1_Read == 0)
	{
		Set_Key1Down_Flag;
		gcKeyValue = Key1;	
	}
	else
		Clr_Key1Down_Flag;
	
	if (Key2_Read == 0)
	{
		Set_Key2Down_Flag;
		gcKeyValue = Key2;
	}
	else
		Clr_Key2Down_Flag;
	
	if (Key1_Read == 0 && Key2_Read == 0)
	{
		Set_Key1_2Down_Flag;
		gcKeyValue = Keycom1;
	}
	else
	 Clr_Key1_2Down_Flag;
	

	
}



uint8_t Key_Check(void)
{
	switch(gcKeyState)
	{
		/**/
		case 0:
		{
			if(Key1_Read == 0 || Key2_Read == 0)
			{
				  gcKeyCount++;
				  if(gcKeyCount >3)      //
					{
						gcKeyCount = 0;
						gcKeyState = 1;
					}
					else
					{
						gcKeyState = 0;
					}
			}
		}
		break;
		/**/
		case 1:
		{
			Set_KeyReturn_Flag;
			Get_Key_Value();
			gcKeyState = 2;
		}
		break;
		/**/
		case 2:
		{
			/* Key Up */
			if(Key1_Read == 1 || Key2_Read == 1)
			{
				gcKeyCount++;
				if(gcKeyCount >= 3)
				{
					gcKeyCount = 0;
					gcKeyState = 0;
				}
			}
			else    //long down
			{
				
			}
			
		}
		break;
		default:
			gcKeyState = 0;
			break;
			
	}
}




