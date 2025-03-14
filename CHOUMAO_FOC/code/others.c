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
    // 初始化GPIO E2 E9为推挽输出 默认输出低电平
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
    // 检测 KEY0
    if (gpio_get_level(my_KEY_1) == 0)  // 第一次检测到按下
    {
        // 简单去抖
        system_delay_ms(10);
        if (gpio_get_level(my_KEY_1) == 0) // 确认按键仍然按下
        {
            // 等待松开，防止重复触发
            while (gpio_get_level(my_KEY_1) == 0)
            {
                // 可以在这里加个延时或做些其他事
            }
            return 1;  // KEY0
        }
    }

    // 检测 KEY1
    if (gpio_get_level(my_KEY_2) == 1)
    {
        // 简单去抖
        system_delay_ms(10);
        if (gpio_get_level(my_KEY_2) == 0)
        {
            // 等待松开
            while (gpio_get_level(my_KEY_2) == 0)
            {
                // 可以在这里加个延时或做些其他事
            }
            return 2;  // KEY1
        }
    }

    // 没有任何按键按下
    return 0;
}































