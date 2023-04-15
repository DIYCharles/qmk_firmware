#include QMK_KEYBOARD_H

bool mouse_jiggle_mode = false;

// int rbgspeed = 25;

bool layer3alt = false;
bool lastlayer3alt = false;

enum custom_keycodes {
    PASS = SAFE_RANGE ,
    PASS2 ,
    GITPULL ,
    GITCHECKOUT,
    GITCLONE,
    GITSTATUS,
    GITADD,
    GITCOMMIT,
    GITPUSH,
    BLBRETH,
    PERETH,
    DQUOTA,
    QUOTA,
    MOUSEJIGGLERMACRO,
    // DECRBGSPD,
    // INCRBGSPD,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case PASS:
      if (record->event.pressed) {
          SEND_STRING("YEEEEEEET" SS_DELAY(500));
          tap_code(KC_ENTER);
      } else {
          // 
      }
    break;

    case PASS2:
      if (record->event.pressed) {
        SEND_STRING("YEEEEEEET" SS_DELAY(500));
        tap_code(KC_TAB);
        SEND_STRING("YEEEEEEET" SS_DELAY(500));
        tap_code(KC_ENTER);
      } else {
        // 
      }
    break;

    case GITPULL:
      if (record->event.pressed) {
        SEND_STRING("git pull" SS_DELAY(500));
        tap_code(KC_ENTER);
      } else {
        //  
      }
      break;

      case GITCHECKOUT:
        if (record->event.pressed) {
          SEND_STRING("git checkout " SS_DELAY(500));
          register_code(KC_LCTL);
          register_code(KC_LSFT);
          tap_code(KC_INSERT);
          unregister_code(KC_LSFT);
          unregister_code(KC_LCTL);
          tap_code(KC_ENTER);
        } else {
        }
      break;

      case GITCLONE:
        if (record->event.pressed) {
          SEND_STRING("git clone " SS_DELAY(500));
          register_code(KC_LCTL);
          register_code(KC_LSFT);
          tap_code(KC_INSERT);
          unregister_code(KC_LSFT);
          unregister_code(KC_LCTL);
          SEND_STRING(" " SS_DELAY(500));
          tap_code(KC_BSPC);
          SEND_STRING("YEEEEEEET" SS_DELAY(5000));
          tap_code(KC_ENTER);
        } else {
        }
      break;

      case GITCOMMIT:
        if (record->event.pressed) {
          SEND_STRING("git commit -am " SS_DELAY(500));
          tap_code16(KC_DQUO);
          tap_code16(KC_DQUO);
          tap_code(KC_LEFT);
        } else {
        }
      break;

      case GITSTATUS:
        if (record->event.pressed) {
          SEND_STRING("git status" SS_DELAY(500));
          tap_code(KC_ENTER);
        } else {
        }
      break;

      case GITADD:
        if (record->event.pressed) {
          SEND_STRING("git status");
          tap_code(KC_ENTER);
          SEND_STRING("git add");
        } else {
        }
      break;

      case GITPUSH:
        if (record->event.pressed) {
          SEND_STRING("git push" SS_DELAY(500));
          tap_code(KC_ENTER);
          SEND_STRING(" " SS_DELAY(500));
          tap_code(KC_BSPC);
          SEND_STRING("YEEEEEEET" SS_DELAY(500));
          tap_code(KC_ENTER);
        } else {
        }
      break;

      case PERETH:
        if (record->event.pressed) {
          tap_code16(KC_LEFT_PAREN);
          tap_code16(KC_RIGHT_PAREN);
          tap_code(KC_LEFT);
        } else {
        }
      break;

      case DQUOTA:
        if (record->event.pressed) {
          tap_code16(KC_DQUO);
          tap_code16(KC_DQUO);
          tap_code(KC_LEFT);
        } else {
        }
      break;

      case QUOTA:
        if (record->event.pressed) {
          tap_code(KC_QUOT);
          tap_code(KC_QUOT);
          tap_code(KC_LEFT);;
        } else {
        }
      break;

      case MOUSEJIGGLERMACRO:
        if (record->event.pressed) {
          if (!mouse_jiggle_mode) {
            mouse_jiggle_mode = true;
          } else {
            mouse_jiggle_mode = false;
          }
        } else {
        }
      break;
    }
    return true;
};

