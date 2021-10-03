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
    KC_A,     KC_R,    KC_S,    KC_T,    KC_G,          KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
    LCTL_T(KC_Z),    LALT_T(KC_X),    KC_C,    KC_D,    KC_V,          KC_K,    KC_H,    KC_COMMA,   RALT_T(KC_DOT),   RCTL_T(KC_QUOT),
                        LO_ENT,  KC_LSHIFT,          KC_RGUI, RA_SPC  
  ),

  [_LOWER] = LAYOUT_reviung34(
    KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX,            KC_PLUS, KC_7, KC_8, KC_9, KC_ASTR,
    KC_F5, KC_F6,  KC_F7, KC_F8, RESET,              KC_MINS, KC_4, KC_5,  KC_6, KC_0,
    KC_F1, KC_F2,  KC_F3, KC_F4, KC_SPC,              KC_SLSH, KC_1, KC_2, KC_3, KC_EQL,
                        _______, _______,              _______, _______
  ),

  [_RAISE] = LAYOUT_reviung34(
    KC_QUES, KC_LPRN, KC_RPRN, KC_PIPE, XXXXXXX,        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
    KC_SLSH, KC_LCBR, KC_RCBR, KC_MINS, KC_UNDS,        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
    KC_BSLS, KC_LBRC, KC_RBRC, KC_GRV,  KC_TILD,        KC_DEL,  KC_BSPC, KC_TAB,  KC_ESC,  XXXXXXX,
                          _______, _______,        _______, _______
  ),
  
  [_ADJUST] = LAYOUT_reviung34(
    RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, RGB_TOG,       KC_BRIU,   KC_VOLU,   KC_MPLY,   KC_MNXT,   XXXXXXX,  
    RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD,XXXXXXX,       KC_BRID,   KC_VOLD,   KC_MPRV,   XXXXXXX,   XXXXXXX, 
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
                              _______, _______,       _______, _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
