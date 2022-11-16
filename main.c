#include "stm32l1xx.h"
#include "stm32l1xx_nucleo.h"
#include <stdio.h>
#define Vref 3.6
uint16_t Vx1,Vy1,Vz1,Vx2,Vy2,Vz2;
uint16_t
adc_data_PC0,adc_data_PC1,adc_data_PC2,adc_data_PC3,adc_data_PC4,adc_data_PC5;
GPIO_InitTypeDef GPIO_InitStructure;
ADC_InitTypeDef ADC_InitStructure;
ADC_CommonInitTypeDef ADC_CommonInitStructure;
void confgADC()
{
RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE); // ADC
RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE); // X OUT les pc-2
channel 12

4

// pour la sortie xout
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2
| GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
GPIO_Init(GPIOC, &GPIO_InitStructure);
// onfig adc and initialize ADC
ADC_Init(ADC1, &ADC_InitStructure);
ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
ADC_InitStructure.ADC_ScanConvMode=ENABLE;
ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
ADC_InitStructure.ADC_ExternalTrigConvEdge =

ADC_ExternalTrigConvEdge_None;
ADC_InitStructure.ADC_ExternalTrigConv=ADC_ExternalTrigConv_T2_CC2;
ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
ADC_InitStructure.ADC_NbrOfConversion = 2;
ADC_CommonInitStructure.ADC_Prescaler=ADC_Prescaler_Div2;
ADC_CommonInit(&ADC_CommonInitStructure);

}
void Usart2Init ()
{
GPIO_InitTypeDef GPIO_Init_USART;
USART_InitTypeDef USART_InitStructure;
RCC_AHBPeriphClockCmd (RCC_AHBPeriph_GPIOA , ENABLE);
GPIO_Init_USART.GPIO_Pin = GPIO_Pin_2;
GPIO_Init_USART.GPIO_Mode = GPIO_Mode_AF;
GPIO_Init_USART.GPIO_Speed = GPIO_Speed_40MHz;
GPIO_Init_USART.GPIO_OType= GPIO_OType_PP;
GPIO_Init_USART.GPIO_PuPd=GPIO_PuPd_UP;
GPIO_Init (GPIOA,& GPIO_Init_USART);
GPIO_Init_USART.GPIO_Pin = GPIO_Pin_3;
GPIO_Init_USART.GPIO_Mode = GPIO_Mode_IN;
GPIO_Init (GPIOA,& GPIO_Init_USART);
GPIO_PinAFConfig(GPIOA ,GPIO_PinSource2 ,GPIO_AF_USART2);
GPIO_PinAFConfig(GPIOA ,GPIO_PinSource3 ,GPIO_AF_USART2);
RCC_APB1PeriphClockCmd (RCC_APB1Periph_USART2, ENABLE);
USART_InitStructure.USART_BaudRate = 9600;
USART_InitStructure.USART_WordLength = USART_WordLength_8b;
USART_InitStructure.USART_StopBits = USART_StopBits_1;
USART_InitStructure.USART_Parity = USART_Parity_No;
USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
USART_InitStructure.USART_HardwareFlowControl =
USART_HardwareFlowControl_None;
USART_Init (USART2,& USART_InitStructure);
USART_Cmd (USART2, ENABLE);
}
uint16_t RedX1ADC()
{
ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_16Cycles);
ADC_Cmd(ADC1, ENABLE);
while(ADC_GetFlagStatus(ADC1, ADC_FLAG_ADONS) == RESET)
{}
ADC_SoftwareStartConv(ADC1);
adc_data_PC0= ADC_GetConversionValue(ADC1);
return adc_data_PC0;

