#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "keymap_steno.h"

#define BASE    0
#define MIRROR  1
#define SYMBOLS 2
#define NUMPAD  3
#define TXBOLT  4
#define QWERTY  5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |QWERTY|           |TXBOLT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   \    | Q/Sym| W/Sym| E/Sym| R/Sym|   T  |  L1  |           |  [   |   Y  | U/Sym| I/Sym| O/Sym| P/Sym|   ]    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Esc   |A/Shft|S/Shft|D/Ctrl|F/Ctrl|   G  |------|           |------|   H  |J/Ctrl|K/Ctrl|L/Shft|;/Shft|   '    |
 * |--------+------+------+------+------+------| Del  |           | Ins  |------+------+------+------+------+--------|
 * |LShift/(| Z/Cmd| X/Cmd| C/Alt| V/Alt|B/Mror|      |           |      |N/Mror| M/Alt| ,/Alt| ./Cmd| //Cmd|RShift/)|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LGui |  Grv |nonUS\|nonUS#| Right|                                       | Left | Down |  Up  | Right| RGui |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |Space |      | Home |       | PgUp |        |Enter |
 *                                 |  /   | Back-|------|       |------|  Tab   |  /   |
 *                                 |Mirror| space| End  |       | PgDn |        |Mirror|
 *                                 `--------------------'       `----------------------'
 */
#define SYM_T(key) LT(SYMBOLS,key)
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,            KC_1,        KC_2,            KC_3,              KC_4,        KC_5,            TG(QWERTY),
        KC_BSLS,           SYM_T(KC_Q), SYM_T(KC_W),     SYM_T(KC_E),       SYM_T(KC_R), KC_T,            TG(NUMPAD),
        KC_ESC,            SFT_T(KC_A), SFT_T(KC_S),     CTL_T(KC_D),       CTL_T(KC_F), KC_G,
        KC_LSPO,           GUI_T(KC_Z), GUI_T(KC_X),     ALT_T(KC_C),       ALT_T(KC_V), LT(MIRROR,KC_B), KC_DELT,
        KC_LGUI,           KC_GRV,      KC_NONUS_BSLASH, KC_NONUS_HASH,     KC_RGHT,
                                                                                          ALT_T(KC_APP),    KC_LGUI,
                                                                                                            KC_HOME,
                                                                      LT(MIRROR, KC_SPC), KC_BSPC,          KC_END,
        // right hand
        TG(TXBOLT), KC_0,            KC_6,        KC_7,           KC_8,          KC_9,           KC_MINS,
        KC_LBRC,    KC_Y,            SYM_T(KC_U), SYM_T(KC_I),    SYM_T(KC_O),   SYM_T(KC_P),    KC_RBRC,
                    KC_H,            CTL_T(KC_J), CTL_T(KC_K),    SFT_T(KC_L),   SFT_T(KC_SCLN), KC_QUOT,
        KC_INS,     LT(MIRROR,KC_N), ALT_T(KC_M), ALT_T(KC_COMM), GUI_T(KC_DOT), GUI_T(KC_SLSH), KC_RSPC,
                                     KC_LEFT,     KC_DOWN,       KC_UP,         KC_RIGHT,        KC_RGUI,
        KC_LALT,    CTL_T(KC_ESC),
        KC_PGUP,
        KC_PGDN,    KC_TAB, LT(MIRROR, KC_ENT)
),
/* Keymap 1: Mirrored
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   -    |   9  |   8  |   7  |   6  |   0  |TXBOLT|           | LEFT |   5  |   4  |   3  |   2  |   1  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   ]    | P/Sym| O/Sym| I/Sym| U/Sym|   Y  |  [   |           |  L1  |   T  | R/Sym| E/Sym| W/Sym| Q/Sym|   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   '    |;/Shft|L/Shft|K/Ctrl|J/Ctrl|   H  |------|           |------|   G  |F/Ctrl|D/Ctrl|S/Shft|A/Shft|  Esc   |
 * |--------+------+------+------+------+------| Ins  |           | Del  |------+------+------+------+------+--------|
 * | RShift | //Cmd| ./Cmd| ,/Alt| M/Alt|   N  |      |           |      |   B  | V/Alt| C(Alt| X/Cmd| Z/Cmd| LShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ~L1  | Right|  Up  | Down | Left |                                       | Right| Left |AltShf|  Grv |Grv/L1|
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,---------------.       ,-------------.
 *                                      |Ctrl/Esc| Alt  |       | LGui | App  |
 *                               ,------+--------+------|       |------+------+------.
 *                               |      |        | PgUp |       | Home |      |Space |
 *                               |Enter |  Tab   |------|       |------| Back-|  /   |
 *                               |      |        | PgDn |       | End  | space|Mirror|
 *                               `----------------------'       `--------------------'
 */
