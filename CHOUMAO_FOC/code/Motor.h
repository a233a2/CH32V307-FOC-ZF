
#define LA_PWM  TIM1_PWM_MAP3_CH1_E9   // 对应 LA (PE9)
#define LB_PWM  TIM1_PWM_MAP3_CH2_E11   // 对应 LB (PE11)
#define LC_PWM  TIM1_PWM_MAP3_CH3_E13   // 对应 LC (PE13)
extern uint16 pwmA;
extern uint16 pwmB;
extern uint16 pwmC;
void DRV8301_Init(void);


void OpenLoopFOC(void);
void Motor_Step_Sequence(void);

void Play_Welcome(void);

void Duty_Set(float A_DUTY,float B_DUTY,float C_DUTY);


