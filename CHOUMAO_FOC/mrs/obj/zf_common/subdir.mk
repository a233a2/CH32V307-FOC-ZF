################################################################################
# MRS Version: 1.9.2
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/libraries/zf_common/zf_common_clock.c \
D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/libraries/zf_common/zf_common_debug.c \
D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/libraries/zf_common/zf_common_fifo.c \
D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/libraries/zf_common/zf_common_font.c \
D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/libraries/zf_common/zf_common_function.c \
D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/libraries/zf_common/zf_common_interrupt.c 

OBJS += \
./zf_common/zf_common_clock.o \
./zf_common/zf_common_debug.o \
./zf_common/zf_common_fifo.o \
./zf_common/zf_common_font.o \
./zf_common/zf_common_function.o \
./zf_common/zf_common_interrupt.o 

C_DEPS += \
./zf_common/zf_common_clock.d \
./zf_common/zf_common_debug.d \
./zf_common/zf_common_fifo.d \
./zf_common/zf_common_font.d \
./zf_common/zf_common_function.d \
./zf_common/zf_common_interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
zf_common/zf_common_clock.o: D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/libraries/zf_common/zf_common_clock.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\Libraries\doc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_components" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Core" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Ld" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Startup" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\user\inc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_common" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_device" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\code" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_debug.o: D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/libraries/zf_common/zf_common_debug.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\Libraries\doc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_components" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Core" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Ld" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Startup" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\user\inc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_common" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_device" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\code" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_fifo.o: D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/libraries/zf_common/zf_common_fifo.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\Libraries\doc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_components" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Core" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Ld" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Startup" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\user\inc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_common" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_device" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\code" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_font.o: D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/libraries/zf_common/zf_common_font.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\Libraries\doc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_components" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Core" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Ld" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Startup" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\user\inc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_common" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_device" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\code" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_function.o: D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/libraries/zf_common/zf_common_function.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\Libraries\doc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_components" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Core" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Ld" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Startup" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\user\inc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_common" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_device" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\code" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_interrupt.o: D:/DESKTOP/CH32-FOC/CHV307_Library-master/Example/libraries/zf_common/zf_common_interrupt.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\Libraries\doc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_components" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Core" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Ld" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Peripheral" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\sdk\Startup" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\user\inc" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_common" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_device" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\CHOUMAO_FOC\code" -I"D:\DESKTOP\CH32-FOC\CHV307_Library-master\Example\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

