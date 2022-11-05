#include "bsp_key.h"
#include "MyFlag.h"
#include "bsp_LED.h"

uint8_t gcKeyState = 0;
uint8_t gcKeyCount = 0;
uint8_t gcKeyValue = 0;
uint16_t giKey1Count = 0;
uint16_t giKey2Count = 0;


void Key_GPIO_Config (void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK|KEY2_GPIO_CLK,ENABLE); 
	
	GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = KEY2_GPIO_PIN; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;              //浮空输入
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
//		gcKeyValue = Key1;	   //改成抬起反应
	}
	else
		Clr_Key1Down_Flag;
	
	if (Key2_Read == 0)
	{
		Set_Key2Down_Flag;
//		gcKeyValue = Key2;
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
	
////	if(Key1_Read == 1 && Key2_Read == 1)
////	{
////		gcKeyValue = 0x00;
////	}
		
}



uint8_t Key_Check(void)
{
//	LED3_TOGGLE;
	switch(gcKeyState)
	{
		/*check*/
		case 0:
		{
			/*have prass*/
			if(Key1_Read == 0 || Key2_Read == 0)
			{
				  gcKeyCount++;
				  if(gcKeyCount >= 1)      //
					{
						gcKeyCount = 0;
						gcKeyState = 1;
					}
			}
			else
			{
				gcKeyCount = 0;
			}
		}
		break;
		
		/*key down*/
		case 1:
		{
//			LED3_TOGGLE;
			Set_KeyReturn_Flag;
			Get_Key_Value();
			gcKeyState = 2;
		}
		break;
		
		/**/
		case 2:
		{			
			/* 按键全抬起 */
			if(Key1_Read == 1 && Key2_Read == 1)
			{
				gcKeyCount++;
				if(gcKeyCount >= 1)   //
				{
					gcKeyCount = 0;					
					giKey1Count = 0;
					giKey2Count = 0;
					
					//抬起反应
					if(Key1Down_Flag)		
					{
						Set_KeyReturn_Flag;
						gcKeyValue = Key1;
					}		
          if(Key2Down_Flag)
					{
						Set_KeyReturn_Flag;
						gcKeyValue = Key2;
					}	
          gcKeyState = 0;	      //在按键弹起之后，要回到第一步				
				}
			}
			
			/* hold on the key */
			else
			{				
				/*Key1_3s*/
				if(Key1Down_Flag)
				{
					if(giKey1Count < 300)
						giKey1Count++;
					if(giKey1Count >= 300)
					{
						giKey1Count = 310;
						gcKeyValue = Key1_3s;
						Set_KeyReturn_Flag;						
					}
				}
				
				/*Key2_3s*/
				if(Key2Down_Flag)
				{
					if(giKey2Count < 300)    //3s
						giKey2Count++;
					if(giKey2Count >= 300)
					{
						giKey2Count = 310;
						gcKeyValue = Key2_3s;
						Set_KeyReturn_Flag;				
					}
				}	       			
			}
		}
		
		break;
		default:
			gcKeyState = 0;
			break;	
	}
	
	if (KeyReturn_Flag)
	{
		Clr_KeyReturn_flag;
		return gcKeyValue;
	}
	else
	{
		return 0;
	}
		
}

void Key_Process(void)
{
	switch(Key_Check())
	{
		case Key1 :
		{
			LED1_ON;
		}
		break;
		case Key2 :
		{
			LED2_ON;
		}
		break;
		case Keycom1 :
		{
//			LED_OFF;
		}
		break;
		case Key1_3s :
		{
//			LED4_ON;
		}
		break;
		case Key2_3s :
		{
//			LED_OFF;
		}
		break;
		default:
			break;
	}
}


