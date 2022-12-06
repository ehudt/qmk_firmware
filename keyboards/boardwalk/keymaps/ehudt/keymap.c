/*
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
enum layer {
    _BASE,
    _POK3R,
    _ASSOC,
    _WAIFU
};

#define ASSOC MO(_ASSOC)
#define POK3R MO(_POK3R)
#define SPC_WAIFU LT(_WAIFU, KC_SPC)
// Mac sleep
#define __SLEEP S(LCTL(KC_POWER))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | [      | ]      | \      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | CAP LK | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | "      | ENTER  | PG UP  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | SHIFT  | UP     | PG DN  |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | POK3R  | LALT   | LGUI   |      SPACE      | ASSOC  |        SPC      | RGUI   | RALT   | LEFT   | DOWN   | RIGHT  |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_BASE] = LAYOUT_2u1u2u_arrow(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, POK3R, KC_LALT, KC_LGUI,      KC_SPC,      KC_SPC,        ASSOC,       KC_RGUI, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /* Pok3r-compatible layer, media buttons were shifted to be more ergonomic on ortho.
    */
     [_POK3R] = LAYOUT_2u1u2u_arrow(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,     KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, KC_PSCR, KC_SLCK, KC_PAUS, _______,
        _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,     _______,      _______,     _______,      _______, _______, _______, _______, _______
    ),
    /* Associative layer, plus explicit arrows
    M,H - minus, hyphen. P - plus, Q - double quote. A - apostrophe(single-quote). U - underscore. G - grave accent(`).
    R,T - round brackets
    S,D - square brackets
    C,V - curly brackets
    missing - Tilde (~) is accessible by grave+shift, as T is taken by square brackets.
    renamed - F (follow) for pipe operator
    */
    [_ASSOC] = LAYOUT_2u1u2u_arrow(
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, KC_QUOT, KC_MINS,  KC_EQL, KC_LPRN, KC_RPRN, _______, KC_UNDS, KC_PGUP, KC_HOME, KC_PLUS, _______, _______, _______,
        _______, KC_DQUO, _______,  KC_DEL, KC_PIPE,  KC_GRV, _______, _______, KC_PGDN,  KC_END, _______, _______, _______, _______,
        _______, _______, _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_MINS, _______, _______, _______, _______, _______, _______,
        RESET,   _______, _______, _______,     _______,      _______,     _______,      _______, _______, _______, _______, _______
    ),
    [_WAIFU] = LAYOUT_2u_arrow(
        RESET,   _______, _______, _______, _______, RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_ACL2, KC_ACL1, KC_ACL0, RGB_HUD, RGB_HUI, _______, KC_MS_U, _______, _______, _______, _______, _______,
        _______, _______, KC_BTN3, KC_BTN2, KC_BTN1, RGB_SAD, RGB_SAI, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,     _______,      _______,     _______,      _______, _______, _______, _______, _______
    )
};
