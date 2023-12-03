#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_4x10(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    QK_BOOT,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_COMMA,KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_Z,    KC_DOT,  KC_TAB,
        KC_A,    KC_B,    KC_BACKSPACE,
    )
};

// #define RIGHT_INDICATOR  F5
// #define MIDDLE_INDICATOR F6
// #define LEFT_INDICATOR   F7
// #define ON 0
// #define OFF 1

void keyboard_post_init_user(void) {
// Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
// debug_keyboard=true;
//debug_mouse=true;

    // setPinOutput(RIGHT_INDICATOR);
    // writePin    (RIGHT_INDICATOR, OFF);
    // setPinOutput(MIDDLE_INDICATOR);
    // writePin    (MIDDLE_INDICATOR, OFF);
    // setPinOutput(LEFT_INDICATOR);
    // writePin    (LEFT_INDICATOR, OFF);
}
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     printf("%d\n",record->event.pressed);
//     if(record->event.pressed){
//         switch(keycode){
//             case KC_1:
//                 writePin(RIGHT_INDICATOR, ON);
//                 break;
//             case KC_2:
//                 writePin(RIGHT_INDICATOR, ON);
//                 writePin(MIDDLE_INDICATOR, ON);
//                 break;
//             case KC_3:
//                 writePin(MIDDLE_INDICATOR, ON);
//                 break;
//             case KC_4:
//                 writePin(LEFT_INDICATOR, ON);
//                 writePin(MIDDLE_INDICATOR, ON);
//                 break;
//             case KC_5:
//                 writePin(LEFT_INDICATOR, ON);
//                 break;
//         }
//     } else{
//         writePin(RIGHT_INDICATOR, OFF);
//         writePin(MIDDLE_INDICATOR, OFF);
//         writePin(LEFT_INDICATOR, OFF);
//     }
// return true;
// }
