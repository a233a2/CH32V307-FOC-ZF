#ifndef _OTHERS_H_
#define _OTHERS_H_

/* System Setting */
#define Fs 20000        // TIM1 Ƶ�� (��FOC����Ƶ��)(��λ: Hz)
#define Fs_speed  Fs/10 //TIM4 Ƶ�ʣ���������(��λ: Hz)
#define Im    20        // �����޷�(��λ: A)
#define Istop Im+10     // �������� ǿ�ƹض�(��λ: A)
#define Vm 300          // �ٶ��޷�(��λ: rpsתÿ��)
#define Pole_Pairs 7    // ���������
#define MODE  3         // 0:�ٶ�ģʽ, 1:λ��ģʽ


// ʹ�õ� PI �ͼ��������ɸ����������      AS5600��
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
