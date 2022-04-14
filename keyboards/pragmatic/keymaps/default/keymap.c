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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _COLEMAK_HOME_MOD,// colemak with home row modifier
    _COLEMAK,  // clean colema mod dhm
    _FN,
    _PN,
    _ADJUST,
    _TYPE,
    _MINECRAFT,
    _NAV
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    COLEMAK = SAFE_RANGE,   // colemak without home row modifier
    COLEMAKm,               // colemak with home row modifier
    DVORAK,
    QWERTY
};

#define _C(X) CTL_T(X)
#define _A(X) ALT_T(X)
#define _S(X) SFT_T(X)
#define _G(X) CMD_T(X)
#define FNBSPC  LT(_FN,     KC_BSPC)
#define PNSPC   LT(_PN,     KC_SPC)
#define ADJUST  LT(_ADJUST, KC_ENT)
#define NAV     LT(_NAV,    KC_CAPS)
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
    // [_COLEMAK_HOME_MOD] = LAYOUT(
    //     KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,KC_EQL,
    //     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,

    //     KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
    //     KC_TAB,_A(KC_A),_C(KC_R),_S(KC_S),_G(KC_T),  KC_G,    KC_M, _G(KC_N),_S(KC_E),_C(KC_I),_A(KC_O),   KC_QUOT,
    //     _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    //     /*                                  Lang     BSpace   Space    Enter                              */
    //     KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, NAV,     FNBSPC,  PNSPC,   ADJUST,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    // ),
    [_COLEMAK_HOME_MOD] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,KC_EQL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,

        KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,   KC_QUOT,
        _______,_A(KC_Z),_C(KC_X),_S(KC_C),_G(KC_D),  KC_V,   KC_K, _G(KC_H),_S(KC_COMM),_C(KC_DOT),_A(KC_SLSH),KC_RSFT,
        /*                                  Lang     BSpace   Space    Enter                              */
        KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, NAV,     FNBSPC,  PNSPC,   ADJUST,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    [_FN] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_ESC,  SCNSHOT, DIVVY,   SPOTLT,  _______, KC_PPLS, KC_P7,   KC_P8,   KC_P9,   KC_PERC, _______,
        _______, KC_TAB,  CUT,     COPY,    PSTE,    KC_ENT,  KC_MINS, KC_P4,   KC_P5,   KC_P6,   KC_PAST, _______,
        _______, _______, WKSPLF,  MSNCTL,  WKSPRT,  KC_SPC,  KC_DLR,  KC_P1,   KC_P2,   KC_P3,   KC_PSLS, _______,
        _______, _______, _______, _______, _______, XXXXXXX, KC_P0,   KC_PDOT, _______, _______, _______, _______
    ),
    [_PN] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_CIRC, KC_GRV,  KC_TILD, KC_LCBR, KC_RCBR, KC_TAB,  KC_PGUP, KC_UP,   _______, _______, _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_LPRN, KC_RPRN, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______,
        _______, KC_BSLS, KC_AMPR, KC_PIPE, KC_LBRC, KC_RBRC, KC_CAPS, KC_PGDN, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, KC_DEL,  XXXXXXX, _______, _______, _______, _______, _______
    ),
    [_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_PPLS, _______, _______, _______, _______, _______,
        _______, _______, _______, REDO,    UNDO,    _______, KC_MINS, KC_PEQL, KC_DQUO, KC_QUOT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_LABK, KC_RABK, _______, _______,
        _______, _______, _______, _______, XXXXXXX, _______, KC_UNDS, _______, _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

        _______, RESET,   _______, _______, _______, _______, _______, KC_VOLU, KC_BRIU, ZOOMIN,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_BRID, ZOOMOUT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, ACTUAL,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______
    ),
    [_MINECRAFT] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   RESET,   KC_F7,   KC_F8,   COLEMAK, COLEMAKm,KC_EQL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,

        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        KC_TAB,  KC_A,    KC_S,    KC_D,_G(KC_T),  KC_G,    KC_M, _G(KC_N),_S(KC_E),_C(KC_I),_A(KC_O),   KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, KC_CAPS, FNBSPC,  PNSPC,KC_ENT,_G(KC_LEFT),_S(KC_DOWN),_C(KC_UP),_A(KC_RGHT)
    )
};
// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _FN, _PN, _ADJUST);
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAKm:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK_HOME_MOD);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
    }
    return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
