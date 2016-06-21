/***************************************************************************

             IOCtrl在PIC单片机中的实现模板

***************************************************************************/
#ifndef __IOCTRL_PIC_H
#define __IOCTRL_PIC_H

#include <pic.h>
#include "PicBit.h"

//-------------------------对Xxx功能口的所有操作--------------------------
//Xxx建议直接使用硬件PCB上的定义,建议全部为大写,且必须保证在项目中的唯一性
//使用时,可删除(或不实现)不可能使用到的宏函数
//先定义口以方便修改:
#define TRIS_Xxx		TRISB
#define PORT_Xxx		LATB
#define PIN_Xxx			PORTB
#define BIT_Xxx			0x04
//方向
#define InXxx()			do{TRIS_Xxx |= BIT_Xxx;}while(0)
#define OutXxx()		do{TRIS_Xxx &= ~BIT_Xxx;}while(0)
#define IsOutXxx()		(!(TRIS_Xxx & BIT_Xxx))
//输出时,高低电平
#define SetXxx()		do{PORT_Xxx |= BIT_Xxx;}while(0)
#define ClrXxx()		do{PORT_Xxx &= ~BIT_Xxx;}while(0)
#define IsSetXxx()		(PORT_Xxx & BIT_Xxx)
//输入时,是否为高电平
#define IsXxx()		        (PIN_Xxx & BIT_Xxx)
//输入时,上接电阻(只有PORTB及部分口有)
#define SetPullUpXxx()		do{WPUB |= BIT_Xxx;}while(0)
#define ClrPullUpXxx()		do{WPUB &= ~BIT_Xxx;}while(0)
#define IsPullUpXxx()	    (WPUB & BIT_Xxx)

//初始化及配置(此函数在用到的模块中调用, 以配置为输出高电平为例):
#define CfgXxx() do{ANSELB &= ~BIT_Xxx; SetXxx(); OutXxx();}while(0)

//-------------------------IO口的统一配置操作--------------------------
//此函数在开机初始化时统一调用,可用于置不会用到的IO口为需要的状态等
//IOCtrl_Init()为IOCtrl的构造函数,不做任何事时,请实现为空.
#define IOCtrl_Init()  do{\
  OPTION_REG &= ~PICB_nWPUEN;\
}while(0)


#endif //#define __IOCTRL_PIC_H



