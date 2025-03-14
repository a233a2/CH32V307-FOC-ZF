#include "AS5600.h"
#include "ch32v30x_gpio.h"   // 根据实际使用的库头文件进行修改
#include "ch32v30x_rcc.h"    // 同上
#include "zf_common_headfile.h"
/*
 * 这里假设使用了与 STM32 类似的 GPIO 库函数:
 *   - GPIO_InitTypeDef 结构体用于引脚初始化
 *   - RCC_APB2PeriphClockCmd() 打开 GPIO 时钟
 *   - GPIO_Init() 初始化 GPIO
 *   - GPIO_SetBits() / GPIO_ResetBits() 设置引脚为高或低
 *   - GPIO_ReadInputDataBit() 读取引脚电平
 *
 * 请根据你的实际 CH32V307 平台库函数或寄存器操作来替换 / 修改。
 */

/* ------------------ 引脚宏定义，可根据需要作调整 ------------------ */
#define SCL_PORT    GPIOD
#define SCL_PIN     GPIO_Pin_1

#define SDA_PORT    GPIOD
#define SDA_PIN     GPIO_Pin_0

/* 用于“读 SDA 引脚” */
#define SDA_READ()  GPIO_ReadInputDataBit(SDA_PORT, SDA_PIN)

/* 置 SCL/SDA 高或低 */
#define SCL_H()     GPIO_SetBits(SCL_PORT, SCL_PIN)
#define SCL_L()     GPIO_ResetBits(SCL_PORT, SCL_PIN)
#define SDA_H()     GPIO_SetBits(SDA_PORT, SDA_PIN)
#define SDA_L()     GPIO_ResetBits(SDA_PORT, SDA_PIN)

/* 软件延时：可根据所需速率进行调整 */
static void SoftI2C_Delay(void)
{
    volatile uint16_t i = 30;  // 调大或调小以调节 I2C 速度
    while(i--) {
        __asm("nop");
    }
}

/* 设置 SDA 为输入模式 */
static void SDA_IN(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = SDA_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; // 浮空输入
    GPIO_Init(SDA_PORT, &GPIO_InitStructure);
}

/* 设置 SDA 为输出模式 */
static void SDA_OUT(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = SDA_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // 推挽输出
    GPIO_Init(SDA_PORT, &GPIO_InitStructure);
}

/* 软件 I2C 初始化：配置 PD0、PD1 */
void SoftI2C_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /* 开启 GPIOD 时钟 */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    /* 配置 SCL(PD1) 为推挽输出 */
    GPIO_InitStructure.GPIO_Pin = SCL_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(SCL_PORT, &GPIO_InitStructure);

    /* 初始状态拉高 SCL */
    SCL_H();

    /* 配置 SDA(PD0) 为推挽输出（空闲时拉高） */
    SDA_OUT();
    SDA_H();
}

/* 发送 I2C 起始信号 */
static void SoftI2C_Start(void)
{
    SDA_OUT();
    SDA_H();
    SCL_H();
    SoftI2C_Delay();
    // 当 SCL 和 SDA 都为高时，再拉 SDA 低
    SDA_L();
    SoftI2C_Delay();
    SCL_L();
    SoftI2C_Delay();
}

/* 发送 I2C 停止信号 */
static void SoftI2C_Stop(void)
{
    SDA_OUT();
    SCL_L();
    SDA_L();
    SoftI2C_Delay();
    SCL_H();
    SoftI2C_Delay();
    SDA_H();
    SoftI2C_Delay();
}

/* 等待应答信号 */
static uint8_t SoftI2C_WaitAck(void)
{
    uint8_t ucErrTime = 0;

    SDA_IN(); // SDA 切换为输入，用于读取从机应答
    SDA_H();  // 先释放 SDA
    SoftI2C_Delay();
    SCL_H();
    SoftI2C_Delay();

    while(SDA_READ())
    {
        ucErrTime++;
        if(ucErrTime > 200)
        {
            SoftI2C_Stop();
            return 1; // 无应答
        }
    }
    SCL_L();
    return 0; // 正常应答
}

/* 产生 ACK 或 NACK 信号 */
static void SoftI2C_SendAck(uint8_t ack)
{
    SCL_L();
    SDA_OUT();
    if(ack) {
        // 发送 NACK
        SDA_H();
    } else {
        // 发送 ACK
        SDA_L();
    }
    SoftI2C_Delay();
    SCL_H();
    SoftI2C_Delay();
    SCL_L();
}

/* 发送一个字节 */
static void SoftI2C_SendByte(uint8_t txd)
{
    uint8_t i;
    SDA_OUT();
    for(i = 0; i < 8; i++)
    {
        SCL_L();
        SoftI2C_Delay();
        if(txd & 0x80)
            SDA_H();
        else
            SDA_L();
        txd <<= 1;
        SoftI2C_Delay();
        SCL_H();
        SoftI2C_Delay();
    }
    // 发送完 8 位后，释放 SDA
    SCL_L();
}

/* 接收一个字节 */
static uint8_t SoftI2C_ReadByte(uint8_t ack)
{
    uint8_t i, receive = 0;
    SDA_IN(); // 切换为输入
    for(i = 0; i < 8; i++)
    {
        SCL_L();
        SoftI2C_Delay();
        SCL_H();
        receive <<= 1;
        if(SDA_READ()) {
            receive++;
        }
        SoftI2C_Delay();
    }
    // 发送 ACK 或 NACK
    SoftI2C_SendAck(ack);

    return receive;
}

