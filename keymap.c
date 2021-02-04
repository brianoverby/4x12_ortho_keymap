#include QMK_KEYBOARD_H
#include "keymap_danish.h"

enum keymap_layers {
  _BASE,
  _GAME,
  _LOWER,
  _RAISE,
  _FN,
  _SYSTEM
};

enum keymap_custom_keycodes {
  COMM = SAFE_RANGE,     // , | <
  DOT,                   // . | >
  SLSH,                  // / | ?
  SCLN,                  // ; | :
  QUOT,                  // ' | "
  WNTG,                  // WinKey toggle keycode
  MACTG,                 // MacOS toggle keycode
  NEW_SAFE_RANGE
};

/* Define mod keys */
#define GAME TG(_GAME)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FN)
#define RSET RESET


// For Win key and game mode toggle
bool winkey_enabled = true;
bool gamemode_enabled = false;
bool mac_layout = false;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_planck_grid(
        KC_TAB,  DK_Q,    DK_W,    DK_E,    DK_R,    DK_T,    DK_Y,    DK_U,    DK_I,    DK_O,    DK_P,    KC_BSPC,
        KC_ESC,  DK_A,    DK_S,    DK_D,    DK_F,    DK_G,    DK_H,    DK_J,    DK_K,    DK_L,    SCLN,    QUOT,
        KC_LSFT, DK_Z,    DK_X,    DK_C,    DK_V,    DK_B,    DK_N,    DK_M,    COMM,    DOT,     SLSH,    KC_ENT,
        FN,      KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    [_GAME] = LAYOUT_planck_grid(
        DK_1,    DK_Q,    DK_W,    DK_E,    DK_R,    DK_T,    DK_Y,    DK_U,    DK_I,    DK_O,    DK_P,    KC_BSPC,
        _______, DK_A,    DK_S,    DK_D,    DK_F,    DK_G,    DK_H,    DK_J,    DK_K,    DK_L,    SCLN,    QUOT,
        _______, DK_Z,    DK_X,    DK_C,    DK_V,    DK_B,    DK_N,    DK_M,    COMM,    DOT,     SLSH,    KC_ENT,
        _______, DK_4,    DK_3,    DK_2,    LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    [_LOWER] = LAYOUT_planck_grid(
        DK_TILD, DK_EXLM, DK_AT,   DK_HASH, DK_DLR,  DK_PERC, DK_CIRC, DK_AMPR, DK_ASTR, DK_LPRN, DK_RPRN, KC_BSPC,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DK_UNDS, DK_PLUS, DK_LCBR, DK_RCBR, DK_ACUT,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DK_BSLS, DK_PIPE, DK_MINS, DK_EQL,  DK_LBRC, DK_RBRC, _______,
        _______, KC_LCTL, KC_LALT, KC_LGUI, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_RAISE] = LAYOUT_planck_grid(
        DK_GRV,  DK_1,    DK_2,    DK_3,    DK_4,    DK_5,    DK_6,    DK_7,    DK_8,    DK_9,    DK_0,    KC_BSPC,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DK_DIAE,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______,
        _______, KC_LCTL, KC_LALT, KC_LGUI, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU,  KC_MPLY
    ),

    [_FN] = LAYOUT_planck_grid(
        KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  XXXXXXX, KC_PSCR, DK_ARNG,
        KC_DEL,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DK_AE,   DK_OSTR,
        _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
        _______, KC_LCTL, KC_LALT, KC_LGUI, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),

    [_SYSTEM] = LAYOUT_planck_grid(
        XXXXXXX, XXXXXXX, WNTG,    XXXXXXX, RSET,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GAME,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MACTG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};



layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _SYSTEM);
}