enum encoder_names {
  LEFT_HALF_ENC,
  RIGHT_HALF_ENC1,
  RIGHT_HALF_ENC2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ansi(
    KC_MUTE,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,            KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_PGDN, KC_PGUP,
    KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, KC_INS,  KC_PGUP,
    KC_F14,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  KC_PGDN,
    MO(3),  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_HOME, KC_END,
    MO(2),  KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,          KC_UP,
    MO(1),  KC_LCTL, KC_LGUI, KC_LALT, MO(1),   KC_SPC,  KC_SPC,                    MO(1),   KC_SPC,  KC_RALT, KC_RGUI,                   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [1] = LAYOUT_ansi(
    BL_STEP,          RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,          RGB_SPD, RGB_SPI,          _______, _______, _______, _______, _______, _______, _______,
    RGB_TOG, KC_LALT, RGB_SPD, RGB_SPI, VK_TOGG, _______, _______, _______,          _______, _______, PERETH, _______, _______, _______, _______, _______, _______, _______,
    RGB_MOD, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    MOUSEJIGGLERMACRO, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, QUOTA, DQUOTA,          _______, _______, _______,
    _______, _______,          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,          _______,          _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______,                   _______, _______, _______, _______
  ),

  [2] = LAYOUT_ansi(
    _______,          GITSTATUS, GITADD, GITCOMMIT, GITPUSH, _______, _______,          _______, _______,          _______, _______, _______, PASS2, PASS, _______, _______,
    _______, _______, GITCLONE, GITCHECKOUT, GITPULL, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,          _______, _______, _______,
    _______, _______,          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,          _______,          _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______,                   _______, _______, _______, _______
  ),

  [3] = LAYOUT_ansi(
    _______,          GITSTATUS, GITADD, GITCOMMIT, GITPUSH, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______, _______,
    _______, _______, GITCLONE, GITCHECKOUT, GITPULL, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,          _______, _______, _______,
    _______, _______,          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,          _______,          _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______,                   _______, _______, _______, _______
  )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == LEFT_HALF_ENC) {
      if(IS_LAYER_ON(3)) {
        if (clockwise) {
          tap_code(KC_TAB);
        } else {
          register_code(KC_LSFT);
          tap_code(KC_TAB);
          unregister_code(KC_LSFT);
        }
      } else {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
      }
    } else if (index == RIGHT_HALF_ENC1) {
      if (clockwise) {
          register_code(KC_LEFT_CTRL);
          tap_code(KC_KP_PLUS);
          unregister_code(KC_LEFT_CTRL);
      } else {
          register_code(KC_LEFT_CTRL);
          tap_code(KC_KP_MINUS);
          unregister_code(KC_LEFT_CTRL);
      }
    } else if (index == RIGHT_HALF_ENC2) {
      if (clockwise) {
          tap_code(KC_PGDN);
      } else {
          tap_code(KC_PGUP);
      }
    }
    return false;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
  if(IS_LAYER_ON(3)) {
    layer3alt = true;
  } else {
    layer3alt = false;
  }
  if (layer3alt) {
    register_code(KC_LALT);
  } else {
    if (!layer3alt && lastlayer3alt) {
      unregister_code(KC_LALT);
    }
  }
  lastlayer3alt = layer3alt;
  
  if (mouse_jiggle_mode) {
    tap_code(KC_NUM_LOCK);
    tap_code(KC_NUM_LOCK);
    tap_code(KC_MS_UP);
    tap_code(KC_MS_DOWN);
    tap_code(KC_MS_LEFT);
    tap_code(KC_MS_RIGHT);
    tap_code(KC_F24);
    tap_code(KC_F24);
  } else {
  }
}

void bootmagic_lite(void) {
  matrix_scan();
  wait_ms(DEBOUNCE * 2);
  matrix_scan();

  if (matrix_get_row(BOOTMAGIC_LITE_ROW_RIGHT) & (1 << BOOTMAGIC_LITE_COLUMN_RIGHT)) {
    // Jump to bootloader.
    bootloader_jump();
  }

  if (matrix_get_row(BOOTMAGIC_LITE_ROW_LEFT) & (1 << BOOTMAGIC_LITE_COLUMN_LEFT)) {
    // Jump to bootloader.
    bootloader_jump();
  }
}