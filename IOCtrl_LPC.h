/***************************************************************************

             IOCtrl在LPC单片机中的实现模板(假定LPC系列结构相同)

***************************************************************************/
#ifndef __IOCTRL_LPC_H
#define __IOCTRL_LPC_H

#include "LPC12xx.h"
#include "LPC12xxbit.h"

//-------------------------对Xxx功能口的所有操作--------------------------
//Xxx建议直接使用硬件PCB上的定义,建议全部为大写,且必须保证在项目中的唯一性
//使用时,可删除(或不实现)不可能使用到的宏函数

//注:
//n: 那个PORT上
//m: PORT的具体那一位 

//方向
#define InXxx()			do{LPC_GPIOn->DIR &= ~(1 << m);}while(0)
#define OutXxx()		do{LPC_GPIOn->DIR |= (1 << m);}while(0)
#define IsOutXxx()		(LPC_GPIOn->DIR & (1 << m))
//输出时,高低电平
#define SetXxx()		do{LPC_GPIOn->SET = (1 << m);}while(0)
#define ClrXxx()		do{LPC_GPIOn->CLR = (1 << m);}while(0)
#define IsSetXxx()		(LPC_GPIOn->PIN & (1 << m))
//输入时,是否为高电平
#define IsXxx()		        (LPC_GPIOn->OUT & (1 << m))
//输入时,上接电阻(不支持)
#define SetPullUpXxx()		do{}while(0)
#define ClrPullUpXxx()		do{}while(0)
#define IsPullUpXxx()	    (1 == 0)

//初始化及配置(此函数在用到的模块中调用, 以配置为输出高电平为例):
#define CfgXxx() do{LPC_IOCON->PIOn_m = 0x90; SetXxx(); OutXxx();}while(0)

//-------------------------IO口的统一配置操作--------------------------
//此函数在开机初始化时统一调用,可用于置不会用到的IO口为需要的状态等
//IOCtrl_Init()为IOCtrl的构造函数,不做任何事时,请实现为空.
#define IOCtrl_Init()  do{\
  LPC_SYSCON->SYSAHBCLKCTRL |= (GPIO0_ACC | GPIO1_ACC | GPIO2_ACC);\
}while(0)


#endif //#define __IOCTRL_LPC_H



