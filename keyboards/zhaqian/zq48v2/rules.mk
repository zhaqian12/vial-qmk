# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = lite     # Virtual DIP switch configuration
KEYBOARD_SHARED_EP = no    # Free up some extra endpoints - needed if console+mouse+extra
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
NO_USB_STARTUP_CHECK =  no	# Disable initialization only when usb is plugged in

MCU = STM32F401
# Bootloader selection
BOOTLOADER = tinyuf2

# # project specific file
CUSTOM_MATRIX = lite    # for using the A9 pin as matrix io
QUANTUM_SRC += matrix.c

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
WS2812_DRIVER = pwm

OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

RGB_MATRIX_CUSTOM_KB = yes
RGB_MATRIX_CONTROL_ENABLE = yes
UNDERGLOW_RGB_MATRIX_ENABLE = yes
WPM_ENABLE = yes
VELOCIKEY_ENABLE = yes
TAP_DANCE_ENABLE = no

