/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include <stdio.h>

#define KC_LEFT_EXSP LT(MO(1), KC_SPC)     // Layer 1 held, Space pressed
#define KC_RIGHT_EXSP LT(MO(2), KC_SPC)     // Layer 2 held, Space pressed
#define KC_ESC_FN LT(MO(4), KC_ESC)  // Layer 3 held, Esc pressed

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_RIGHT_EXSP:
            return true;
        case KC_LEFT_EXSP:
            return true;
        default:
            return false;
    }
}

//Tap Dance Definitions
//E and its special characters
void accent_e (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
    SEND_STRING(SS_RALT("e"));
    reset_tap_dance (state);
  } else {
    SEND_STRING ("e");
    reset_tap_dance (state);
  }
}

//C and its special characters
void accent_c (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
    SEND_STRING(SS_RALT(","));
    reset_tap_dance (state);
  } else {
    SEND_STRING ("c");
    reset_tap_dance (state);
  }
};

void accent_o (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    SEND_STRING(SS_RALT("o"));
    reset_tap_dance(state);
  } else {
    SEND_STRING("o");
    reset_tap_dance(state);
  }
};

//I and its special characters
void accent_i (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
    SEND_STRING(SS_RALT("i"));
    reset_tap_dance (state);
  } else {
    SEND_STRING ("i");
    reset_tap_dance (state);
  }
};

//U and its special characters
void accent_u (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
    SEND_STRING(SS_RALT("u"));
    reset_tap_dance (state);
  } else {
    SEND_STRING ("u");
    reset_tap_dance (state);
  }
};

//A and its special characters
void accent_a (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
    SEND_STRING(SS_RALT("a"));
    reset_tap_dance (state);

  } else {
    SEND_STRING ("a");
    reset_tap_dance (state);
  }
};

//Tilde A left spacebar
void tilde_a_left (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
    SEND_STRING("~a");
    reset_tap_dance (state);
  } else {
    SEND_STRING("$");
    reset_tap_dance (state);
  }
};

//Tilde A right spacebar
void tilde_a_right (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
    SEND_STRING("~a");
    reset_tap_dance (state);
  } else {
    tap_code(KC_4);
    reset_tap_dance (state);
  }
};

//Tilde O
void tilde_o(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
    SEND_STRING("~o");
    reset_tap_dance (state);
  } else {
    tap_code(KC_MINUS);
    reset_tap_dance (state);
  }
};


//Quotes and double quotes
void quotes(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
      // register_code(KC_QUOT);
      tap_code16(KC_DOUBLE_QUOTE);
      reset_tap_dance (state);
  } else {
      tap_code(KC_QUOTE);
      reset_tap_dance (state);
  }
};

//Tap Dance Declarations
enum {

  TD_E_ACCENT,
  TD_C_ACCENT,
  TD_O_ACCENT,
  TD_I_ACCENT,
  TD_U_ACCENT,
  TD_A_ACCENT,
  TD_A_TILDE_LEFT,
  TD_A_TILDE_RIGHT,
  TD_O_TILDE,
  TD_QUOTES,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_E_ACCENT] = ACTION_TAP_DANCE_FN(accent_e),
  [TD_C_ACCENT] = ACTION_TAP_DANCE_FN(accent_c),
  [TD_O_ACCENT] = ACTION_TAP_DANCE_FN(accent_o),
  [TD_I_ACCENT] = ACTION_TAP_DANCE_FN(accent_i),
  [TD_U_ACCENT] = ACTION_TAP_DANCE_FN(accent_u),
  [TD_A_ACCENT] = ACTION_TAP_DANCE_FN(accent_a),
  [TD_A_TILDE_LEFT] = ACTION_TAP_DANCE_FN(tilde_a_left),
  [TD_A_TILDE_RIGHT] = ACTION_TAP_DANCE_FN(tilde_a_right),
  [TD_O_TILDE] = ACTION_TAP_DANCE_FN(tilde_o),
  [TD_QUOTES] = ACTION_TAP_DANCE_FN(quotes)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_Q, KC_W, TD(TD_E_ACCENT), KC_R, KC_T,                         KC_Y,    TD(TD_U_ACCENT),    TD(TD_I_ACCENT), TD(TD_O_ACCENT),   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC_FN, TD(TD_A_ACCENT), KC_S, KC_D, KC_F, KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCTL(KC_LGUI),    KC_Z,    KC_X, TD(TD_C_ACCENT), KC_V, KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_PSCR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   LSFT_T(KC_BSPC),  KC_LEFT_EXSP,     KC_RIGHT_EXSP,  RSFT_T(KC_ENT), MO(3)
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRAVE, KC_AMPERSAND, KC_ASTERISK,  _______, _______, _______,           _______, _______, _______, TD(TD_O_TILDE), KC_EQUAL, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, TD(TD_A_TILDE_LEFT), KC_PERCENT, KC_CIRCUMFLEX, _______, _______,                      KC_HOME, KC_PGDOWN,   KC_PGUP,KC_END, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXCLAIM, KC_AT, KC_HASH, _______, _______,                      _______, KC_SCOLON, KC_LPRN, KC_RPRN, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, KC_DEL,  _______,     _______,   _______, _______
                                      //`--------------------------'  `--------------------------'
  ),


  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       TD(TD_QUOTES), KC_7, KC_8, KC_9, KC_0, _______,           _______, _______, _______, TD(TD_O_TILDE), KC_EQUAL, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, TD(TD_A_TILDE_RIGHT), KC_5, KC_6, _______, _______,                      KC_LEFT, KC_DOWN, KC_UP,KC_RIGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_1, KC_2, KC_3, _______, _______,                      _______, _______, KC_LBRC, KC_RBRC, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, KC_DEL,  _______,     _______,   _______, _______
                                      //`--------------------------'  `--------------------------'
  ),


  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       TD(TD_QUOTES), KC_SLASH, KC_QUESTION, _______, _______, _______,           _______, _______, _______, KC_MINUS, KC_EQUAL, RESET,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                      KC_F7, KC_F8, KC_F9,KC_F10, KC_F11, KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_BSLS, KC_PIPE, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  RESET,     _______,   _______, _______
                                      //`--------------------------'  `--------------------------'
  ),


  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       TD(TD_QUOTES), _______, KC_UP, _______, _______, _______,           _______, _______, _______, _______, KC_F5, RCS(KC_F5),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,                      _______, _______, _______,_______, KC_F10, KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______,   _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

//   [3] = LAYOUT_split_3x6_3(
//   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//         RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                           KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
//                                       //`--------------------------'  `--------------------------'
//   )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE
