#ifndef _OTHERS_H_
#define _OTHERS_H_

/* System Setting */
#define Fs 20000        // TIM1 频率 (即FOC计算频率)(单位: Hz)
#define Fs_speed  Fs/10 //TIM4 频率（编码器）(单位: Hz)
#define Im    20        // 电流限幅(单位: A)
#define Istop Im+10     // 过流保护 强制关断(单位: A)
#define Vm 300          // 速度限幅(单位: rps转每秒)
#define Pole_Pairs 7    // 电机极对数
#define MODE  3         // 0:速度模式, 1:位置模式


// 使用的 PI 和极对数，可根据需求调整      AS5600用
#define MY_PI       3.1415926f
#define POLE_PAIRS  7

#define AS5600_SCL (D1)
#define AS5600_SDA (D0)

#define FOC_PWM_FREC 15000


#define FAULT   (B7)
#define NOCTW   (C11)
#define PWGRD   (C12)
void ERROR_REPORT_INIT(void);


#define LED1_PIN        (E2)
#define LED2_PIN        (E3)
void LED_init(void);

#define my_KEY_1 (C2)
#define my_KEY_2 (C3)
void KEY_init(void);


#endif
