#ifndef __AS5600_H
#define __AS5600_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

//************* 用户可根据实际硬件情况进行调整 ******************//
#define AS5600_I2C_ADDR      0x36  // AS5600 器件 7bit 地址: 0x36 (写时0x6C, 读时0x6D)

// 定义与 AS5600 相关的寄存器
#define AS5600_REG_ANGLE_H   0x0E  // 编程后角度高字节
#define AS5600_REG_ANGLE_L   0x0F  // 编程后角度低字节

//******************** 函数声明 *******************************//

/**
 * @brief  软件 I2C 引脚初始化（PD1 -> SCL, PD0 -> SDA）。
 */
void AS5600_Init(void);



float GetAngle(void);
float GetAngle_NoTrack(void);
float GetVelocity(void);



/**
 * @brief  读取 AS5600 的角度（0~4095），单位为 12 位。
 * @return 12位的角度值，范围 0 ~ 4095。
 */
uint16_t AS5600_GetAngle(void);

extern float Ele_rad;
extern float angle_360;
extern float Distance;
/**
 * @brief 每次调用该函数，都会读取当前 AS5600 角度，更新：
 *        1) Distance：累计机械转动量(度数)
 *        2) angle_360：当前机械角度(0~360度)
 *        3) Ele_rad：当前电角度(弧度)
 */
void AS5600_UpdateAngle(float *Distance, float *angle_360, float *Ele_rad);


#ifdef __cplusplus
}
#endif

#endif // __AS5600_SOFT_I2C_H
