#include "zq75v2.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {  //
    {
        {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, NO_LED},
        {28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14},
        {43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29},
        {56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, NO_LED, NO_LED},
        {69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, NO_LED, NO_LED},
        {80, 79, 78, 77, NO_LED, 76, NO_LED, 75, NO_LED, 74, 73, 72, 71, NO_LED, 70},
    },{
        {195, 9}, {178,9}, {164, 9}, {150, 9}, {136, 9}, {119, 9}, {105, 9}, {91, 9}, {77, 9}, {59, 9}, {45, 9}, {31, 9}, {17, 9}, {0, 9},
        {212, 18}, {188, 18}, {168, 18}, {154, 18}, {140, 18}, {126, 18}, {112, 18}, {98, 18}, {84, 18}, {70, 18}, {56, 18}, {42, 18}, {28, 18}, {14, 18}, {0, 18},
        {212, 27}, {192, 27}, {175, 27}, {161, 27}, {147, 27}, {133, 27}, {119, 27}, {105, 27}, {91, 27}, {77, 27}, {63, 27}, {49, 27}, {35, 27}, {21, 27}, {3, 27},
        {186, 36}, {164, 36}, {150, 36}, {136, 36}, {122, 36}, {108, 36}, {94, 36}, {80, 36}, {66, 36}, {52, 36}, {38, 36}, {24, 36}, {5, 36},
        {199, 48}, {177, 45}, {158, 45}, {144, 45}, {130, 45}, {116, 45}, {102, 45}, {88, 45}, {74, 45}, {59, 45}, {45, 45}, {31, 45}, {9, 45},
        {212, 57}, {199, 57}, {184, 57}, {160, 54}, {144, 54}, {117, 54}, {89, 54}, {61, 54}, {34, 54}, {18, 54}, {2, 54},
        {8, 64}, {26, 64}, {39, 64}, {64, 64}, {96, 64}, {126, 64}, {160, 64}, {185, 64}, {221, 64},
        {221, 0}, {185, 0}, {160, 0}, {126, 0}, {96, 0}, {64, 0}, {39, 0}, {26, 0}, {8, 0},
    },{
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1,
        2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2,
    }};

#endif

#ifdef RGB_DISABLE_WHEN_USB_SUSPENDED

void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}

#endif



#ifdef OLED_DRIVER_ENABLE
bool is_cat_anime_active = false;
bool anime_cleared = false;
#endif

void matrix_init_kb(void) {
#ifdef OLED_DRIVER_ENABLE
    is_cat_anime_active = eeprom_read_byte((uint8_t *)20);
#endif
    matrix_init_user();
}

void rgb_matrix_indicators_kb(void) {
// COLOR RED RGB VALUE
    HSV hsv = {0, 255, rgb_matrix_get_val()};
    RGB rgb = hsv_to_rgb(hsv);
// caps_lock indicator
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(56, rgb.r, rgb.g, rgb.b);
    } else {
        rgb_matrix_enable();
    }
//  layers indicators
    switch(biton32(layer_state)) {
        case 1: rgb_matrix_set_color(12, rgb.r, rgb.g, rgb.b); break;
        case 2: rgb_matrix_set_color(11, rgb.r, rgb.g, rgb.b); break;
        case 3: rgb_matrix_set_color(10, rgb.r, rgb.g, rgb.b); break;
        case 4: rgb_matrix_set_color(9, rgb.r, rgb.g, rgb.b); break;
        case 5: rgb_matrix_set_color(8, rgb.r, rgb.g, rgb.b); break;
        case 6: rgb_matrix_set_color(7, rgb.r, rgb.g, rgb.b); break;
        case 7: rgb_matrix_set_color(6, rgb.r, rgb.g, rgb.b); break;
        case 8: rgb_matrix_set_color(5, rgb.r, rgb.g, rgb.b); break;
        case 9: rgb_matrix_set_color(4, rgb.r, rgb.g, rgb.b); break;
        case 10: rgb_matrix_set_color(3, rgb.r, rgb.g, rgb.b); break;
        case 11: rgb_matrix_set_color(2, rgb.r, rgb.g, rgb.b); break;
        case 12: rgb_matrix_set_color(1, rgb.r, rgb.g, rgb.b); break;
        default: rgb_matrix_enable(); break;
    }
}

#if defined ENCODER_ENABLE && defined ENCODER_TRIGGER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (clockwise) {
		encoder_trigger_kb(
#ifdef VIA_ENABLE
            dynamic_keymap_get_keycode(biton32(layer_state), 3, 14),
#else
            1,
#endif
            (keypos_t){.row = 3, .col = 14});
    } else {
		encoder_trigger_kb(
#ifdef VIA_ENABLE
            dynamic_keymap_get_keycode(biton32(layer_state), 3, 13),
#else
            1,
#endif
            (keypos_t){.row = 3, .col = 13});
	}
	return true;
}
#endif

#ifdef OLED_DRIVER_ENABLE
void CatToggle(void) {
    anime_cleared = true;
    is_cat_anime_active = !is_cat_anime_active;
    eeprom_write_byte((uint8_t *)20, is_cat_anime_active);
}
#endif

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
#ifdef ALT_TAB_MARCO_ENABLE
        case ATR:
            if (record->event.pressed) {
                alt_tab_reverse();
            }
            return false;
        case ATF:
            if (record->event.pressed) {
                alt_tab_forward();
            }
            return false;
#endif
#ifdef RGB_MATRIX_CONTROL_ENABLE
        case UGLRGBTog:
            if (record->event.pressed) {
                underglow_rgb_toggle();
            }
            return false;
        case KBLRGBTog:
            if (record->event.pressed) {
                key_backlight_rgb_toggle();
            }
            return false;
#endif
#ifdef UNDERGLOW_RGB_MATRIX_ENABLE
        case UGLFIXEDRGBMODF:
            if (record->event.pressed) {
               underglow_rgb_mode_step();
            }
            return false;
#endif
#ifdef OLED_DRIVER_ENABLE
        case CATTOG:
			if (record->event.pressed) {
                CatToggle();
            }
            return false;
#endif
    }
    return process_record_user(keycode, record);
};


