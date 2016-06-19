/***************************************************************************

             IOCtrl在AVR单片机中的实现模板

***************************************************************************/
#ifndef __IOCTRL_AVR_H
#define __IOCTRL_AVR_H

#include <ioavr.h>

//-------------------------对Xxx功能口的所有操作--------------------------
//Xxx建议直接使用硬件PCB上的定义,建议全部为大写,且必须保证在项目中的唯一性
//使用时,可删除(或不实现)不可能使用到的宏函数
//先定义口以方便修改:
#define DDR_Xxx		  DDRD
#define PORT_Xxx		PORTD
#define PIN_Xxx			PIND
#define BIT_Xxx			0x04

//方向
#define InXxx()			do{DDR_Xxx &= ~BIT_Xxx;}while(0)
#define OutXxx()		do{DDR_Xxx |= BIT_Xxx;}while(0)
#define IsOutXxx()		(DDR_Xxx & BIT_Xxx)
//输出时,高低电平
#define SetXxx()		do{PORT_Xxx |= BIT_Xxx;}while(0)
#define ClrXxx()		do{PORT_Xxx &= ~BIT_Xxx;}while(0)
#define IsSetXxx()		(PORT_Xxx & BIT_Xxx)
//输入时,是否为高电平
#define IsXxx()		        (PIN_Xxx & BIT_Xxx)
//输入时,上接电阻(在输入状态,AVR的PORT端复用作上拉电阻功能)
#define SetPullUpXxx()		do{PORT_Xxx |= BIT_Xxx;}while(0)
#define ClrPullUpXxx()		do{PORT_Xxx &= ~BIT_Xxx;}while(0)
#define IsPullUpXxx()	    (PORT_Xxx & BIT_Xxx)

//初始化及配置(此函数在用到的模块中调用, 以配置为输出高电平为例):
#define CfgXxx() do{SetXxx();OutXxx();}while(0)

//-------------------------IO口的统一配置操作--------------------------
//此函数在开机初始化时统一调用,可用于置不会用到的IO口为需要的状态等
//IOCtrl_Init()为IOCtrl的构造函数,不做任何事时,请实现为空.
#define IOCtrl_Init()  do{\
}while(0)


#endif //#define __IOCTRL_AVR_H



