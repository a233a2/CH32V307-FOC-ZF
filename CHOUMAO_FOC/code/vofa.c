#include "zf_common_headfile.h"

float tempFloat[3];  //7

unsigned char tail[4]={0x00, 0x00, 0x80, 0x7f};


void Vofa_Send_Data(void)
{
    tempFloat[0]=(float)dc_a;
    tempFloat[1]=(float)dc_b;
    tempFloat[2]=(float)dc_c;


    uart_write_buffer(UART_3 , (unsigned char *)tempFloat, sizeof(float)*16);
    uart_write_buffer(UART_3 ,tail, 4);    // 发送帧尾
    //systick_delay_ms(STM0,100);
}

