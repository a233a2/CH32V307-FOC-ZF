#include "zf_common_headfile.h"

#define  limit            6.3
#define  Output_ramp      10000

//ÏÞ·ù
float  _constrain(float amt, float low, float high)
{
    return ((amt<low)?(low):((amt)>(high)?(high):(amt)));
}

unsigned long Timestamp_Last = 0.0;
float Last_Error = 0.0;
float Last_intergration = 0.0;
float Last_Output = 0.0;
float PID_Controller(float Kp, float Ki, float Kd, float Error)
{
    float Ts = 0.0;
    uint32_t Timestamp = timer_get(TIM_2);
  if(Timestamp < Timestamp_Last) Ts = (float)(Timestamp_Last - Timestamp)/9*1e-6;
    else
        Ts = (0xFFFFFF - Timestamp + Timestamp_Last)/9*1e-6;

    if(Ts<=0 || Ts > 0.05f) Ts = 0.001;

    float proportion = Kp * Error;//P»·

    float intergration = Last_intergration + Ki * 0.5f * Ts * Error;//I»·
    intergration = _constrain(intergration, -limit, limit);

    float differential = Kd * (Error - Last_Error)/Ts;//D»·

    float Output = proportion + intergration + differential;
    Output = _constrain(Output, -limit, limit);

    Last_Error = Error;
    Last_intergration = intergration;
    Last_Output = Output;
    Timestamp_Last = Timestamp;

    return Output;
}



















