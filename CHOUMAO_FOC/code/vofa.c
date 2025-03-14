#include "zf_common_headfile.h"

float tempFloat[3];  //7

unsigned char tail[4]={0x00, 0x00, 0x80, 0x7f};


void Vofa_Send_Data(void)
{
    tempFloat[0]=(float)pwmA;
    tempFloat[1]=(float)pwmB;
    tempFloat[2]=(float)pwmC;


    uart_write_buffer(UART_1 , (unsigned char *)tempFloat, sizeof(float)*16);
    uart_write_buffer(UART_1 ,tail, 4);    // 发送帧尾
    //systick_delay_ms(STM0,100);
}

