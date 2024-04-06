/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   RCC ʱ������
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:����  STM32 F429 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
	
	
// ʹ��HSE����HSI ����ϵͳʱ��
#include "stm32f4xx.h"
#include "./rcc/bsp_clkconfig.h"
#include "./led/bsp_led.h"



void Delay(__IO u32 nCount); 

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
    // ��������main����֮ǰ�������ļ���statup_stm32f429_439xx.s�Ѿ�����
    // SystemInit()������ϵͳʱ�ӳ�ʼ����72MHZ
    // SystemInit()��system_stm32f4xx.c�ж���
    // ����û����޸�ϵͳʱ�ӣ������б�д�����޸�	
    // ��������ϵͳʱ�ӣ���ʱ�����ѡ��ʹ��HSE����HSI

    // ʹ��HSE������ϵͳʱ��Ϊ180M
    HSE_SetSysClock(25, 360, 2, 7);

    //ϵͳʱ�ӳ�Ƶ��216Mˬһ�£������216M������������
    //HSE_SetSysClock(25, 432, 2, 9);

    // ʹ��HSI������ϵͳʱ��Ϊ180M
    //HSI_SetSysClock(16, 360, 2, 7);

    // LED �˿ڳ�ʼ�� 
    LED_GPIO_Config();

    // MCO GPIO  ��ʼ��
    MCO1_GPIO_Config();
    MCO2_GPIO_Config();	

    // MCO1 ���PLLCLK	
    RCC_MCO1Config(RCC_MCO1Source_PLLCLK, RCC_MCO1Div_1);

    // MCO2 ���SYSCLK
    RCC_MCO2Config(RCC_MCO2Source_SYSCLK, RCC_MCO1Div_1);

	while (1)
	{
        LED1( ON );			 // �� 
        Delay(0x0FFFFF);
        LED1( OFF );		 // ��
        Delay(0x0FFFFF);
	}
}


void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/

