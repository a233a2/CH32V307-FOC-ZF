################################################################################
# MRS Version: 1.9.2
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/CHOUMAO_FOC/code/AS5600.c \
D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/CHOUMAO_FOC/code/FOC.c \
D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/CHOUMAO_FOC/code/Motor.c \
D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/CHOUMAO_FOC/code/fliter.c \
D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/CHOUMAO_FOC/code/others.c \
D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/CHOUMAO_FOC/code/pid_control.c \
D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/CHOUMAO_FOC/code/sensors.c \
D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/CHOUMAO_FOC/code/vofa.c 

OBJS += \
./code/AS5600.o \
./code/FOC.o \
./code/Motor.o \
./code/fliter.o \
./code/others.o \
./code/pid_control.o \
./code/sensors.o \
./code/vofa.o 

C_DEPS += \
./code/AS5600.d \
./code/FOC.d \
./code/Motor.d \
./code/fliter.d \
./code/others.d \
./code/pid_control.d \
./code/sensors.d \
./code/vofa.d 


# Each subdirectory must supply rules for building sources it contributes
code/AS5600.o: D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/CHOUMAO_FOC/code/AS5600.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\Libraries\doc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_components" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Core" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Ld" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Startup" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\user\inc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_common" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_device" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\code" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/FOC.o: D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/CHOUMAO_FOC/code/FOC.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\Libraries\doc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_components" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Core" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Ld" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Startup" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\user\inc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_common" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_device" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\code" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/Motor.o: D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/CHOUMAO_FOC/code/Motor.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\Libraries\doc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_components" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Core" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Ld" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Startup" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\user\inc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_common" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_device" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\code" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/fliter.o: D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/CHOUMAO_FOC/code/fliter.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\Libraries\doc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_components" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Core" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Ld" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Startup" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\user\inc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_common" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_device" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\code" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/others.o: D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/CHOUMAO_FOC/code/others.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\Libraries\doc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_components" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Core" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Ld" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Startup" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\user\inc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_common" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_device" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\code" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/pid_control.o: D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/CHOUMAO_FOC/code/pid_control.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\Libraries\doc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_components" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Core" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Ld" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Startup" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\user\inc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_common" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_device" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\code" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/sensors.o: D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/CHOUMAO_FOC/code/sensors.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\Libraries\doc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_components" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Core" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Ld" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Startup" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\user\inc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_common" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_device" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\code" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/vofa.o: D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/CHOUMAO_FOC/code/vofa.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\Libraries\doc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_components" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Core" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Ld" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Startup" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\user\inc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_common" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_device" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\code" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

