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

#include <assert.h>

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
#define ZOOMIN  G(KC_PPLS)  // command +
#define ZOOMOUT G(KC_PMNS)  // command -
#define ACTUAL  G(KC_0)
// window management utility
#define DIVVY   KC_F13

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
     [0] = LAYOUT(
           KC_Q,    KC_W,    KC_F,    KC_P,   KC_B,         KC_J,    KC_L,    KC_U,       KC_Y,    KC_SCLN,
           KC_A,    KC_R,    KC_S,    KC_T,   KC_G,         KC_M,    KC_N,    KC_E,       KC_I,    KC_O,
        _A(KC_Z),_C(KC_X),_S(KC_C),_G(KC_D),  KC_V,         KC_K, _G(KC_H),_S(KC_COMM),_C(KC_DOT),_A(KC_SLSH),
                          LT(3,KC_CAPS), LT(1,KC_BSPC),LT(2,KC_SPC), LT(4,KC_ENT)
    ),
    [1] = LAYOUT(
        KC_ESC,  SCNSHOT, DIVVY,   SPOTLT,  _______, KC_PPLS, KC_P7,   KC_P8,   KC_P9,   KC_PERC,
        KC_TAB,  CUT,     COPY,    PSTE,    KC_ENT,  KC_MINS, KC_P4,   KC_P5,   KC_P6,   KC_PAST,
        _______, WKSPLF,  MSNCTL,  WKSPRT,  KC_SPC,  KC_DLR,  KC_P1,   KC_P2,   KC_P3,   KC_PSLS,
                                   _______, XXXXXXX, KC_P0,   KC_PDOT
    ),
    [2] = LAYOUT(
        KC_CIRC, KC_GRV,  KC_TILD, KC_LCBR, KC_RCBR, KC_TAB,  KC_PGUP, KC_UP,   _______, _______,
        KC_EXLM, KC_AT,   KC_HASH, KC_LPRN, KC_RPRN, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
        KC_BSLS, KC_AMPR, KC_PIPE, KC_LBRC, KC_RBRC, KC_CAPS, KC_PGDN, _______, _______, _______,
                                   _______, KC_DEL,  XXXXXXX, _______
    ),
    [3] = LAYOUT(
        _______, _______, _______, _______, _______, KC_PPLS, _______, _______, _______, _______,
        _______, _______, REDO,    UNDO,    _______, KC_MINS, KC_PEQL, KC_DQUO, KC_QUOT, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_LABK, KC_RABK, _______,
                                   XXXXXXX, _______, KC_UNDS, _______
    ),
    [4] = LAYOUT(
       RESET,   _______, _______, _______, _______, _______, KC_BRIU, KC_VOLU, ZOOMIN,  _______,
       _______, _______, _______, _______, _______, _______, KC_BRID, KC_VOLD, ZOOMOUT, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, ACTUAL,  _______,
                                  _______, _______, _______, XXXXXXX
    ),
    [5] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______
    ),
    [6] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______
    ),
    [7] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______
    )
};

#ifdef OLED_ENABLE
bool caps_lock = false;
char layer_indicator[]="--------";
uint8_t prev_layer = DYNAMIC_KEYMAP_LAYER_COUNT;    // init with max layers

bool oled_task_user(void) {
    assert(oled_max_chars()==10);
    assert(oled_max_lines()==2);

    // render caps lock indicator
    if(caps_lock){
        oled_write("CAPS LOCK", false);
    }else{
        oled_write("PRAGMATIC", false);
    }

    oled_set_cursor(0, 2);

    // render layer indicator
    uint8_t layer = get_highest_layer(layer_state);
    if(layer == prev_layer) return false; // no change, just return
    prev_layer=layer;
    if(layer==0){
        oled_write("-= 34 =-", false);
    } else {
        layer_indicator[layer]=layer+48;
        oled_write(layer_indicator, false);
        layer_indicator[layer]='-'; // reset indicator
    }

    return false;
}

bool led_update_user(led_t led_state){

    caps_lock = led_state.caps_lock;
    return true;
}
#endif // OLED_ENABLE

