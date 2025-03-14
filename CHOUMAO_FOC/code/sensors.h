#ifndef _SENSOR_H_
#define _SENSOR_H_

extern uint16 SOA1;
extern uint16 SOA2;

extern uint16 Voltage_A;
extern uint16 Voltage_B;
extern uint16 Voltage_C;


void Current_sensor_init(void);
void Voltage_sensor_init(void);
void Get_Current(void);

void Get_Voltage(void);


#endif


