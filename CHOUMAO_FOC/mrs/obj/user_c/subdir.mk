################################################################################
# MRS Version: 1.9.2
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/CHOUMAO_FOC/user/src/isr.c \
D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/CHOUMAO_FOC/user/src/main.c 

OBJS += \
./user_c/isr.o \
./user_c/main.o 

C_DEPS += \
./user_c/isr.d \
./user_c/main.d 


# Each subdirectory must supply rules for building sources it contributes
user_c/isr.o: D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/CHOUMAO_FOC/user/src/isr.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\Libraries\doc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_components" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Core" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Ld" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Startup" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\user\inc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_common" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_device" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\code" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
user_c/main.o: D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/CHOUMAO_FOC/user/src/main.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\Libraries\doc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_components" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Core" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Ld" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Startup" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\user\inc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_common" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_device" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\code" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

