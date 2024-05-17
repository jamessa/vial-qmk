#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    
        KC_J,    KC_L,    KC_U,    KC_Y,    KC_1,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    
        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_3,    KC_X,    KC_C,    KC_D,
    )
};               

// const uint16_t PROGMEM L2[]={KC_1, KC_3, COMBO_END};
// const uint16_t PROGMEM R2[]={KC_5, KC_3, COMBO_END};
// const uint16_t PROGMEM MM[]={KC_1, KC_3, KC_5, COMBO_END};

// combo_t key_combos[] = {
//     COMBO(L2, KC_BACKSPACE),
//     COMBO(R2, KC_SPACE),
//     COMBO(MM, KC_ENTER),
// };

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
