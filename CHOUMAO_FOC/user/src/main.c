#include "zf_common_headfile.h"





uint16 Show_Flag=0;
int main(void)
{
    clock_init(SYSTEM_CLOCK_144M);      // 初始化芯片时钟 工作频率为 120MHz
    debug_init();                       // 务必保留，本函数用于初始化MPU 时钟 调试串口

    // 此处编写用户代码 例如外设初始化代码等


    uart_init(UART_1, 115200, UART1_MAP0_TX_A9, UART1_MAP0_RX_A10);
    ips114_init();
    Current_sensor_init();
    Voltage_sensor_init();
    SoftI2C_Init();
    DRV8301_Init();

    timer_init(TIM_2, TIMER_US);


    ips114_show_string(0, 0, "CHOUMAO_FOC_Ready");
    ips114_show_string(0, 17, "Q1_i:");
    ips114_show_string(110, 17, "Q2_i:");

    ips114_show_string(0, 33, "VA:");
    ips114_show_string(85, 33, "VB:");
    ips114_show_string(155, 33, "VC:");

    ips114_show_string(0, 50, "Dis:");
    ips114_show_string(80, 50, "Ang:");
    ips114_show_string(155, 50, "Ele:");


    // 此处编写用户代码 例如外设初始化代码等
    Play_Welcome();
    timer_start(TIM_2);

    while(1)
    {
        if(Show_Flag>=200)
        {
            Show_Flag=0;
            Get_Current();
            Get_Voltage();
            AS5600_UpdateAngle(&Distance, &angle_360, &Ele_rad);


            ips114_show_uint(40, 17, SOA1, 4);
            ips114_show_uint(150, 17, SOA2, 4);

            ips114_show_uint(30, 33, Voltage_A, 4);
            ips114_show_uint(110, 33, Voltage_B, 4);
            ips114_show_uint(180, 33, Voltage_C, 4);

            ips114_show_int(30, 50, Distance, 4);
            ips114_show_int(115, 50, angle_360, 3);
            ips114_show_int(190, 50, Ele_rad, 4);   //Ele_rad
        }else Show_Flag++;
        velocityOpenloop(5);  // 开环FOC控制
        //Vofa_Send_Data();
    }
}






