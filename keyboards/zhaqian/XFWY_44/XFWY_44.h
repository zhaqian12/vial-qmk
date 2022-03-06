#ifndef XFWY_44_H
#define XFWY_44_H

#include "quantum.h"

#define LAYOUT( \
	K00, K01, K02, K03, K04, K05, K06, \
	K10, K11, K12, K13, K14, K15, K16, \
	K20,      K22, K23, K24,      K26, \
	K30, K31, K32, K33, K34, K35, K36, \
	K40, K41, K42, K43, K44, K45, K46, \
	K50,      K52, K53, K54, K55, K56, \
	K60,      K62, K63, K64,      K66  \
) { \
	{ K00,   K01,   K02,   K03,   K04,   K05,   K06 }, \
	{ K10,   K11,   K12,   K13,   K14,   K15,   K16 }, \
	{ K20,   KC_NO, K22,   K23,   K24,   KC_NO, K26 }, \
	{ K30,   K31,   K32,   K33,   K34,   K35,   K36 }, \
	{ K40,   K41,   K42,   K43,   K44,   K45,   K46 }, \
	{ K50,   KC_NO, K52,   K53,   K54,   K55,   K56 }, \
	{ K60,   KC_NO, K62,   K63,   K64,   KC_NO, K66 }  \
}

#endif