// Send keycodes matching the legend on the keycaps (US keycaps, Danish keyboard layout in OS)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case COMM:    // , | <
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          if(mac_layout) {
            unregister_code16(KC_LSFT);  // Remove shift before sending the keycode
            register_code16(KC_NUBS);     // This is < on Danish Mac keyboard
            register_code16(KC_LSFT);
          } else {
            unregister_code16(KC_LSFT);  // Remove shift before sending the keycode
            register_code16(DK_LABK);
            register_code16(KC_LSFT);
          }            
        } else {
          register_code16(KC_COMM);
        }
      } else {
        unregister_code16(KC_GRV);
        unregister_code16(DK_LABK);
        unregister_code16(KC_COMM);
      }
      return false;
      break;

    case DOT:    // . | >
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          if(mac_layout) {
            register_code16(KC_GRV);
          } else {
            register_code16(DK_RABK);
          }
        } else {
          register_code16(KC_DOT);
        }
      } else {
        unregister_code16(KC_GRV);
        unregister_code16(DK_RABK);
        unregister_code16(KC_DOT);
      }
      return false;
      break;

    case SLSH:    // / | ?
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code16(DK_QUES);
        } else {
          register_code16(DK_SLSH);
        }
      } else {
        unregister_code16(DK_QUES);
        unregister_code16(DK_SLSH);
      }
      return false;
      break;

    case SCLN:    // ; | :
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code16(DK_COLN);
        } else {
          register_code16(DK_SCLN);
        }
      } else {
        unregister_code16(DK_COLN);
        unregister_code16(DK_SCLN);
      }
      return false;
      break;

    case QUOT:    // ' | "
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code16(DK_DQUO);
        } else {
          register_code16(DK_QUOT);
        }
      } else {
        unregister_code16(DK_DQUO);
        unregister_code16(DK_QUOT);
      }
      return false;
      break;
    
    case WNTG:
      if (record->event.pressed) { // Toggle Windows Key
        winkey_enabled = !winkey_enabled;
      }
      return false;
      break;
    
    case KC_LGUI: // Check if Windows Key is disabled 
      if (!winkey_enabled) {
        return false;
      } else {
        return true;
      }
      break;
    
    case GAME:
      if (record->event.pressed) { // Toggle game mode
        gamemode_enabled = !gamemode_enabled;
      }
      return false;
      break;
    
    case MACTG:
      if (record->event.pressed) { // Toggle Windows / Mac layout
        mac_layout = !mac_layout;
      }
      return false;
      break;
    
    case DK_TILD: // Send TAB, when game mode is enabled else send ~ or `
    case DK_GRV:
      if(gamemode_enabled) {
        if (record->event.pressed) {
          register_code(KC_TAB);
        } else {
          unregister_code(KC_TAB);
        }
        return false;
      } else {
        return true;
      }
      break;

    case DK_AT:
      if(mac_layout) {
        if (record->event.pressed) {
          register_code16(LALT(KC_NUHS));
        } else {
          unregister_code16(LALT(KC_NUHS));
        }
        return false;
      } else {
        return true;
      }
      break;
    
    case DK_DLR:
      if(mac_layout) {
        if (record->event.pressed) {
          register_code16(LSFT(LALT(KC_3)));
        } else {
          unregister_code16(LSFT(LALT(KC_3)));
        }
        return false;
      } else {
        return true;
      }
      break;
    
    case DK_BSLS:
      if(mac_layout) {
        if (record->event.pressed) {
          register_code16(LSFT(LALT(KC_7)));
        } else {
          unregister_code16(LSFT(LALT(KC_7)));
        }
        return false;
      } else {
        return true;
      }
      break;

    case DK_PIPE:
      if(mac_layout) {
        if (record->event.pressed) {
          register_code16(LALT(DK_I));
        } else {
          unregister_code16(LALT(DK_I));
        }
        return false;
      } else {
        return true;
      }
      break;

    case DK_LCBR:
      if(mac_layout) {
        if (record->event.pressed) {
          register_code16(LSFT(LALT(KC_8)));
        } else {
          unregister_code16(LSFT(LALT(KC_8)));
        }
        return false;
      } else {
        return true;
      }
      break;

    case DK_RCBR:
      if(mac_layout) {
        if (record->event.pressed) {
          register_code16(LSFT(LALT(KC_9)));
        } else {
          unregister_code16(LSFT(LALT(KC_9)));
        }
        return false;
      } else {
        return true;
      }
      break;

  }
  return true;
};
