/***************************************************************************

             IOCtrl��PIC��Ƭ���е�ʵ��ģ��

***************************************************************************/
#ifndef __IOCTRL_PIC_H
#define __IOCTRL_PIC_H

#include <pic.h>
#include "PicBit.h"

//-------------------------��Xxx���ܿڵ����в���--------------------------
//Xxx����ֱ��ʹ��Ӳ��PCB�ϵĶ���,����ȫ��Ϊ��д,�ұ��뱣֤����Ŀ�е�Ψһ��
//ʹ��ʱ,��ɾ��(��ʵ��)������ʹ�õ��ĺ꺯��
//�ȶ�����Է����޸�:
#define TRIS_Xxx		TRISB
#define PORT_Xxx		LATB
#define PIN_Xxx			PORTB
#define BIT_Xxx			0x04
//����
#define InXxx()			do{TRIS_Xxx |= BIT_Xxx;}while(0)
#define OutXxx()		do{TRIS_Xxx &= ~BIT_Xxx;}while(0)
#define IsOutXxx()		(!(TRIS_Xxx & BIT_Xxx))
//���ʱ,�ߵ͵�ƽ
#define SetXxx()		do{PORT_Xxx |= BIT_Xxx;}while(0)
#define ClrXxx()		do{PORT_Xxx &= ~BIT_Xxx;}while(0)
#define IsSetXxx()		(PORT_Xxx & BIT_Xxx)
//����ʱ,�Ƿ�Ϊ�ߵ�ƽ
#define IsXxx()		        (PIN_Xxx & BIT_Xxx)
//����ʱ,�Ͻӵ���(ֻ��PORTB�����ֿ���)
#define SetPullUpXxx()		do{WPUB |= BIT_Xxx;}while(0)
#define ClrPullUpXxx()		do{WPUB &= ~BIT_Xxx;}while(0)
#define IsPullUpXxx()	    (WPUB & BIT_Xxx)

//��ʼ��������(�˺������õ���ģ���е���, ������Ϊ����ߵ�ƽΪ��):
#define CfgXxx() do{ANSELB &= ~BIT_Xxx; SetXxx(); OutXxx();}while(0)

//-------------------------IO�ڵ�ͳһ���ò���--------------------------
//�˺����ڿ�����ʼ��ʱͳһ����,�������ò����õ���IO��Ϊ��Ҫ��״̬��
//IOCtrl_Init()ΪIOCtrl�Ĺ��캯��,�����κ���ʱ,��ʵ��Ϊ��.
#define IOCtrl_Init()  do{\
  OPTION_REG &= ~PICB_nWPUEN;\
}while(0)


#endif //#define __IOCTRL_PIC_H



