#include "zf_common_headfile.h"
#include "math.h"
#include <stdlib.h>



float Ua=0,Ub=0,Uc=0,Ualpha,Ubeta=0,dc_a=0,dc_b=0,dc_c=0;
float voltage_limit = 7;
float voltage_power_supply = 0;
float zero_electric_Angle=0.0;

int pp = 7,Dir = 1;

//ÏÞÖÆ·ùÖµ
float constrain(float amt, float low, float high)
{
     return ((amt<low)?(low):((amt)>(high)?(high):(amt)));
}

//½«½Ç¶È¹é»¯µ½0-2PI
float normalizeAngle(float angle)
{
    float a = fmod(angle, 2*PI);
    return ((a>=0) ? a : (a + 2*PI));
}

float electricAngle(void)
{
    return normalizeAngle((GetAngle_NoTrack() * pp * Dir) - zero_electric_Angle);
}

void SetPwm(float Ua, float Ub, float Uc)
{
    float U_a=0.0;
    float U_b=0.0;
    float U_c=0.0;

    U_a = constrain(Ua, 0.0f, voltage_limit);
    U_b = constrain(Ub, 0.0f, voltage_limit);
    U_c = constrain(Uc, 0.0f, voltage_limit);

    dc_a = constrain(U_a / voltage_power_supply, 0.0f, 1.0f);
    dc_b = constrain(U_b / voltage_power_supply, 0.0f, 1.0f);
    dc_c = constrain(U_c / voltage_power_supply, 0.0f, 1.0f);

    pwm_set_duty(LA_PWM, dc_a);
    pwm_set_duty(LA_PWM, dc_b);
    pwm_set_duty(LA_PWM, dc_c);

}

//FOCºËÐÄËã·¨£¬¿ËÀ­¿ËÄæ±ä»»/ÅÁ¿ËÄæ±ä»»
void SetPhaseVoltage(float Uq, float Ud, float angle_el)
{
//  angle_el = normalizeAngle(angle_el);

    Ualpha = -Uq*sin(angle_el);
    Ubeta = Uq*cos(angle_el);

    Ua = Ualpha + voltage_power_supply / 2;
    Ub = (sqrt(3)*Ubeta - Ualpha) / 2 + voltage_power_supply / 2;
    Uc = -(Ualpha + sqrt(3)*Ubeta) / 2 + voltage_power_supply / 2;

    SetPwm(Ua,Ub,Uc);
}


void Check_Sensor(void)
{
    SetPhaseVoltage(3, 0, _3PI_2);
    delay_ms(3000);
    zero_electric_Angle = electricAngle();
    SetPhaseVoltage(0, 0, _3PI_2);
    delay_ms(500);
}

void FOC_Init(void)
{
    voltage_power_supply = VOLTAGE_IN;
    DRV8301_Init();
    CurrSense_Init();
    AS5600_Init();

    Check_Sensor();
}

// ´®¿Ú½ÓÊÕ
float Last_C_Num = 0.0;
float GetCommand(void)
{
    float C_Num = 0.0;
    char *Getchar;
    uint8 Serial_RxPacket;
    if(uart_query_byte(UART_3,&Serial_RxPacket) == 1)
    {
        C_Num = strtof(Serial_RxPacket, &Getchar);
        Last_C_Num = C_Num;

        return C_Num;
    }
    return Last_C_Num;
}

float shaft_angle;
float openloop_timestamp;
float velocityopenloop(float target)
{
    float Uq = 0.0;
    float Ts = 0.0;

    uint32_t now_ts  =  timer_get(TIM_2);

    if(now_ts < openloop_timestamp)
      Ts = (openloop_timestamp - now_ts)/9.0f*1e-6f;
    else
        Ts = (0xFFFFFF - now_ts + openloop_timestamp)/9.0f*1e-6f;

    if(Ts < 0||Ts >= 0.005)  Ts = 0.001f;

    shaft_angle = normalizeAngle(shaft_angle + pp*target*Ts);

//  Serial_SendFloatNumber(Ts, 1, 6);
//  Serial_SendString("\n");

    Uq = voltage_limit;

    SetPhaseVoltage(Uq, 0, shaft_angle);

    openloop_timestamp = now_ts;

    return Uq;
}






