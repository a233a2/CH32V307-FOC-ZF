#include "zf_common_headfile.h"
    /**TIM1 GPIO Configuration
    E8     ------> HA
    E9     ------> LA
    E10    ------> HB
    E11    ------> LB
    E12    ------> HC
    E13    ------> LC
    */


#define PWM_MAX 10000       // PWM 最大值
#define PWM_DUTY 2000       // 50% 占空比
#define Step_Delay 10000    // 换相时间 (us)

uint16 pwmA, pwmB, pwmC;



void DRV8301_Init(void)
{
    pwm_init(LA_PWM, FOC_PWM_FREC, 5000);//E9     ------> LA
    pwm_init(LB_PWM, FOC_PWM_FREC, 5000);//E11    ------> LB
    pwm_init(LC_PWM, FOC_PWM_FREC, 5000);//E13    ------> LC
}

float theta = 0.0f;  // 旋转角度
float speed = 0.05f; // 角速度 (影响电机转速)

////////////////////////////////////////////////////////////////////FOC必要函数
// Clarke 变换: (Ia, Ib, Ic) -> (α, β)
void ClarkeTransform(float Ia, float Ib, float Ic, float *Ialpha, float *Ibeta) {
    *Ialpha = Ia;
    *Ibeta = (Ib - Ic) * 0.57735026919f;  // sqrt(3)/3
}

// Park 变换: (α, β) -> (d, q)
void ParkTransform(float Ialpha, float Ibeta, float theta, float *Id, float *Iq) {
    float cos_theta = cosf(theta);
    float sin_theta = sinf(theta);
    *Id = Ialpha * cos_theta + Ibeta * sin_theta;
    *Iq = -Ialpha * sin_theta + Ibeta * cos_theta;
}

// 逆 Park 变换: (d, q) -> (α, β)
void InverseParkTransform(float Id, float Iq, float theta, float *Ialpha, float *Ibeta) {
    float cos_theta = cosf(theta);
    float sin_theta = sinf(theta);
    *Ialpha = Id * cos_theta - Iq * sin_theta;
    *Ibeta = Id * sin_theta + Iq * cos_theta;
}


void SVPWM1(float Ualpha, float Ubeta, uint16_t *pwmA, uint16_t *pwmB, uint16_t *pwmC) {
    float Uref1 = Ualpha;
    float Uref2 = -0.5f * Ualpha + 0.86602540378f * Ubeta;  // sqrt(3)/2
    float Uref3 = -0.5f * Ualpha - 0.86602540378f * Ubeta;

    float Umax = fmaxf(fmaxf(Uref1, Uref2), Uref3);
    float Umin = fminf(fminf(Uref1, Uref2), Uref3);
    float Uoffset = (Umax + Umin) / 2.0f;

    Uref1 -= Uoffset;
    Uref2 -= Uoffset;
    Uref3 -= Uoffset;

    *pwmA = (uint16_t)((Uref1 / 2.0f + 0.5f) * PWM_MAX);
    *pwmB = (uint16_t)((Uref2 / 2.0f + 0.5f) * PWM_MAX);
    *pwmC = (uint16_t)((Uref3 / 2.0f + 0.5f) * PWM_MAX);
}

////////////////////////////////////////////////////////////////////开环FOC
void OpenLoopFOC(void) {
    float Ialpha, Ibeta;
    float Id = 0.0f;       // d 轴电流设为 0
    float Iq = 0.7f;       // 设定 q 轴电流大小 (决定转速)

    // 逆 Park 变换 (产生 α-β 轴电压)
    InverseParkTransform(Id, Iq, theta, &Ialpha, &Ibeta);

    SVPWM1(Ialpha, Ibeta, &pwmA, &pwmB, &pwmC);

    // 设定 PWM
    pwm_set_duty(LA_PWM, pwmA);
    pwm_set_duty(LB_PWM, pwmB);
    pwm_set_duty(LC_PWM, pwmC);

    // 更新角度 theta (开环运行)
    theta += speed;
    if (theta >= 2.0f * PI) {
        theta -= 2.0f * PI;
    }
    system_delay_us(Step_Delay);
}



void Play_Welcome(void) {
    // Maxwell The Cat 音符频率 (Hz)
    uint32_t melody[] = {
            1000, 2000, 3000,
    };

    // 每个音符的持续时间 (ms)
    uint32_t note_durations[] = {
        300, 300, 300,
    };

    uint8_t notes = sizeof(melody)/sizeof(melody[0]);

    for (uint8_t i = 0; i < notes; i++) {
        // 动态占空比增强节奏感

        pwm_set_freq(LA_PWM, melody[i], 6000);
        pwm_set_freq(LB_PWM, melody[i], 6000);
        pwm_set_freq(LC_PWM, melody[i], 6000);
        // 精确节奏控制（包含音符间的静音间隔）
        system_delay_ms(note_durations[i]);       // 提前结束制造停顿感
    }
        pwm_set_freq(LA_PWM, FOC_PWM_FREC, 0);
        pwm_set_freq(LB_PWM, FOC_PWM_FREC, 0);
        pwm_set_freq(LC_PWM, FOC_PWM_FREC, 0);
}




void Duty_Set(float A_DUTY,float B_DUTY,float C_DUTY)
{
    if(A_DUTY>=10000)A_DUTY=9999;
    if(B_DUTY>=10000)B_DUTY=9999;
    if(C_DUTY>=10000)C_DUTY=9999;
    if(A_DUTY<=0)A_DUTY=1;
    if(B_DUTY<=0)B_DUTY=1;
    if(C_DUTY<=0)C_DUTY=1;
    pwm_set_duty(LA_PWM, A_DUTY);
    pwm_set_duty(LB_PWM, B_DUTY);
    pwm_set_duty(LC_PWM, C_DUTY);
}














