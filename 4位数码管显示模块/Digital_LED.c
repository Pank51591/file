/* 
 *版权信息： 深圳天微电子 
 *文件名： TM1637 
 *当前版本： 1.0 
 *单片机型号： AT89S52 
 *开发环境： Keil uVision3 
 *晶震频率： 11.0592M 
 *程序功能： 把 TM1637 所有显示寄存器地址全部写满数据 0xff，并开显示，然后再读按键值。 
 */ 
#include<reg52.h> 
#include<intrins.h> 


//定义端口 
sbit clk = P1^2; 
sbit dio = P1^1; 

///======================================= 
void Delay_us(unsigned int i) //nus 延时 
{ 
	 for(;i>0;i--) 
	 _nop_(); 
} 
///====================================== 
void I2CStart(void)  //1637 开始 
{ 
	 clk = 1; 
	 dio = 1; 
	 Delay_us(2); 
	 dio = 0; 
} 
///============================================= 
void I2Cask(void) //1637 应答 
{ 
	clk = 0; 
	Delay_us(5); //在第八个时钟下降沿之后延时 5us，开始判断 ACK 信号 
	while(dio); 
	 clk = 1; 
	Delay_us(2); 
	 clk=0; 
} 
///========================================

void I2CStop(void) // 1637 停止 
{ 
	 clk = 0; 
	 Delay_us(2); 
	 dio = 0; 
	 Delay_us(2); 
	 clk = 1; 
	 Delay_us(2); 
	 dio = 1; 
} 
///========================================= 
void I2CWrByte(unsigned char oneByte) //写一个字节 
{ 
	 unsigned char i; 
	 for(i=0;i<8;i++) 
	 { 
		clk = 0; 
		 if(oneByte&0x01) //低位在前 
		 { 
			dio = 1; 
		 } 
		 else 
		 { 
			dio = 0; 
		 } 
		 Delay_us(3); 
		 oneByte=oneByte>>1; 
		 clk=1; 
		 Delay_us(3); 
	 } 
} 

///------------------------------------------------- 
unsigned char ScanKey(void) //读按键 
{ 
	unsigned char rekey,rkey,i; 
	 I2CStart(); 
	 I2CWrByte(0x42); //读按键命令 
	 I2Cask(); 
	 dio=1; // 在读按键前拉高数据线 
	 for(i=0;i<8;i++) //从低位开始读 
	{	clk=0; 
		rekey=rekey>>1;
		Delay_us(30); 
		clk=1; 
		if(dio) 
		{ 
			rekey=rekey|0x80; 
		} 
		else 
		{ 
			rekey=rekey|0x00; 
		} 
		Delay_us(30); 
	 } 
	 I2Cask(); 
	 I2CStop(); 
	 return (rekey); 
} 
///================================================ 
void SmgDisplay(void) //写显示寄存器 
{ 
	unsigned char i; 
	I2CStart(); 
	I2CWrByte(0x40); // 40H 地址自动加 1 模式,44H 固定地址模式,本程序采用自加 1 模式 
	I2Cask(); 
	I2CStop(); 
	I2CStart(); 
	I2CWrByte(0xc0); //设置首地址， 
	I2Cask(); 
 
	for(i=0;i<6;i++) //地址自加，不必每次都写地址 
	{ 
		I2CWrByte(0xff); //送数据 
		I2Cask(); 
	} 
	I2CStop(); 
	I2CStart(); 
	I2CWrByte(0x8f); //开显示 ，最大亮度 
	I2Cask(); 
	I2CStop(); 
} 
///==============================================
void init() //初始化子程序 
{ 
  //初始化略 
} 
///============================================== 
void main(void) 
{ 
	unsigned char keydate; 
	init()； //初始化 
	SmgDisplay(); //写寄存器并开显示 
	while(1) 
	{ 
		keydate=Scankey(); //读按键值 ，读出的按键值不作处理。 
	} 
} 
//===========end==================================


