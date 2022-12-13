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

#define _LG(X) LGUI_T(X)
#define _LA(X) LALT_T(X)
#define _LC(X) LCTL_T(X)
#define _LS(X) LSFT_T(X)
#define _RG(X) RGUI_T(X)
#define _RA(X) RALT_T(X)
#define _RC(X) RCTL_T(X)
#define _RS(X) RSFT_T(X)

#define REDO C(KC_Y)
#define COPY C(KC_C)
#define PSTE C(KC_V)
#define CUT C(KC_X)
#define UNDO C(KC_Z)

enum my_layers {
    COLEMAK = 0,
    QWERTY,
    NAV,
    MOUSE,
    MEDIA,
    NUM,
    SYM,
    FUNC,
    TOTAL_LAYER_COUNT,
};

const char *layer_names[TOTAL_LAYER_COUNT] = {
    [COLEMAK] = " COL ",
    [QWERTY]  = " QWE ",
    [NAV]     = " NAV ",
    [MOUSE]   = "MOUSE",
    [MEDIA]   = "MEDIA",
    [NUM]     = " NUM ",
    [SYM]     = " SYM ",
    [FUNC]    = " FUN ",
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [COLEMAK] = LAYOUT(
        KC_Q, KC_W, KC_F, KC_P, KC_B,
            KC_J, KC_L, KC_U, KC_Y, KC_QUOT,
        _LG(KC_A), _LA(KC_R), _LC(KC_S), _LS(KC_T), KC_G,
            KC_M, _LS(KC_N), _LC(KC_E), _LA(KC_I), _LG(KC_O),
        KC_Z, KC_X, KC_C, KC_D, KC_V,
            KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH,
        LT(NAV, KC_TAB), LT(MOUSE, KC_SPC), LT(SYM, KC_BSPC), LT(NUM, KC_ENT)
    ),
    [QWERTY] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T,
            KC_Y, KC_U, KC_I, KC_O, KC_P,
        _LG(KC_A), _LA(KC_S), _LC(KC_D), _LS(KC_F), KC_G,
            KC_H, _LS(KC_J), _LC(KC_K), _LA(KC_L), _LG(KC_SCLN),
        KC_Z, KC_X, KC_C, KC_V, KC_B,
            KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
        _______, _______, _______, _______
    ),
    [NAV] = LAYOUT(
        TG(QWERTY), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            REDO, PSTE, COPY, CUT, UNDO,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
            XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
        KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
        XXXXXXX, XXXXXXX, KC_BSPC, KC_ENT
    ),
    [MOUSE] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            REDO, PSTE, COPY, CUT, UNDO,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
            XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            KC_BTN3, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
        XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2
    ),
    [MEDIA] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
            XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, KC_MSTP, KC_MPLY, KC_MUTE, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [NUM] = LAYOUT(
        KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,
            XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_GRV, KC_1, KC_2, KC_3, KC_BSLS,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_0, KC_MINS, XXXXXXX, XXXXXXX
    ),
    [SYM] = LAYOUT(
        KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,
            XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX
    ),
    [FUNC] = LAYOUT(
        KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,
            XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_SPC, KC_TAB, XXXXXXX, XXXXXXX
    ),
};

const uint16_t PROGMEM thumbcombos_base_left[] = {LT(NAV, KC_TAB), LT(MOUSE, KC_SPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_right[] = {LT(SYM, KC_BSPC), LT(NUM, KC_ENT), COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[] = {KC_BSPC, KC_ENT, COMBO_END};
const uint16_t PROGMEM thumbcombos_sym[] = {KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM thumbcombos_func[] = {KC_SPC, KC_TAB, COMBO_END};
combo_t key_combos[] = {
    COMBO(thumbcombos_base_left, LT(MEDIA, KC_ESC)),
    COMBO(thumbcombos_base_right, LT(FUNC, KC_DEL)),
    COMBO(thumbcombos_nav, KC_DEL),
    COMBO(thumbcombos_sym, KC_UNDS),
    COMBO(thumbcombos_func, KC_APP),
};
const uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable = true;
    //   debug_matrix=true;
    //   debug_keyboard=true;
    //   debug_mouse=true;
}

#ifdef OLED_ENABLE

bool    oled_needs_update = true;
bool    caps_lock         = false;
uint8_t layer             = 0;

// for caps lock
bool led_update_user(led_t led_state) {
    if (caps_lock == led_state.caps_lock) return true;
    dprint("caps lock changed\n");

    caps_lock         = led_state.caps_lock;
    oled_needs_update = true;
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // render layer indicator
    if (layer == get_highest_layer(state)) return state;
    dprint("layer changed\n");

    layer             = get_highest_layer(state);
    oled_needs_update = true;
    return state;
}

bool oled_task_user(void) {
    if (!oled_needs_update) return false;
    oled_needs_update = false;

    // render caps lock indicator
    if (caps_lock) {
        oled_write_P(PSTR("CAPS LOCK"), false);
    } else {
        oled_write_P(PSTR("PRAGMATIC"), false);
    }

    oled_set_cursor(0, 1);

    const char *layer_name = layer_names[layer];
    if (layer_name)
        oled_write(layer_name, false);
    return false;
}

#endif // OLED_ENABLE
