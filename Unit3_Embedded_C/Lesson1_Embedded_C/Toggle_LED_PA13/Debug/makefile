################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Lab1_Toggle_LED_PA13
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Lab1_Toggle_LED_PA13.elf \

MAP_FILES += \
Lab1_Toggle_LED_PA13.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Lab1_Toggle_LED_PA13.list \

OBJCOPY_HEX += \
Lab1_Toggle_LED_PA13.hex \

OBJCOPY_BIN += \
Lab1_Toggle_LED_PA13.bin \


# All Target
all: main-build

# Main-build Target
main-build: Lab1_Toggle_LED_PA13.elf secondary-outputs

# Tool invocations
Lab1_Toggle_LED_PA13.elf Lab1_Toggle_LED_PA13.map: $(OBJS) $(USER_OBJS) E:\Embedded\STM32CubeIDE\workspace_1.12.0\test\STM32F103C6TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Lab1_Toggle_LED_PA13.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"E:\Embedded\STM32CubeIDE\workspace_1.12.0\test\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Lab1_Toggle_LED_PA13.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Lab1_Toggle_LED_PA13.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Lab1_Toggle_LED_PA13.list"
	@echo 'Finished building: $@'
	@echo ' '

Lab1_Toggle_LED_PA13.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "Lab1_Toggle_LED_PA13.hex"
	@echo 'Finished building: $@'
	@echo ' '

Lab1_Toggle_LED_PA13.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Lab1_Toggle_LED_PA13.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Lab1_Toggle_LED_PA13.bin Lab1_Toggle_LED_PA13.elf Lab1_Toggle_LED_PA13.hex Lab1_Toggle_LED_PA13.list Lab1_Toggle_LED_PA13.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