/**
 * @brief  通过软件 I2C 向寄存器写入一个字节
 * @param  devAddr:  7位设备地址
 * @param  regAddr:  寄存器地址
 * @param  data:     要写入的一个字节数据
 * @retval 0 表示成功，非0 表示失败
 * 如果你后续需要写配置（例如设置零点寄存器、方向寄存器等），就可以直接调用 SoftI2C_WriteOneByte。
 * 否则，如果你确实不需要往 AS5600 的寄存器写数据，也可以删除这个函数，或者暂时保留以备将来使用。
 */
/*
static uint8_t SoftI2C_WriteOneByte(uint8_t devAddr, uint8_t regAddr, uint8_t data)
{
    SoftI2C_Start();
    // 发送器件写地址
    SoftI2C_SendByte((devAddr << 1) | 0);
    if(SoftI2C_WaitAck()) {
        SoftI2C_Stop();
        return 1;
    }
    // 发送寄存器地址
    SoftI2C_SendByte(regAddr);
    if(SoftI2C_WaitAck()) {
        SoftI2C_Stop();
        return 2;
    }
    // 发送要写入的数据
    SoftI2C_SendByte(data);
    if(SoftI2C_WaitAck()) {
        SoftI2C_Stop();
        return 3;
    }
    SoftI2C_Stop();
    return 0;
}
*/
/**
 * @brief  通过软件 I2C 从指定寄存器读取一个字节
 * @param  devAddr:  7位设备地址
 * @param  regAddr:  寄存器地址
 * @return 读到的数据
 */
static uint8_t SoftI2C_ReadOneByte(uint8_t devAddr, uint8_t regAddr)
{
    uint8_t temp;
    SoftI2C_Start();
    // 发送器件写地址
    SoftI2C_SendByte((devAddr << 1) | 0);
    SoftI2C_WaitAck();
    // 发送寄存器地址
    SoftI2C_SendByte(regAddr);
    SoftI2C_WaitAck();
    // 重新启动，发送器件读地址
    SoftI2C_Start();
    SoftI2C_SendByte((devAddr << 1) | 1);
    SoftI2C_WaitAck();
    // 读数据(最后一个字节发送NACK)
    temp = SoftI2C_ReadByte(1);
    SoftI2C_Stop();
    return temp;
}

/**
 * @brief  读取 AS5600 的“编程后角度”（ANGLE 寄存器 0x0E/0x0F）
 *         该寄存器输出 0~4095 (12-bit) 的角度值
 * @return 返回角度，0~4095
 */
uint16_t AS5600_GetAngle(void)
{
    uint8_t high, low;
    // 读取高、低字节
    high = SoftI2C_ReadOneByte(AS5600_I2C_ADDR, AS5600_REG_ANGLE_H);
    low  = SoftI2C_ReadOneByte(AS5600_I2C_ADDR, AS5600_REG_ANGLE_L);

    // 12 位数据，高字节低 4 位 + 低字节 8 位
    // AS5600 寄存器手册中：高字节只有低 4 位有效
    uint16_t angle = ((high & 0x0F) << 8) | low;

    return angle;
}


float Ele_rad = 0;
float angle_360 = 0;
float Distance = 0;
/**
 * @brief  每次调用，读取 AS5600 编码器值并计算:
 *         1) 机械角度 angle_360 (0~360度)
 *         2) 电角度 Ele_rad (0 ~ 2π * POLE_PAIRS)
 *         3) Distance 记录累计转过的机械角度(可正可负)，自动处理过零跳变
 * @param  Distance : 累计旋转角度(度)，由本函数更新
 * @param  angle_360: 当前 0~360 度
 * @param  Ele_rad  : 电角度(弧度)
 * AS5600_UpdateAngle(Distance, angle_360, Ele_rad);
 */
void AS5600_UpdateAngle(float *Distance, float *angle_360, float *Ele_rad)
{
    // 静态变量用于保存上一次的机械角度(单位:度)
    // 以便下次计算增量和处理过零
    static float old_angle_360 = 0.0f;
    static uint8_t first_run = 1; // 标识第一次读取，避免错误的跳变补偿

    // 1. 读取 AS5600 原始值(0~4095)
    uint16_t raw = AS5600_GetAngle();

    // 2. 转化到 0~360 度
    float new_angle_360 = (float)raw * (360.0f / 4096.0f);
    // 说明: 4096 = 2^12

    // 3. 若不是第一次调用，进行过零点跳跃补偿
    if(!first_run)
    {
        float delta = new_angle_360 - old_angle_360;

        // 若从 359度跳到0度，会产生 +(-359) 左右的错误
        // 一般认为大于 +180, 就是逆向越过零点
        // 小于 -180, 就是正向越过零点
        if(delta > 180.0f)      // 可能出现 359 -> 0
        {
            delta -= 360.0f;
        }
        else if(delta < -180.0f) // 可能出现 0 -> 359
        {
            delta += 360.0f;
        }

        // 将此次变化量加入到 Distance
        *Distance += delta;
    }
    else
    {
        // 第一次运行，不做差值累计，防止出现随机跳变
        *Distance = 0.0f;
        first_run = 0;
    }

    // 更新上一次角度
    old_angle_360 = new_angle_360;

    // 输出当前机械角度(0~360)
    *angle_360 = new_angle_360;

    // 4. 计算电角度 Ele_rad
    // 常规公式: 机械角度(度) / 360度 * 2π * (极对数)
    // 不过你给出的公式略简化: angle_360 / 360 * π * 7
    // 如果你需要完整 2π，请自行修改
    *Ele_rad = (*angle_360 / 360.0f) * MY_PI * POLE_PAIRS;
}






