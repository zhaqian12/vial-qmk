# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no     # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no      # Mouse keys
EXTRAKEY_ENABLE = no       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no         # USB Nkey Rollover
NO_USB_STARTUP_CHECK =  no	# Disable initialization only when usb is plugged in

MCU = STM32F411

CUSTOM_MATRIX = lite    # for using the A9 pin as matrix io
QUANTUM_SRC += matrix.c

# Bootloader selection
BOOTLOADER = tinyuf2


# Address of the bootloader in system memory
STM32_BOOTLOADER_ADDRESS = 0x1FFF0000
# Bootloader selection

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
WS2812_DRIVER = pwm

ENCODER_ENABLE = yes

RGB_MATRIX_CUSTOM_KB = yes
RGB_MATRIX_CONTROL_ENABLE = yes
UNDERGLOW_RGB_MATRIX_ENABLE = yes
ENCODER_TRIGGER_ENABLE = yes
WPM_ENABLE = no
VELOCIKEY_ENABLE = no
TAP_DANCE_ENABLE = no
ALT_TAB_MARCO_ENABLE = yes

