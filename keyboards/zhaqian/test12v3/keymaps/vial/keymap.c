/* Copyright 2021 JasonRen(biu)
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
#include QMK_KEYBOARD_H
#include "joystick.h"
#include "analog.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC,
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC,
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC,
        KC_UP, KC_DOWN, KC_RIGHT, KC_LEFT),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),


};

#ifdef JOYSTICK_ENABLE

char arrow_keys[4] = {KC_UP, KC_LEFT, KC_DOWN, KC_RIGHT};
static int actuation = 256;
bool arrows[4];
joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
    [0] = JOYSTICK_AXIS_VIRTUAL,
    [1] = JOYSTICK_AXIS_VIRTUAL
};

#endif

void matrix_scan_user(void){
#ifdef JOYSTICK_ENABLE
    if (!arrows[0] && analogReadPin(A1) - 512 > actuation){
		arrows[0] = true;
		uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 3,0);
		register_code16(keycode);
    } else if (arrows[0] &&  analogReadPin(A1) - 512 < actuation){
    	arrows[0] = false;
        uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 3,0);
        unregister_code16(keycode);
    }
    if (!arrows[1] && analogReadPin(A1) - 512 < -actuation){
        arrows[1] = true;
        uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 3,1);
        register_code16(keycode);
    } else if (arrows[1] && analogReadPin(A1) - 512 > -actuation){
        arrows[1] = false;
        uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 3,1);
        unregister_code16(keycode);
    }
    if (!arrows[2] && analogReadPin(A2) - 512 > actuation){
    	arrows[2] = true;
        uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 3,2);
        register_code16(keycode);
    } else if (arrows[2] &&  analogReadPin(A2) - 512 < actuation){
        arrows[2] = false;
        uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 3,2);
        unregister_code16(keycode);
    }
    if (!arrows[3] && analogReadPin(A2) - 512 < -actuation){
        arrows[3] = true;
        uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 3,3);
        register_code16(keycode);
    } else if (arrows[3] && analogReadPin(A2) - 512 > -actuation){
        arrows[3] = false;
        int16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), 3,3);
        unregister_code16(keycode);
	}
#endif
}
