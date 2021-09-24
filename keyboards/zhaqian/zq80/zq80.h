#ifndef ZQ80_H
#define ZQ80_H

#include "quantum.h"

#define LAYOUT( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K313,       \
	K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410,       K412, K413,       \
	K500, K501, K502,             K505,                   K509, K510,       K512, K513, K514  \
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  K013,  K014 }, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113,  K114 }, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  K213,  K214 }, \
	{ K300,  K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  KC_NO, K313,  KC_NO }, \
	{ K400,  K401,  K402,  K403,  K404,  K405,  K406,  K407,  K408,  K409,  K410,  KC_NO, K412,  K413,  KC_NO }, \
	{ K500,  K501,  K502,  KC_NO, KC_NO, K505,  KC_NO, KC_NO, KC_NO, K509,  K510,  KC_NO, K512,  K513,  K514 }  \
}

//custom keycodes
enum custom_keycodes {
#ifdef RGB_MATRIX_CONTROL_ENABLE
#ifdef VIA_ENABLE
	UGLRGBTog = USER00,		//rgb toggle for underglow rgb light
#else
    UGLRGBTog = SAFE_RANGE,
#endif
	KBLRGBTog,				//rgb toggle for key rgb backlight
#ifdef LOGO_RGB_MATRIX_CONTROL_ENABLE
    LOGORGBTog,             //rgb toggle for logo light
#endif
#endif
#ifdef UNDERGLOW_RGB_MATRIX_ENABLE
    LGUGRGBMODF,           //logo rgblight and underglow rgblight mode+
    LGUGRGBMODR,           //logo rgblight and underglow rgblight mode-
#endif
};


#endif
