#include "zf_common_headfile.h"
#include "others.h"

void ERROR_REPORT_INIT(void)
{
    gpio_init(FAULT, GPI, 0, GPO_PUSH_PULL);
    gpio_init(NOCTW, GPI, 0, GPO_PUSH_PULL);
    gpio_init(PWGRD, GPI, 0, GPO_PUSH_PULL);
}


void ERROR_REPORT(void)
{
    if(FAULT==1)
    {

    }
}





void LED_init(void)
{
    // ��ʼ��GPIO E2 E9Ϊ������� Ĭ������͵�ƽ
    gpio_init(LED1_PIN, GPO, 0, GPO_PUSH_PULL);
    gpio_init(LED2_PIN, GPO, 0, GPO_PUSH_PULL);
}


void KEY_init(void)
{
    gpio_init(my_KEY_1, GPO, 0, GPO_PUSH_PULL);
    gpio_init(my_KEY_2, GPO, 0, GPO_PUSH_PULL);
}


uint8_t Key_Scan(void)
{
    // ��� KEY0
    if (gpio_get_level(my_KEY_1) == 0)  // ��һ�μ�⵽����
    {
        // ��ȥ��
        system_delay_ms(10);
        if (gpio_get_level(my_KEY_1) == 0) // ȷ�ϰ�����Ȼ����
        {
            // �ȴ��ɿ�����ֹ�ظ�����
            while (gpio_get_level(my_KEY_1) == 0)
            {
                // ����������Ӹ���ʱ����Щ������
            }
            return 1;  // KEY0
        }
    }

    // ��� KEY1
    if (gpio_get_level(my_KEY_2) == 1)
    {
        // ��ȥ��
        system_delay_ms(10);
        if (gpio_get_level(my_KEY_2) == 0)
        {
            // �ȴ��ɿ�
            while (gpio_get_level(my_KEY_2) == 0)
            {
                // ����������Ӹ���ʱ����Щ������
            }
            return 2;  // KEY1
        }
    }

    // û���κΰ�������
    return 0;
}































