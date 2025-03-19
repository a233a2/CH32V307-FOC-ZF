#include "zf_common_headfile.h"
float y = 0;
float Lowpassfilter_sim(float x)
{
    float out = 0.9*x + 0.1*y;
    y = x;
    return out;
}

uint32_t Last_Timesamp = 0.0;
float Last_y = 0.0;
float Lowpassfilter(float Tf, float x)
{
    float dt = 0.0;

    uint32_t Timesamp = timer_get(TIM_2);
    if(Timesamp < Last_Timesamp) dt = (float)(Last_Timesamp - Timesamp)/9*1e-6;
    else
        dt = (float)(0xFFFFFF - Timesamp + Last_Timesamp)/9*1e-6;

    if(dt<0.0||dt==0) dt = 0.0015f;
    else if(dt>0.005f)
    {
        Last_y = x;
        Last_Timesamp = Timesamp;
        return x;
    }
    float alpha = Tf / (Tf + dt);
    float y = alpha * Last_y + (1.0f - alpha) * x;

    Last_y = y;
    Last_Timesamp = Timesamp;


    return y;
}

