#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "led.h"

#define BASE 0 // default layer
#define COLE 1 // colemak layer
#define SYMB 2 // symbols
#define MDIA 3 // media keys
#define UMLS 4 // umlauts

#define UMLAE 10
#define UMLOE 11
#define UMLUE 12
#define UMLSZ 13
#define UMLEU 14

#define L2CTRL 20
#define L2CTRLSFT 21

#define CPYPST 30

#define SM_SMILE 44
#define SM_SMIRK 45
#define SM_FROWN 46
#define SM_CRY 47
#define SM_KISS 48
#define SM_HEART 49
#define SM_LAUGH 50
#define SM_SAD 51

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,        KC_1,     KC_2,     KC_3,    KC_4,      KC_5,     LGUI(KC_SPC),
        KC_TAB,        KC_Q,     KC_W,     KC_E,    KC_R,      KC_T,     KC_PLUS,
        CTL_T(KC_ESC), KC_A,     KC_S,     KC_D,    KC_F,      KC_G,
        KC_LSFT,       KC_Z,     KC_X,     KC_C,    KC_V,      KC_B,     KC_EQL,
        KC_LCTRL,      MO(MDIA), MO(SYMB), KC_LGUI, KC_LALT,
                                                    M(CPYPST), KC_ENT,
                                                               TG(COLE),
                                           KC_SPC,  KC_BSPC,   KC_DEL,
        // right hand
             LGUI(KC_ENT), KC_6,    KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
             LSFT(KC_7),   KC_Y,    KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
                           KC_H,    KC_J,     KC_K,     KC_L,     KC_SCLN,  CTL_T(KC_QUOT),
             KC_MINS,      KC_N,    KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                                    MO(MDIA), MO(UMLS), MO(MDIA), MO(SYMB), KC_RCTRL,
             KC_FN1,       KC_CAPS,
             KC_PSCREEN,
             KC_DEL,       KC_TAB,  KC_ENT
    ),
[COLE] = KEYMAP(  // COLEMAK
        // left hand
        KC_GRV,        KC_1,     KC_2,     KC_3,    KC_4,    KC_5,      LGUI(KC_SPC),
        KC_TAB,        KC_Q,     KC_W,     KC_F,    KC_P,    KC_G,      KC_PLUS,
        CTL_T(KC_ESC), KC_A,     KC_R,     KC_S,    KC_T,    KC_D,
        KC_LSFT,       KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,      KC_EQL,
        KC_LCTRL,      MO(MDIA), MO(SYMB), KC_LGUI, KC_LALT,
                                                             M(CPYPST), KC_ENT,
                                                                        KC_TRNS,
                                                    KC_SPC,  KC_BSPC,   KC_DEL,
        // right hand
             LGUI(KC_ENT),KC_6,    KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
             LSFT(KC_7),  KC_J,    KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_BSLS,
                          KC_H,    KC_N,     KC_E,     KC_I,     KC_O,     CTL_T(KC_QUOT),
             KC_MINS,     KC_K,    KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                                   MO(MDIA), MO(UMLS), MO(MDIA), MO(SYMB), KC_RCTRL,
             KC_FN1,      KC_CAPS,
             KC_PSCREEN,
             KC_DEL,      KC_TAB,  KC_ENT
    ),
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_SLSH, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_ASTR, KC_SLSH,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_PLUS, KC_MINS,
                         KC_EQL, KC_0,    KC_DOT,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_MUTE,
                 KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MSTP,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
