#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT(
                                                                  KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_1, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_3, KC_X, KC_C, KC_D, )};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_F18:
            if (record->event.pressed) {
                // 空白鍵和滑鼠左鍵
                register_code(KC_SPC);
                register_code(KC_MS_BTN1);
            } else {
                unregister_code(KC_SPC);
                unregister_code(KC_MS_BTN1);
            }

            return false;
    }
    return true;
}
