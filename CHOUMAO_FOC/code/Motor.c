#include "zf_common_headfile.h"
    /**TIM1 GPIO Configuration
    E8     ------> HA
    E9     ------> LA
    E10    ------> HB
    E11    ------> LB
    E12    ------> HC
    E13    ------> LC
    */


#define PWM_MAX 10000       // PWM ���ֵ
#define PWM_DUTY 2000       // 50% ռ�ձ�
#define Step_Delay 10000    // ����ʱ�� (us)

uint16 pwmA, pwmB, pwmC;



void DRV8301_Init(void)
{
    pwm_init(LA_PWM, FOC_PWM_FREC, 5000);//E9     ------> LA
    pwm_init(LB_PWM, FOC_PWM_FREC, 5000);//E11    ------> LB
    pwm_init(LC_PWM, FOC_PWM_FREC, 5000);//E13    ------> LC
}



void Play_Welcome(void) {
    // Maxwell The Cat ����Ƶ�� (Hz)
    uint32_t melody[] = {
            1000, 2000, 3000,
    };

    // ÿ�������ĳ���ʱ�� (ms)
    uint32_t note_durations[] = {
        300, 300, 300,
    };

    uint8_t notes = sizeof(melody)/sizeof(melody[0]);

    for (uint8_t i = 0; i < notes; i++) {
        // ��̬ռ�ձ���ǿ�����

        pwm_set_freq(LA_PWM, melody[i], 6000);
        pwm_set_freq(LB_PWM, melody[i], 6000);
        pwm_set_freq(LC_PWM, melody[i], 6000);
        // ��ȷ������ƣ�����������ľ��������
        system_delay_ms(note_durations[i]);       // ��ǰ��������ͣ�ٸ�
    }
        pwm_set_freq(LA_PWM, FOC_PWM_FREC, 0);
        pwm_set_freq(LB_PWM, FOC_PWM_FREC, 0);
        pwm_set_freq(LC_PWM, FOC_PWM_FREC, 0);
}




void Duty_Set(float A_DUTY,float B_DUTY,float C_DUTY)
{
    if(A_DUTY>=PWM_MAX)A_DUTY=PWM_MAX;
    if(B_DUTY>=PWM_MAX)B_DUTY=PWM_MAX;
    if(C_DUTY>=PWM_MAX)C_DUTY=PWM_MAX;
    if(A_DUTY<=0)A_DUTY=0;
    if(B_DUTY<=0)B_DUTY=0;
    if(C_DUTY<=0)C_DUTY=0;
    pwm_set_duty(LA_PWM, A_DUTY);
    pwm_set_duty(LB_PWM, B_DUTY);
    pwm_set_duty(LC_PWM, C_DUTY);
}














