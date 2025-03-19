#ifndef FOC_H
#define FOC_H
#include "zf_common_headfile.h"
#include "math.h"

#define VOLTAGE_IN         12.6
#define PI         3.14159265359f
#define _3PI_2     4.71238898f
#define _1_SQRT3     0.57735026919f
#define _2_SQRT3   1.15470053838f

extern float dc_a;
extern float dc_b;
extern float dc_c;


float constrain(float amt, float low, float high);
void SetPwm(float Ua, float Ub, float Uc);
float normalizeAngle(float angle);
void SetPhaseVoltage(float Uq, float Ud, float angle_el);
void Check_Sensor(void);
void FOC_Init(void);
float electricAngle(void);
float GetCommand(void);
float velocityopenloop(float target);

#endif

