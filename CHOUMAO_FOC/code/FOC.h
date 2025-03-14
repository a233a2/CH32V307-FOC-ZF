#ifndef FOC_H
#define FOC_H
#include "zf_common_headfile.h"
#include "math.h"


float velocityOpenloop(float target_velocity);
extern float dc_a;
void setPhaseVoltage(float Uq,float Ud, float angle_el);

#endif

