#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "keymap_steno.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _PLOVER 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  PLOVER,
  EXT_PLV,
  LOWER,
  RAISE,
  UNLOWER,
  UNRAISE,
  ROT_BTN,
  ROT_A,
  ROT_B
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define NKRO    MAGIC_TOGGLE_NKRO

#define LS(C) MT(MOD_LSFT, KC_##C)
#define LC(C) MT(MOD_LCTL, KC_##C)
#define LA(C) MT(MOD_LALT, KC_##C)
#define LG(C) MT(MOD_LGUI, KC_##C)
#define RS(C) MT(MOD_RSFT, KC_##C)
#define RC(C) MT(MOD_RCTL, KC_##C)
#define RA(C) MT(MOD_RALT, KC_##C)
#define RG(C) MT(MOD_RGUI, KC_##C)
#define LO(C) LT(_LOWER, KC_##C)
#define RZ(C) LT(_RAISE, KC_##C)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |  \   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space | Tab  |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
   KC_BSLS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_MINS, \
   KC_ESC,  LS(A),   LS(S),   LC(D),   LC(F),   KC_G,     KC_H,    RC(J),   RC(K),    RS(L),   RS(SCLN), KC_QUOT, \
   KC_LSFT, LG(Z),   LG(X),   LA(C),   LA(V),   KC_B,     KC_N,    RA(M),   RA(COMM), RG(DOT), RG(SLSH), KC_RSFT, \
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LO(SPC), RZ(BSPC), LO(TAB), RZ(ENT), KC_MPLY,  ROT_A,   ROT_B,    XXXXXXX  \
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  FN  |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Exit |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |   A  |   O  |   E  |   U  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = LAYOUT_ortho_4x12( \
  STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5, STN_N6,  STN_N7,  STN_N8, STN_N9,  STN_NA, STN_NB, STN_NC, \
  STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL, STN_ST1, STN_ST3, STN_FR, STN_PR,  STN_LR, STN_TR, STN_DR, \
  EXT_PLV, STN_S2,  STN_KL,  STN_WL,  STN_RL, STN_ST2, STN_ST4, STN_RR, STN_BR,  STN_GR, STN_SR, STN_ZR, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, STN_A,  STN_O,   STN_E,   STN_U,  KC_MPLY, ROT_A,  ROT_B,  XXXXXXX \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR,    KC_LPRN, KC_RPRN, _______, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,  KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS), S(KC_NUBS), _______, _______, _______, \
  _______, _______, _______, _______, UNLOWER, RAISE,   UNLOWER, RAISE,    KC_MSTP,    ROT_A,   ROT_B,   _______  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_0,    KC_6,    KC_7,    KC_8,    KC_9,    _______, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______, LOWER,   UNRAISE, LOWER,   UNRAISE, KC_MSEL, ROT_A,   ROT_B,   _______  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | NKRO |      |      |      |      |      |      |      |      |      |      | NKRO |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Plover|      | Home | PgUp | PgDn | End  | Left | Down |  Up  |Right |      |Plover|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Reset |      |      |      |      |      |      |      |      |      |      |Reset |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  NKRO,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, NKRO,    \
  PLOVER,  _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, PLOVER, \
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_EJCT, ROT_A,   ROT_B,   _______  \
)


};

void matrix_init_user(void) {
  steno_set_mode(STENO_MODE_GEMINI);
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

static int rotary_encoder_state = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (keycode != ROT_A && keycode != ROT_B)
    rotary_encoder_state = 0;

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case PLOVER:
      if (!record->event.pressed) {
        layer_off(_LOWER);
        layer_off(_RAISE);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
      }
      return false;
      break;
    case EXT_PLV:
      if (!record->event.pressed) {
        layer_off(_PLOVER);
        layer_on(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case UNLOWER:
      if (!record->event.pressed) {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case UNRAISE:
      if (!record->event.pressed) {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ROT_BTN:
      if (!record->event.pressed) {
        uint16_t kc = layer_state_is(_ADJUST)?KC_MSEL:
                      layer_state_is(_LOWER)? KC_STOP:
                                              KC_MPLY;
        register_code(kc);
        unregister_code(kc);
      } else {
        rotary_encoder_state = 0;
      }
      return false;
      break;
    case ROT_A:
      if (record->event.pressed) {
        switch (rotary_encoder_state) {
          case 0:
            rotary_encoder_state = 1;
            break;
          default: // not just case 2 because of debouncing issues
            {
              uint16_t kc = layer_state_is(_ADJUST)?KC_WFWD:
                            layer_state_is(_LOWER)? KC_MPRV:
                            layer_state_is(_RAISE)? KC_MRWD:
                                                    KC_VOLU;
              register_code(kc);
              unregister_code(kc);
            }
        }
      } else {
        rotary_encoder_state = 0;
      }
      return false;
      break;
    case ROT_B:
      if (record->event.pressed) {
        switch (rotary_encoder_state) {
          case 0:
            rotary_encoder_state = 2;
            break;
          default: // not just case 1 because of debouncing issues
            {
              uint16_t kc = layer_state_is(_ADJUST)?KC_WBAK:
                            layer_state_is(_LOWER)? KC_MNXT:
                            layer_state_is(_RAISE)? KC_MFFD:
                                                 KC_VOLD;
              register_code(kc);
              unregister_code(kc);
            }
        }
      } else {
        rotary_encoder_state = 0;
      }
      return false;
      break;
  }
  return true;
}
