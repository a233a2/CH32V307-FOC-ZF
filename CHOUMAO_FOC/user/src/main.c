#include "zf_common_headfile.h"




float Target = 0.0;
uint16 Show_Flag=0;
int main(void)
{
    clock_init(SYSTEM_CLOCK_144M);
    debug_init();

    uart_init(UART_3, 115200, UART3_MAP0_TX_B10, UART3_MAP0_RX_B11);
    ips114_init();
    Current_sensor_init();
    Voltage_sensor_init();

    FOC_Init();

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

    Play_Welcome();
    timer_start(TIM_2);

    while(1)
    {
        if(Show_Flag>=200)
        {
            Show_Flag=0;
            Get_Current();
            Get_Voltage();
            AS5600_UpdateAngle(&Distance, &angle_360, &Ele_rad);//5464564


            ips114_show_uint(40, 17, SOA1, 4);
            ips114_show_uint(150, 17, SOA2, 4);

            ips114_show_uint(30, 33, Voltage_A, 4);
            ips114_show_uint(110, 33, Voltage_B, 4);
            ips114_show_uint(180, 33, Voltage_C, 4);

            ips114_show_int(30, 50, Distance, 4);
            ips114_show_int(115, 50, angle_360, 3);
            ips114_show_int(190, 50, Ele_rad, 4);   //Ele_rad

            Vofa_Send_Data();

        }else Show_Flag++;

        Target = GetCommand();
        velocityopenloop(60);

    }
}






