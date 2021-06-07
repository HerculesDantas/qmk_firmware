/* Copyright 2019 mechmerlin
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

// Layer shorthand
enum layers {
    _BASE = 0, // Base
    _EXTR,     // Extra
    _CTRL      // Control
};

#define KC_LEFT_EXSP LT(MO(1), KC_SPC)     // Layer 1 held, Space pressed
#define KC_RIGHT_EXSP LT(MO(2), KC_SPC)     // Layer 2 held, Space pressed
#define KC_ESC_FN LT(MO(4), KC_ESC)  // Layer 3 held, Esc pressed

//Tap Dance Declarations
enum {

  TD_E_ACCENT,
  TD_C_ACCENT,
  TD_O_ACCENT,
  TD_I_ACCENT,
  TD_U_ACCENT,
  TD_A_ACCENT,

};

//Tap Dance Definitions
//E and its special characters
void accent_e (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
    // SEND_STRING ("'"+"e");
    SEND_STRING("'e");
    reset_tap_dance (state);

  } else if (state->count == 3) {
    // SEND_STRING ("'"+"e");
    SEND_STRING("'e");
    reset_tap_dance (state);
  } else {
    SEND_STRING ("e");
    reset_tap_dance (state);
  }
}

//C and its special characters
void accent_c (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
    SEND_STRING("'c");
    reset_tap_dance (state);
  } else {
    SEND_STRING ("c");
    reset_tap_dance (state);
  }
};

//O and its special characters
void accent_o (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
    SEND_STRING("'o");
    reset_tap_dance (state);
  } else {
    SEND_STRING ("o");
    reset_tap_dance (state);
  }
};

//I and its special characters
void accent_i (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
    // SEND_STRING ("'"+"e");
    SEND_STRING("'i");
    reset_tap_dance (state);
  } else {
    SEND_STRING ("i");
    reset_tap_dance (state);
  }
};

//U and its special characters
void accent_u (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
    // SEND_STRING ("'"+"e");
    SEND_STRING("'u");
    reset_tap_dance (state);
  } else {
    SEND_STRING ("u");
    reset_tap_dance (state);
  }
};

//A and its special characters
void accent_a (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
    // SEND_STRING ("'"+"e");
    SEND_STRING("'a");
    reset_tap_dance (state);

  } else if (state->count == 3) {
    SEND_STRING("`a");
    reset_tap_dance (state);
  } else {
    SEND_STRING ("a");
    reset_tap_dance (state);
  }
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_E_ACCENT] = ACTION_TAP_DANCE_FN(accent_e),
  [TD_C_ACCENT] = ACTION_TAP_DANCE_FN(accent_c),
  [TD_O_ACCENT] = ACTION_TAP_DANCE_FN(accent_o),
  [TD_I_ACCENT] = ACTION_TAP_DANCE_FN(accent_i),
  [TD_U_ACCENT] = ACTION_TAP_DANCE_FN(accent_u),
  [TD_A_ACCENT] = ACTION_TAP_DANCE_FN(accent_a)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /* Base Layer
   * .-----------------------------------------------------------------------.
   * | Tab |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  | BkSp |
   * |------------------------------------------------------------------------|
   * | Esc   |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  Return  |
   * |------------------------------------------------------------------------|
   * | Shift    |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |   /   |
   * |------------------------------------------------------------------------|
   * | Ctrl  | Win | Alt   | Fn1      |  Space         | Alt   | Win |  Ctrl  |
   * '------------------------------------------------------------------------'
   */

    [_BASE] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    TD(TD_E_ACCENT),    KC_R,    KC_T,    KC_Y,    TD(TD_U_ACCENT),    TD(TD_I_ACCENT),    TD(TD_O_ACCENT),    KC_P,    KC_BSPC,
        KC_ESC_FN,    TD(TD_A_ACCENT),    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    TD(TD_C_ACCENT),    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_UP,   RSFT_T(KC_DOT),
        KC_LCTL, KC_LGUI, KC_LALT, KC_LEFT_EXSP,              KC_RIGHT_EXSP,              MO(3),   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        KC_TILDE,   KC_AMPERSAND, KC_ASTERISK, KC_9, KC_0, _______, _______, _______, _______, KC_MINUS, KC_EQUAL, KC_DEL,
        _______,   KC_DOLLAR, KC_PERCENT,  KC_CIRCUMFLEX,  _______, _______, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END, _______,
        _______,    KC_EXCLAIM, KC_AT, KC_HASH, _______, _______, _______, KC_SCOLON, KC_LPRN, _______, KC_RPRN,
        _______, _______, _______, _______,                _______,             _______, _______, _______, _______
    ),

    [2] = LAYOUT(
        KC_QUOTE,   KC_7, KC_8, KC_9, KC_0, _______, _______, _______, _______, KC_MINUS, KC_EQUAL, RESET,
        _______,   KC_4, KC_5,  KC_6,  _______, _______, _______, _______, _______, _______, _______,
        _______,    KC_1, KC_2, KC_3, _______, _______, _______, _______, KC_LBRC, _______, KC_RBRC,
        _______, _______, _______, _______,                _______,             _______, _______, _______, _______
    ),


    [3] = LAYOUT(
        KC_QUOTE,   KC_SLASH, KC_QUESTION, _______, _______, _______, _______, _______, _______, KC_MINUS, KC_EQUAL, RESET,
        KC_F1,  KC_F2, KC_F3,  KC_F4,  KC_F5, KC_F6, KC_F7, KC_F8, KC_9, KC_F10, KC_F11,
        KC_F1,    KC_BSLS, KC_PIPE, _______, _______, _______, _______, _______, KC_LBRC, _______, KC_RBRC,
        _______, _______, _______, _______,                _______,             _______, _______, _______, _______
    ),

    [4] = LAYOUT(
        KC_QUOTE,   _______, KC_UP, _______, _______, _______, _______, _______, _______, KC_MINUS, KC_EQUAL, RESET,
        _______,   KC_LEFT, KC_DOWN,  KC_RIGHT,  _______, _______, _______, _______, _______, _______, _______,
        _______,    _______, _______, _______, _______, _______, _______, _______, KC_LBRC, _______, KC_RBRC,
        _______, _______, _______, _______,                _______,             _______, _______, _______, _______
    ),

};

