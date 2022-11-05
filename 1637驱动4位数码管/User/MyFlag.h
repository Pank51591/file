#ifndef MYFLAG_H_
#define MYFLAG_H_

#include "stm32f10x.h"

struct Flag_Class
{
	uint8_t Key1Down;
	uint8_t Key2Down;
	uint8_t Key1_2Down;
	uint8_t KeyReturn;

};

struct Flag_Class MyFlag;

#define Key1Down_Flag       MyFlag.Key1Down
#define Set_Key1Down_Flag   MyFlag.Key1Down = 1;
#define Clr_Key1Down_Flag   MyFlag.Key1Down = 0;

#define Key2Down_Flag       MyFlag.Key2Down
#define Set_Key2Down_Flag   MyFlag.Key2Down = 1;
#define Clr_Key2Down_Flag   MyFlag.Key2Down = 0;

#define Key1_2Down_Flag       MyFlag.Key1_2Down
#define Set_Key1_2Down_Flag   MyFlag.Key1_2Down = 1;
#define Clr_Key1_2Down_Flag   MyFlag.Key1_2Down = 0;

#define KeyReturn_Flag          MyFlag.KeyReturn
#define Set_KeyReturn_Flag      MyFlag.KeyReturn = 1;
#define Clr_KeyReturn_flag      MyFlag.KeyReturn = 0;



#endif

