/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define DIODE_DIRECTION COL2ROW
// wiring of each half
#define MATRIX_ROW_PINS { B1, B2, C7, B4, D7, B0 }
#define MATRIX_COL_PINS { F4, NO_PIN, F0, B7, B3, D2, D3, D5, D4, NO_PIN }
#define MATRIX_ROW_PINS_RIGHT { B3, B2, B6, B4, D7, B0 }
#define MATRIX_COL_PINS_RIGHT { F1, F0, F4, F5, F6, D5, D2, D3, B7, B1 }
#define SPLIT_HAND_PIN F7

#define CAPS_LOCK_LED_PIN B6

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN E6
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #define RGBLIGHT_EFFECT_KNIGHT
// #define RGBLIGHT_EFFECT_CHRISTMAS
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #define RGBLIGHT_EFFECT_RGB_TEST
// #define RGBLIGHT_EFFECT_ALTERNATING
// #define RGBLIGHT_EFFECT_TWINKLE
#define RGBLED_NUM 16    // Number of LEDs
#define RGBLED_SPLIT { 8, 8 }
#define RGBLIGHT_LED_MAP { 1, 2, 3, 12, 13, 14, 15, 0, 7, 6, 5, 4, 11, 10, 9, 8 }

#define BOOTMAGIC_LITE_ROW_RIGHT 10
#define BOOTMAGIC_LITE_COLUMN_RIGHT 9
#define BOOTMAGIC_LITE_ROW_LEFT 4
#define BOOTMAGIC_LITE_COLUMN_LEFT  0
#define DEBOUNCE 10
#define SPLIT_VELOCIKEY_ENABLE