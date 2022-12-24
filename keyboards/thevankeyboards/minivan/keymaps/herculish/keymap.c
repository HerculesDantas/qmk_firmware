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

   /* Base Layer
   * .-----------------------------------------------------------------------.
   * | Tab |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  | BkSp |
   * |------------------------------------------------------------------------|
   * | Esc   |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  Return  |
   * |------------------------------------------------------------------------|
   * | Shift    |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |   /   |
   * |------------------------------------------------------------------------|
   * | Ctrl  | Win | Alt   |  Space+fn1  |  Space+fn2  | Alt   | Win |  Ctrl  |
   * '------------------------------------------------------------------------'
   */

    [_BASE] = LAYOUT_arrow(
        KC_TAB, KC_Q, KC_W, TD(TD_E_ACCENT), KC_R,  KC_T,    KC_Y,    TD(TD_U_ACCENT),    TD(TD_I_ACCENT),    TD(TD_O_ACCENT),    KC_P,    KC_BSPC,
        KC_ESC_FN,    TD(TD_A_ACCENT),    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,   KC_ENT,
        KC_LSFT,  KC_Z,    KC_X,    TD(TD_C_ACCENT),    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_UP,   KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_LEFT_EXSP,              KC_RIGHT_EXSP,              MO(3),   KC_LEFT, KC_DOWN, KC_RGHT
    ),


    [1] = LAYOUT_arrow(
        KC_GRAVE,  KC_AMPERSAND , KC_ASTERISK, _______ , _______, _______, _______, _______, _______, TD(TD_O_TILDE), KC_EQUAL, KC_DEL,
        _______,   TD(TD_A_TILDE_LEFT), KC_PERCENT,  KC_CIRCUMFLEX,  _______, _______, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END, _______, _______,
        _______,    KC_EXCLAIM , KC_AT, KC_HASH , _______, _______, _______, KC_SCOLON, KC_LPRN, KC_RPRN, _______, _______,
        _______, _______, _______, _______,                _______,             _______, _______, _______, _______
    ),

    [2] = LAYOUT_arrow(
        TD(TD_QUOTES),   KC_7, KC_8, KC_9, KC_0 , _______, _______, _______, _______, TD(TD_O_TILDE), KC_EQUAL, _______,
        _______,   TD(TD_A_TILDE_RIGHT), KC_5,  KC_6,  _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,
        _______,    KC_1, KC_2, KC_3, _______ , _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______,
        _______, _______, _______, _______,                _______,             _______, _______, _______, _______
    ),


    [3] = LAYOUT_arrow(
        TD(TD_QUOTES),   KC_SLASH, KC_QUESTION, _______, _______, _______, _______, _______, _______, KC_MINUS, KC_EQUAL, RESET,
        KC_F1,  KC_F2, KC_F3,  KC_F4,  KC_F5, KC_F6, KC_F7, KC_F8, KC_9, KC_F10, KC_F11, KC_F12,
        _______,    KC_BSLS, KC_PIPE, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,                _______,             _______, _______, _______, _______
    ),

    [4] = LAYOUT_arrow(
        TD(TD_QUOTES),   _______, KC_UP, _______, _______, _______, _______, _______, _______, _______, KC_F5, RCS(KC_F5),
        _______,   KC_LEFT, KC_DOWN,  KC_RIGHT,  _______, _______, _______, _______, _______, _______, KC_F10, KC_F11,
        _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,                _______,             _______, _______, _______, _______
    )

};
