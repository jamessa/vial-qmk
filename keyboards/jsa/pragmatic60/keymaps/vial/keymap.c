/* Copyright 2021 James Sa
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

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// Defines names for use in layer keycodes and the keymap
// enum layer_names {
//     _QWERTY,
// };

// Defines the keycodes used by our macros in process_record_user
// enum custom_keycodes {
//     COLEMAK = SAFE_RANGE,   // colemak without home row modifier
//     COLEMAKm,               // colemak with home row modifier
//     DVORAK,
//     QWERTY
// };

#define _C(X) CTL_T(X)
#define _A(X) ALT_T(X)
#define _S(X) SFT_T(X)
#define _G(X) CMD_T(X)
#define FNBSPC LT(_FN, KC_BSPC)
#define PNSPC  LT(_PN, KC_SPC)
// macOS shortcut
#define MSNCTL  C(KC_UP)
#define WKSPLF  C(KC_LEFT)
#define WKSPRT  C(KC_RGHT)
#define COPY    G(KC_C)
#define PSTE    G(KC_V)
#define CUT     G(KC_X)
#define UNDO    G(KC_Z)
#define REDO    G(S(KC_Z))
#define SCNSHOT S(G(KC_4))
#define SPOTLT  G(KC_SPC)
// window management utility
#define DIVVY   KC_F13

#define ZOOMIN  G(KC_PPLS)  // command +
#define ZOOMOUT G(KC_PMNS)  // command -
#define ACTUAL  G(KC_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
        KC_LALT, KC_LCTL, KC_LALT, KC_LGUI, LT(3,KC_CAPS), LT(1,KC_BSPC), LT(2,KC_SPC), LT(4,KC_ENT),  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
        _______, KC_ESC,  SCNSHOT, DIVVY,   SPOTLT,  _______, KC_PPLS, KC_P7,   KC_P8,   KC_P9,   KC_PERC, _______,
        _______, KC_TAB,  CUT,     COPY,    PSTE,    KC_ENT,  KC_MINS, KC_P4,   KC_P5,   KC_P6,   KC_PAST, _______,
        _______, _______, WKSPLF,  MSNCTL,  WKSPRT,  KC_SPC,  KC_DLR,  KC_P1,   KC_P2,   KC_P3,   KC_PSLS, _______,
        _______, _______, _______, _______, _______, XXXXXXX, KC_P0,   KC_PDOT, _______, _______, _______, _______
    ),
    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_CIRC, KC_GRV,  KC_TILD, KC_LCBR, KC_RCBR, KC_TAB,  KC_PGUP, KC_UP,   _______, _______, _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_LPRN, KC_RPRN, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______,
        _______, KC_BSLS, KC_AMPR, KC_PIPE, KC_LBRC, KC_RBRC, KC_CAPS, KC_PGDN, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, KC_DEL,  XXXXXXX, _______, _______, _______, _______, _______
    ),
    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RESET,   _______, _______, _______, _______, _______, KC_VOLU, KC_BRIU, ZOOMIN,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_BRID, ZOOMOUT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, ACTUAL,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______
    )
};
