/***************************************************************************

             IOCtrl��AVR��Ƭ���е�ʵ��ģ��

***************************************************************************/
#ifndef __IOCTRL_AVR_H
#define __IOCTRL_AVR_H

#include <ioavr.h>

//-------------------------��Xxx���ܿڵ����в���--------------------------
//Xxx����ֱ��ʹ��Ӳ��PCB�ϵĶ���,����ȫ��Ϊ��д,�ұ��뱣֤����Ŀ�е�Ψһ��
//ʹ��ʱ,��ɾ��(��ʵ��)������ʹ�õ��ĺ꺯��
//�ȶ�����Է����޸�:
#define DDR_Xxx		  DDRD
#define PORT_Xxx		PORTD
#define PIN_Xxx			PIND
#define BIT_Xxx			0x04

//����
#define InXxx()			do{DDR_Xxx &= ~BIT_Xxx;}while(0)
#define OutXxx()		do{DDR_Xxx |= BIT_Xxx;}while(0)
#define IsOutXxx()		(DDR_Xxx & BIT_Xxx)
//���ʱ,�ߵ͵�ƽ
#define SetXxx()		do{PORT_Xxx |= BIT_Xxx;}while(0)
#define ClrXxx()		do{PORT_Xxx &= ~BIT_Xxx;}while(0)
#define IsSetXxx()		(PORT_Xxx & BIT_Xxx)
//����ʱ,�Ƿ�Ϊ�ߵ�ƽ
#define IsXxx()		        (PIN_Xxx & BIT_Xxx)
//����ʱ,�Ͻӵ���(������״̬,AVR��PORT�˸������������蹦��)
#define SetPullUpXxx()		do{PORT_Xxx |= BIT_Xxx;}while(0)
#define ClrPullUpXxx()		do{PORT_Xxx &= ~BIT_Xxx;}while(0)
#define IsPullUpXxx()	    (PORT_Xxx & BIT_Xxx)

//��ʼ��������(�˺������õ���ģ���е���, ������Ϊ����ߵ�ƽΪ��):
#define CfgXxx() do{SetXxx();OutXxx();}while(0)

//-------------------------IO�ڵ�ͳһ���ò���--------------------------
//�˺����ڿ�����ʼ��ʱͳһ����,�������ò����õ���IO��Ϊ��Ҫ��״̬��
//IOCtrl_Init()ΪIOCtrl�Ĺ��캯��,�����κ���ʱ,��ʵ��Ϊ��.
#define IOCtrl_Init()  do{\
}while(0)


#endif //#define __IOCTRL_AVR_H