// MIRROR
[MIRROR] = LAYOUT_ergodox(
        // left hand
        KC_MINS, KC_9,     KC_8,   KC_7,         KC_6,           KC_0,          TG(TXBOLT),
        KC_RBRC, SYM_T(KC_P),     SYM_T(KC_O),   SYM_T(KC_I),    SYM_T(KC_U), KC_Y, KC_LBRC,
        KC_QUOT, SFT_T(KC_SCLN),  SFT_T(KC_L),   CTL_T(KC_K),    CTL_T(KC_J), KC_H,
        KC_RSPC, GUI_T(KC_SLSH),  GUI_T(KC_DOT), ALT_T(KC_COMM), ALT_T(KC_M), KC_N, KC_INS,
        KC_RGUI, KC_RIGHT, KC_UP, KC_DOWN,       KC_LEFT,
                                                                 CTL_T(KC_ESC), KC_LALT,
                                                                                KC_PGUP,
                                                                        KC_ENT, KC_TAB,   KC_PGDN,
        // right hand
        KC_LEFT,    KC_5, KC_4,        KC_3,        KC_2,        KC_1,        KC_EQL,
        TG(NUMPAD), KC_T, SYM_T(KC_R), SYM_T(KC_E), SYM_T(KC_W), SYM_T(KC_Q), KC_BSLS,
                    KC_G, CTL_T(KC_F), CTL_T(KC_D), SFT_T(KC_S), SFT_T(KC_A), KC_ESC,
        KC_DELT,    KC_B, ALT_T(KC_V), ALT_T(KC_C), GUI_T(KC_X), GUI_T(KC_Z), KC_LSPO,
                          KC_RGHT,     KC_LEFT,     LALT(KC_LSFT), KC_GRV,    KC_LGUI,
        KC_LGUI,    ALT_T(KC_APP),
        KC_HOME,
        KC_END,     KC_BSPC, MIRROR
),
/* Keymap 2: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |      |      |           |      |      |   "  |   '  |   =  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |      |------|           |------|      |   &  |   _  |   -  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |      |      |           |      |      |   |  |   `  |   ~  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMBOLS] = LAYOUT_ergodox(
       // left hand
       M(0),    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS, SYM_T(KC_EXLM), SYM_T(KC_AT),   SYM_T(KC_LCBR), SYM_T(KC_RCBR), KC_TRNS, KC_TRNS,
       KC_TRNS, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_TRNS,
       KC_TRNS, KC_PERC,        KC_CIRC,        KC_LBRC,        KC_RBRC,        KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                                 KC_TRNS,KC_TRNS,
                                                                                         KC_TRNS,
                                                                         KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F7,  KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
       KC_TRNS, SYM_T(KC_TRNS), SYM_T(KC_DQT),  SYM_T(KC_QUOT), SYM_T(KC_EQL),   KC_ASTR, KC_TRNS,
                KC_TRNS,        KC_AMPR,        KC_UNDS,        KC_MINUS,        KC_PLUS, KC_TRNS,
       KC_TRNS, KC_TRNS,        KC_PIPE,        KC_GRV,         KC_TILD,         KC_BSLS, KC_TRNS,
                                KC_TRNS, KC_TRNS, KC_TRNS,  KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Numpad
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   F13  | Num  |  P/  |  P*  |  P-  |  F1  |      |           |      |  F5  |  Num |  P/  |  P*  |  P-  |   F9   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   F14  |  P7  |  P8  |  P9  |  P+  |  F2  |      |           |      |  F6  |  P7  |  P8  |  P9  |  P+  |   F10  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   F15  |  P4  |   5  |  P6  |  P+  |  F3  |------|           |------|  F7  |  P4  |  P5  |  P6  |  P+  |   F11  |
 * |--------+------+------+------+------+------|      |           | PrSc |------+------+------+------+------+--------|
 * |   F16  |  P1  |  P2  |  P3  | PRet |  F4  |      |           | SysR |  F8  |  P1  |  P2  |  P3  | PRet |   F12  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |  P0  |  P0  |  P.  | PRet |                                       |  P0  |  P0  |  P.  | PRet |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// NUMPAD
[NUMPAD] = LAYOUT_ergodox(
       // left hand
       KC_F13,  KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_F1, KC_TRNS,
       KC_F14,  KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_F2, KC_TRNS,
       KC_F15,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_F3,
       KC_F16,  KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_F4, KC_TRNS,
       KC_TRNS, KC_P0,   KC_P0,   KC_PDOT, KC_PENT,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F5, KC_NLCK, KC_PSLS,  KC_PAST, KC_PMNS, KC_F9,
       KC_TRNS, KC_F6, KC_P7,   KC_P8,    KC_P9,   KC_PPLS, KC_F10,
                KC_F7, KC_P4,   KC_P5,    KC_P6,   KC_PPLS, KC_F11,
       KC_PSCR, KC_F8, KC_P1,   KC_P2,    KC_P3,   KC_PENT, KC_F12,
                       KC_P0,   KC_P0,    KC_PDOT, KC_PENT, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
// TxBolt Codes
#define Sl 0b00000001
#define Tl 0b00000010
#define Kl 0b00000100
#define Pl 0b00001000
#define Wl 0b00010000
#define Hl 0b00100000
#define Rl 0b01000001
#define Al 0b01000010
#define Ol 0b01000100
#define X  0b01001000
#define Er 0b01010000
#define Ur 0b01100000
#define Fr 0b10000001
#define Rr 0b10000010
#define Pr 0b10000100
#define Br 0b10001000
#define Lr 0b10010000
#define Gr 0b10100000
#define Tr 0b11000001
#define Sr 0b11000010
#define Dr 0b11000100
#define Zr 0b11001000
#define NM 0b11010000
#define GRPMASK 0b11000000
#define GRP0 0b00000000
#define GRP1 0b01000000
#define GRP2 0b10000000
#define GRP3 0b11000000
/* Keymap 3: TxBolt (Serial)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | BKSPC  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   #  |   #  |   #  |   #  |   #  |      |           |      |   #  |   #  |   #  |   #  |   #  |   #    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   S  |   T  |   P  |   H  |   *  |------|           |------|   *  |   F  |   P  |   L  |   T  |   D    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   S  |   K  |   W  |   R  |   *  |      |           |      |   *  |   R  |   B  |   G  |   S  |   Z    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   A  |   O  |------|       |------|   E  |   U  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// TxBolt over Serial
[TXBOLT] = LAYOUT_ergodox(
       KC_BSPC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  KC_NO,
       KC_NO,   STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,
       KC_NO,   STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                           KC_NO,   KC_NO,
                                                    KC_NO,
                                  STN_A,   STN_O,   KC_NO,
    // right hand
       KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,    STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,
                 STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
       KC_NO,    STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   STN_E,   STN_U
),
/* Keymap 0: Basic QWERTY (gaming) layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Escape |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LGui |  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | RGui |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Ctrl | Alt  |       | Alt  | Ctrl   |
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[QWERTY] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,  KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_TRNS,
        KC_DELT, KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_NO,
        KC_ESC,  KC_A,    KC_S,    KC_D, KC_F, KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V, KC_B, KC_NO,
        KC_LGUI,  KC_QUOT, LALT(KC_LSFT), KC_LEFT, KC_RGHT,
                                               KC_LCTRL, KC_LALT,
                                                         KC_HOME,
                                          KC_SPC,KC_BSPC,KC_END,
        // right hand
        KC_NO, KC_6, KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,
        KC_NO, KC_Y, KC_U,    KC_I,    KC_O,   KC_P,    KC_BSLS,
               KC_H, KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_NO, KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                     KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, KC_RGUI,
        KC_RALT,        KC_RCTRL,
        KC_PGUP,
        KC_PGDN,KC_TAB, KC_ENT
),
};
//
// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    steno_set_mode(STENO_MODE_BOLT); // or STENO_MODE_GEMINI
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    if (layer&1) ergodox_right_led_1_on(); else ergodox_right_led_1_off();
    if (layer&2) ergodox_right_led_2_on(); else ergodox_right_led_2_off();
    if (layer&4) ergodox_right_led_3_on(); else ergodox_right_led_3_off();
};
