#include "zf_common_headfile.h"
#include "sensors.h"













uint16 SOA1=0,SOA2=0;
uint16 Voltage_A=0,Voltage_B=0,Voltage_C=0;

void Current_sensor_init(void)
{
    adc_init(ADC2_IN10_C0,ADC_12BIT);  //SOA1
    adc_init(ADC2_IN11_C1,ADC_12BIT);  //SOA2
}

void Voltage_sensor_init(void)
{
    adc_init(ADC1_IN0_A0,ADC_12BIT);  //SOA1
    adc_init(ADC1_IN1_A1,ADC_12BIT);  //SOA2
    adc_init(ADC1_IN2_A2,ADC_12BIT);  //SOA2
}

void Get_Current(void)
{
    SOA1=adc_mean_filter_convert(ADC2_IN10_C0,10);
    SOA2=adc_mean_filter_convert(ADC2_IN11_C1,10);
}

void Get_Voltage(void)
{
    Voltage_A=adc_mean_filter_convert(ADC1_IN0_A0,10);
    Voltage_B=adc_mean_filter_convert(ADC1_IN1_A1,10);
    Voltage_C=adc_mean_filter_convert(ADC1_IN2_A2,10);
}









