/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

/*
  How to flash Q10 Keyboard:
  https://www.keychron.com/blogs/archived/how-to-factory-reset-or-flash-your-qmk-via-enabled-keychron-q10-keyboard

  1. Unplug the keyboard
  2. Take keycap off of right spacebar
  3. Press and hold the RESET button on the PCB
  4. Plug in the keyboard
  5. Compile and flash the firmware
     qmk compile --keyboard keychron/q10/ansi_encoder --keymap smypf
     qmk flash --keyboard keychron/q10/ansi_encoder --keymap smypf
  6. After the firmware is flashed press and hold FN + J + Z
*/

#include QMK_KEYBOARD_H

// clang-format off

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_89(
        KC_MPLY,  KC_ESC,            KC_F1,    KC_F2,            KC_F3,    KC_F4,         KC_F5,                    KC_F6,    KC_F7,           KC_F8,       KC_F9,   KC_F10,   KC_F11,   KC_F12,    KC_F13,    KC_F14,
        KC_F16,   KC_GRV,             KC_1,     KC_2,             KC_3,     KC_4,          KC_5,                     KC_6,     KC_7,            KC_8,        KC_9,     KC_0,  KC_MINS,   KC_EQL,  KC_BSPC,   KC_DEL,
        KC_F17,   KC_TAB,             KC_Q,     KC_W,             KC_E,     KC_R,          KC_T,                     KC_Y,     KC_U,            KC_I,        KC_O,     KC_P,  KC_LBRC,  KC_RBRC,  KC_BSLS,   KC_PGUP,
        KC_F18,   LCTL_T(KC_ESC),     KC_A,     KC_S,             KC_D,     KC_F,          KC_G,                     KC_H,     KC_J,            KC_K,        KC_L,  KC_SCLN,  KC_QUOT,             KC_ENT,    KC_PGDN,
        KC_F19,   SC_LSPO,            KC_Z,     KC_X,             KC_C,     KC_V,          KC_B,                     KC_B,     KC_N,            KC_M,     KC_COMM,   KC_DOT,  KC_SLSH,  SC_RSPC,    KC_UP,
        KC_F20,   KC_LCTL,         KC_LOPT,            LGUI_T(KC_BSPC),   KC_SPC, LCA_T(KC_ENT),            LT(1, KC_SPC),            RGUI_T(KC_TAB),                                   KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_89(
        RGB_TOG,  _______,   KC_BRID,  KC_BRIU,  KC_NO,           KC_NO,    RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU, _______,            _______,
        _______,  _______,  _______,  _______,  _______,         _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,         RGB_SAI,  RGB_SPI,   _______,  KC_LBRC,  KC_RBRC,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,         RGB_SAD,  RGB_SPD,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,          _______,            _______,
        _______,  _______,            _______,  _______,         _______,  _______,   _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,            _______,  LGUI_T(KC_DEL),  _______,                       _______,            _______,                      _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_89(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_F13,             KC_F14,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_DEL,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
        _______,  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_PGDN,
        _______,  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,  MO(WIN_FN),                     KC_SPC,             KC_RALT,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_89(
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,             _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  _______,  NK_TOGG,  _______,  _______,  _______,   _______,  _______,  _______,
        _______,  _______,  _______,            _______,  _______,  _______,                       _______,            _______,                       _______,  _______,  _______),
};

// TODO
// Prev / Next Track
// Volume Up & Down
// Ability to switch between options
#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif // ENCODER_MAP_ENABLE
