#ifndef __PID_CONTROL_H
#define __PID_CONTROL_H

float PID_Controller(float Kp, float Ki, float Kd, float Error);
float  _constrain(float amt, float low, float high);

#endif