// UMLAUTS
[UMLS] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, M(UMLEU),KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, M(UMLAE),M(UMLSZ),KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,
       KC_TRNS,  KC_TRNS, M(UMLUE),   KC_TRNS,    M(UMLOE),  KC_TRNS,    KC_TRNS,
                 KC_TRNS, M(SM_SMILE),M(SM_SMIRK),M(SM_SAD), M(SM_FROWN),KC_TRNS,
       KC_TRNS,  KC_TRNS, M(SM_LAUGH),M(SM_HEART),M(SM_KISS),M(SM_CRY),  KC_TRNS,
                          KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),               // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_TAP_TOGGLE(MDIA),               // FN2 - Momentary Layer 2 (Media)
    [3] = ACTION_LAYER_TAP_TOGGLE(UMLS)                // FN3 - Momentary Layer 3 (Umlauts)
};

static uint16_t cpypst_timer;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case UMLAE:
          if (record->event.pressed) {
            return MACRO(T(APP), D(LSFT), T(QUOT), U(LSFT), T(A), END);
          }
          break;
        case UMLOE:
          if (record->event.pressed) {
            return MACRO(T(APP), D(LSFT), T(QUOT), U(LSFT), T(O), END);
          }
          break;
        case UMLUE:
          if (record->event.pressed) {
            return MACRO(T(APP), D(LSFT), T(QUOT), U(LSFT), T(U), END);
          }
          break;
        case UMLSZ:
          if (record->event.pressed) {
            return MACRO(T(APP), T(S), T(S), END);
          }
          break;
        case UMLEU:
          if (record->event.pressed) {
            return MACRO(T(APP), T(EQL), T(C), END);
          }
          break;
        case SM_SMILE:
          if (record->event.pressed) {
            return MACRO(D(LSFT), T(SCLN), U(LSFT), T(MINS), D(LSFT), T(0), U(LSFT), END);
          }
          break;
        case SM_SMIRK:
          if (record->event.pressed) {
            return MACRO(T(SCLN), T(MINS), D(LSFT), T(0), U(LSFT), END);
          }
          break;
        case SM_CRY:
          if (record->event.pressed) {
            return MACRO(T(SCLN), T(MINS), D(LSFT), T(9), U(LSFT), END);
          }
          break;
        case SM_SAD:
          if (record->event.pressed) {
            return MACRO(D(LSFT), T(SCLN), U(LSFT), T(MINS), D(LSFT), T(9), U(LSFT), END);
          }
          break;
        case SM_HEART:
          if (record->event.pressed) {
            return MACRO(D(LSFT), T(COMM), U(LSFT), T(3), END);
          }
          break;
        case SM_LAUGH:
          if (record->event.pressed) {
            return MACRO(D(LSFT), T(SCLN), U(LSFT), T(MINS), D(LSFT), T(D), U(LSFT), END);
          }
          break;
        case SM_KISS:
          if (record->event.pressed) {
            return MACRO(D(LSFT), T(SCLN), U(LSFT), T(MINS), D(LSFT), T(8), U(LSFT), END);
          }
          break;
        case SM_FROWN:
          if (record->event.pressed) {
            return MACRO(D(LSFT), T(SCLN), U(LSFT), T(MINS), T(LBRC), END);
          }
          break;
        case L2CTRL:
          if (record->event.pressed) {
            layer_on(MDIA);
            register_code(KC_LCTL);
          } else {
            unregister_code(KC_LCTL);
            layer_off(MDIA);
          }
          break;
        case L2CTRLSFT:
          if (record->event.pressed) {
            layer_on(MDIA);
            register_code(KC_LCTL);
            register_code(KC_LSFT);
          } else {
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            layer_off(MDIA);
          }
          break;
        case CPYPST:
          if (record->event.pressed) {
            cpypst_timer = timer_read();
          } else {
            if (timer_elapsed(cpypst_timer) > 150) {
              return MACRO(D(LCTRL), T(INS), U(LCTRL), END);
            } else {
              return MACRO(D(LSFT), T(INS), U(LSFT), END);
            }
          }
          break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case SYMB:
            ergodox_right_led_1_on();
            break;
        case MDIA:
            ergodox_right_led_2_on();
            break;
        case UMLS:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
    if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
        ergodox_right_led_3_on();
    }

};