5

}
uint16_t RedY1ADC()
{
ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_16Cycles);
ADC_Cmd(ADC1, ENABLE);
while(ADC_GetFlagStatus(ADC1, ADC_FLAG_ADONS) == RESET)
{}
ADC_SoftwareStartConv(ADC1);
adc_data_PC1= ADC_GetConversionValue(ADC1);
return adc_data_PC1;

}
uint16_t RedZ1ADC()
{
ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 1, ADC_SampleTime_16Cycles);
ADC_Cmd(ADC1, ENABLE);
while(ADC_GetFlagStatus(ADC1, ADC_FLAG_ADONS) == RESET)
{}
ADC_SoftwareStartConv(ADC1);
adc_data_PC2= ADC_GetConversionValue(ADC1);
return adc_data_PC2;

}
uint16_t RedX2ADC()
{
ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1, ADC_SampleTime_16Cycles);
ADC_Cmd(ADC1, ENABLE);
while(ADC_GetFlagStatus(ADC1, ADC_FLAG_ADONS) == RESET)
{}
ADC_SoftwareStartConv(ADC1);
adc_data_PC3= ADC_GetConversionValue(ADC1);
return adc_data_PC3;

}
uint16_t RedY2ADC()
{
ADC_RegularChannelConfig(ADC1, ADC_Channel_14, 1, ADC_SampleTime_16Cycles);
ADC_Cmd(ADC1, ENABLE);
while(ADC_GetFlagStatus(ADC1, ADC_FLAG_ADONS) == RESET)
{}
ADC_SoftwareStartConv(ADC1);
adc_data_PC4= ADC_GetConversionValue(ADC1);
return adc_data_PC4;

}
uint16_t RedZ2ADC()
{
ADC_RegularChannelConfig(ADC1, ADC_Channel_15, 1, ADC_SampleTime_16Cycles);
ADC_Cmd(ADC1, ENABLE);
while(ADC_GetFlagStatus(ADC1, ADC_FLAG_ADONS) == RESET)
{}
ADC_SoftwareStartConv(ADC1);
adc_data_PC5= ADC_GetConversionValue(ADC1);
return adc_data_PC5;

}
void InitializeTimer()
{
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
// 200ns 2048 78
TIM_TimeBaseInitTypeDef timerInitStructure;
timerInitStructure.TIM_Prescaler =40000;
timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
timerInitStructure.TIM_Period =200;
timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
// timerInitStructure.TIM_RepetitionCounter = 0;
TIM_TimeBaseInit(TIM2, &timerInitStructure);
TIM_Cmd(TIM2, ENABLE);
TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
}
void EnableTimerInterrupt()

6

{
NVIC_InitTypeDef nvicStructure;
nvicStructure.NVIC_IRQChannel = TIM2_IRQn;
nvicStructure.NVIC_IRQChannelPreemptionPriority = 0;
nvicStructure.NVIC_IRQChannelSubPriority = 1;
nvicStructure.NVIC_IRQChannelCmd = ENABLE;
NVIC_Init(&nvicStructure);
}
void send_char(char x)
{
while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
USART_SendData(USART2,x);
}
void send_str(char* str)
{
int x=0;
while(str[x])
send_char(str[x++]);
}
void send_nbr(int nbr)
{
if(nbr/10)
send_nbr(nbr/10);
send_char((nbr%10)+48);
}
void transx(uint16_t x)
{
volatile float Resultatvalue;
Resultatvalue=(int)(x*Vref)/4095.000000;
send_nbr(Resultatvalue);

send_char('.');
send_nbr((int)(Resultatvalue*1000000)%100000000);
send_char('\r');
send_char('\n');

}
int main(void)
{

confgADC();
Usart2Init();
InitializeTimer();
EnableTimerInterrupt();
while(1)
{ }
}
void TIM2_IRQHandler()
{
if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)

{
TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
send_str("Vx1 = ");
Vx1=RedX1ADC();
transx(Vx1);
send_char('\n');
send_str("Vy1 = ");
Vy1=RedY1ADC();
transx(Vy1);
send_char('\n');

7

send_str("Vz1 = ");
Vz1=RedZ1ADC();
transx(Vz1);
send_char('\n');
send_char('\r');
send_str("Vx2 = ");
Vx2=RedX2ADC();
transx(Vx2);
send_char('\n');
send_str("Vy2 = ");
Vy2=RedY2ADC();
transx(Vy2);
send_char('\n');
send_str("Vz2 = ");
Vz2=RedZ2ADC();
transx(Vz2);
send_char('\n');
send_char('\r');

}
}
