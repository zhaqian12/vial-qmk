
#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x00AA
#define DEVICE_VER      0x0006
#define PRODUCT_ID  0xAA06
#define MANUFACTURER    zhaqian
#define PRODUCT         TEST12v3

// enable the nkro when using the VIA.
#define FORCE_NKRO

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 1


#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 4

/* key matrix pins */
#define MATRIX_ROWS 4
#define MATRIX_COLS 5

//                        0    1    2    3     4    5    6   7    8    9    10   11   12  13   14   15   16   17
#define MATRIX_COL_PINS { A9,  A8, B15, B14,  B13 }
#define MATRIX_ROW_PINS { A0,  C15,  C14, A7}

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* RGN Matrix */
#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN B5
#define RGBLED_NUM 16
#define DRIVER_LED_TOTAL RGBLED_NUM
#define WS2812_PWM_DRIVER PWMD3
#define WS2812_PWM_CHANNEL 2
#define WS2812_PWM_PAL_MODE 2
#define WS2812_DMA_STREAM STM32_DMA1_STREAM2
#define WS2812_DMA_CHANNEL 5
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_DISABLE_WHEN_USB_SUSPENDED true
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_CUSTOM_EFFECT_ANIMATION
#endif

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { B1 }
#define ENCODERS_PAD_B { B3}
#define ENCODER_RESOLUTIONS { 4 }
#endif

#ifdef UNDERGLOW_RGB_MATRIX_ENABLE
#define UG_RGB_MATRIX_ANIMATIONS
#define UG_RGB_MATRIX_WPM_ANIMATIONS
#endif

#ifdef VIAL_ENABLE
#define VIAL_KEYBOARD_UID {0xF5, 0x25, 0xE7, 0x19, 0x05, 0x2D, 0x41, 0xAF}
#ifdef VIAL_ENCODERS_ENABLE
#define VIAL_ENCODER_DEFAULT {KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU}
#define VIAL_ENCODER_KEYCODE_DELAY 10
#endif
#endif
#ifdef JOYSTICK_ENABLE
#define JOYSTICK_BUTTON_COUNT 0
#define JOYSTICK_AXES_COUNT 2
#endif
