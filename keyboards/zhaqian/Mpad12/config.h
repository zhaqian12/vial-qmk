/* Copyright 2021 ZhaQian
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x00AA
#define PRODUCT_ID      0xAAAA
#define DEVICE_VER      0x0001
#define MANUFACTURER    ZhaQian
#define PRODUCT         Mpad12
#define DESCRIPTION     multifunction pad12

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 6

/* key matrix pins */
#define MATRIX_ROW_PINS { B7, D2, D3, D5 }
#define MATRIX_COL_PINS { B4, B5, B6, C6, C7 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#ifdef RGB_MATRIX_ENABLE
#define RGB_DI_PIN F6
#define RGBLED_NUM 18
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
#define RGB_DISABLE_WHEN_USB_SUSPENDED true
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
#define DISABLE_RGB_MATRIX_ALPHAS_MODS
#define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define DISABLE_RGB_MATRIX_BAND_SAT
#define DISABLE_RGB_MATRIX_BAND_VAL
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define DISABLE_RGB_MATRIX_DUAL_BEACON
#define DISABLE_RGB_MATRIX_RAINBOW_BEACON
#define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define DISABLE_RGB_MATRIX_RAINDROPS
#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define DISABLE_RGB_MATRIX_HUE_BREATHING
#define DISABLE_RGB_MATRIX_HUE_PENDULUM
#define DISABLE_RGB_MATRIX_HUE_WAVE
#define DISABLE_RGB_MATRIX_TYPING_HEATMAP
#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSSS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define DISABLE_RGB_MATRIX_SPLASH
#define DISABLE_RGB_MATRIX_MULTISPLASH
#define DISABLE_RGB_MATRIX_SOLID_SPLASH
#define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A {B1, B2}
#define ENCODERS_PAD_B {B0, B3}
#define ENCODER_RESOLUTIONS {4, 2}
#endif

#ifdef JOYSTICK_ENABLE
#define JOYSTICK_BUTTON_COUNT 0
#define JOYSTICK_AXES_COUNT 2
#endif

#ifdef OLED_DRIVER_ENABLE
#define OLED_BRIGHTNESS 100
#define OLED_TIMEOUT 60000
#define OLED_FONT_HEIGHT 8
#define OLED_FONT_WIDTH 6
#define OLED_FONT_H "../../zfont.c"
#endif

#ifdef VIAL_ENABLE
#define VIAL_KEYBOARD_UID {0x21, 0x22, 0xB9, 0x90, 0x43, 0x03, 0xAE, 0x7E}
#ifdef VIAL_ENCODERS_ENABLE
#define VIAL_ENCODER_KEYCODE_DELAY 10
#endif
#endif
#define DYNAMIC_KEYMAP_MACRO_COUNT 15
