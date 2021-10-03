/* Copyright 2021 gtips
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

enum layer_names {
  _BASE,
  LAYER_2,
  LAYER_3,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST  MO(_ADJUST)

#define LO_ENT LT(LOWER, KC_ENT)
#define RA_SPC LT(RAISE, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung34(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,          KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    LSFT_T(KC_A),     LALT_T(KC_R),    LCTL_T(KC_S),    LGUI_T(KC_T),    KC_G,          KC_M,    RGUI_T(KC_N),    RCTL_T(KC_E),    RALT_T(KC_I),    RSFT_T(KC_O),
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,          KC_K,    KC_H,    KC_COMMA,   KC_DOT,   KC_QUOT,
                        LO_ENT,  XXXXXXX,          XXXXXXX, RA_SPC  
  ),

  [LAYER_2] = LAYOUT_reviung34(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,          KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    KC_A,     LALT_T(KC_R),    LCTL_T(KC_S),    KC_T,    KC_G,          KC_M,    KC_N,    RCTL_T(KC_E),    RALT_T(KC_I),    KC_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,          KC_K,    KC_H,    KC_COMMA,   KC_DOT,   KC_QUOT,
                        LO_ENT,  KC_LSHIFT,          KC_RGUI, RA_SPC  
  ),

  [LAYER_3] = LAYOUT_reviung34(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,          KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    LSFT_T(KC_A),     KC_R,    KC_S,    LGUI_T(KC_T),    KC_G,          KC_M,    RGUI_T(KC_N),    KC_E,    KC_I,    RSFT_T(KC_O),
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,          KC_K,    KC_H,    KC_COMMA,   KC_DOT,   KC_QUOT,
                        LO_ENT,  KC_LALT,          KC_RCTL, RA_SPC  
  ),

  [_LOWER] = LAYOUT_reviung34(
    KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX,            KC_PLUS, KC_7, KC_8, KC_9, KC_ASTR,
    LSFT_T(KC_F5), LALT_T(KC_F6),  LCTL_T(KC_F7), LGUI_T(KC_F8), RESET,              KC_MINS, LGUI_T(KC_4), LCTL_T(KC_5),  LALT_T(KC_6), LSFT_T(KC_0),
    KC_F1, KC_F2,  KC_F3, KC_F4, KC_SPC,              KC_SLSH, KC_1, KC_2, KC_3, KC_EQL,
                        _______, _______,              _______, _______
  ),

  [_RAISE] = LAYOUT_reviung34(
    KC_QUES, KC_LCBR, KC_RCBR, KC_PIPE, XXXXXXX,        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
    LSFT_T(KC_SLSH), LALT_T(KC_LBRC), LCTL_T(KC_RBRC), LGUI_T(KC_MINS), KC_UNDS,        KC_LEFT, LGUI_T(KC_DOWN), LCTL_T(KC_UP),   LALT_T(KC_RGHT), KC_RSHIFT,
    KC_BSLS, KC_LPRN,  KC_RPRN,  KC_GRV,  KC_TILD,        KC_DEL,  KC_BSPC, KC_TAB,  KC_ESC,  XXXXXXX,
                          _______, _______,        _______, _______
  ),
  
  [_ADJUST] = LAYOUT_reviung34(
    RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, RGB_TOG,       KC_BRIU,   KC_VOLU,   KC_MPLY,   KC_MNXT,   XXXXXXX,  
    RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD,XXXXXXX,       KC_BRID,   KC_VOLD,   KC_MPRV,   XXXXXXX,   XXXXXXX, 
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         TG(_BASE),  TG(LAYER_2),  TG(LAYER_3), XXXXXXX, XXXXXXX,
                              _______, _______,       _______, _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
