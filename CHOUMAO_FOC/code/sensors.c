#include "zf_common_headfile.h"
#include "sensors.h"


uint16 SOA1=0,SOA2=0;
uint16 Voltage_A=0,Voltage_B=0,Voltage_C=0;

#define _ADC_CONV    0.00080586f

float _shunt_resistor = 0;
float amp_gain = 0;
float vlots_to_amps = 0;
float gain_a, gain_b, gain_c;
float offset_ia = 0.0, offset_ib = 0.0;
float current_a, current_b, current_c;

//¡„∆ØºÏ≤‚
void DriftOffsets()
{
    uint16_t detect_rounds = 1000;
    for(int i = 0; i < detect_rounds; i++)
    {
        offset_ia += Samp_volts[0]*_ADC_CONV;
        offset_ib += Samp_volts[1]*_ADC_CONV;
    }
    offset_ia = offset_ia / detect_rounds;
    offset_ib = offset_ib / detect_rounds;

}


void CurrSense_Init(void)
{
    adc_init(ADC2_IN10_C0,ADC_12BIT);  //SOA1
    adc_init(ADC2_IN11_C1,ADC_12BIT);  //SOA2

    adc_init(ADC1_IN0_A0,ADC_12BIT);  //UA
    adc_init(ADC1_IN1_A1,ADC_12BIT);  //UB
    adc_init(ADC1_IN2_A2,ADC_12BIT);  //UC


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









