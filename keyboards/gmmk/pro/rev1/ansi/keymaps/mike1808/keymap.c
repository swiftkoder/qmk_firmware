/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>, Mikael Manukyan <arm.localhost@gmail.com>
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
#include "mike1808.h"

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [JK_ESC] = COMBO(jk_combo, KC_ESC),
};

enum tapdance_keycodes {
   TD_F2,
   TD_F3,
   TD_F7,
   TD_J,
   TD_V,
   TD_U,
   TD_SLSH,
   TD_LSFT,
   TD_RSFT,
   TD_LBRC,
   TD_RBRC,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_F2] = ACTION_TAP_DANCE_DOUBLE(KC_F2, LALT(KC_ENT)),
    [TD_F3] = ACTION_TAP_DANCE_DOUBLE(KC_F3, LGUI(KC_F3)),
    [TD_F7] = ACTION_TAP_DANCE_DOUBLE(KC_F7, LALT(KC_F7)),
    [TD_J] = ACTION_TAP_DANCE_DOUBLE(KC_J, RGUI(KC_E)),
    [TD_U] = ACTION_TAP_DANCE_DOUBLE(KC_U, RGUI(KC_O)),
    [TD_V] = ACTION_TAP_DANCE_DOUBLE(KC_V, RGUI(KC_F)),
    [TD_LSFT] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, LCTL(KC_A)),
    [TD_RSFT] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, RCTL(KC_E)),
    [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LGUI(KC_LBRC)),
    [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, LGUI(KC_RBRC)),
    [TD_SLSH] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, RGUI(KC_SLSH)),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right
    [MACOS] = LAYOUT(
       KC_ESC,  KC_F1,   TD(TD_F2),   TD(TD_F3),   KC_F4,   KC_F5,   S(KC_F6),   KC_F7,   KC_F8,   KC_F9,   KC_IJ_F10,  S(LGUI(KC_F)),  RALT(KC_F12),  RGUI(KC_BSPC),       TO(LINUX),
       KC_GRV,  KC_1,    KC_2,        KC_3,        KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,             KC_MINS,        KC_EQL,        KC_BSPC,             LALT(KC_F7),
       KC_TAB,  KC_Q,    KC_W,        KC_E,        KC_R,    KC_T,    KC_Y,    TD(TD_U),KC_I,    KC_O,    KC_P,             TD(TD_LBRC),    TD(TD_RBRC),   KC_BSLS,             RGUI(KC_Z),
       KC_HYPR, KC_A,    KC_S,        KC_D,        KC_F,    KC_G,    KC_H,    TD(TD_J),KC_K,    KC_L,    KC_SCLN,          KC_QUOT,                       KC_ENT,              RGUI(KC_V),
       TD(TD_LSFT),      KC_Z,        KC_X,        KC_C,    TD(TD_V),KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,           TD(TD_SLSH),                   TD(TD_RSFT), KC_UP,  RGUI(KC_C),
       KC_LGUI,          KC_LCTL,     KC_LALT,                       KC_SPC,                             KC_RALT,          TT_FN,      KC_RGUI,       KC_LEFT,     KC_DOWN,KC_RGHT
    ),

    [LINUX] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           TO(MACOS),
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          RCTL(KC_Z),
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           RCTL(KC_V),
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   RCTL(KC_C),
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, TT_FN, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [FUNCTIONS] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, HYPR(KC_L),          _______,
        _______, RGB_TOG, RGB_VAI, RGB_VAD, RGB_HUI, _______, _______, _______, _______, _______, _______, _______, _______, _______,          HYPR(KC_H),
        _______, _______, _______, _______, LCTL(KC_R), RALT(KC_F12), _______, _______, _______, _______, _______, _______, _______,    RESET, HYPR(KC_QUOT),
        _______, _______, _______, LCTL(KC_D), S(LGUI(KC_F)), _______, _______, _______, _______, _______, _______, _______,          _______, HYPR(KC_B),
        _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, HYPR(KC_N),
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),
};

#ifdef RGB_MATRIX_LEDMAPS_ENABLED

#define ______ {0, 0, 0}

const ledmap PROGMEM ledmaps[] = {
         //  LU = Left Underglow, RU = Right Underglow
         //  LU_1    ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)  RU_1
         //  LU_2    ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del       RU_2
         //  LU_3    Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp         RU_3
         //  LU_4    Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn         RU_4
         //  LU_5    Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End          RU_5
         //  LU_6    Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right        RU_6
    [MACOS] = RGB_MATRIX_LAYOUT_LEDMAP(
          SPRING,    SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING,         SPRING,    SPRING,
          SPRING,    SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING,         SPRING,    SPRING,
          SPRING,    SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING,         SPRING,    SPRING,
          SPRING,    SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING,         SPRING,         SPRING,    SPRING,
          SPRING,    SPRING,         SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING, SPRING,         SPRING, SPRING, SPRING,    SPRING,
          SPRING,    SPRING, SPRING, SPRING,                         SPRING,                         SPRING, SPRING, SPRING, SPRING, SPRING, SPRING,    SPRING
    ),

    [LINUX] = RGB_MATRIX_LAYOUT_LEDMAP(
          GREEN,    GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,         GREEN,    GREEN,
          GREEN,    GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,         GREEN,    GREEN,
          GREEN,    GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,         GREEN,    GREEN,
          GREEN,    GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,         GREEN,         GREEN,    GREEN,
          GREEN,    GREEN,         GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,         GREEN, GREEN, GREEN,    GREEN,
          GREEN,    GREEN, GREEN, GREEN,                         GREEN,                         GREEN, GREEN, GREEN, GREEN, GREEN, GREEN,   GREEN
    ),

    [FUNCTIONS] = RGB_MATRIX_LAYOUT_LEDMAP(
          ORANGE,   ORANGE,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,   ORANGE,
          ORANGE,   ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,    ORANGE,
          ORANGE,   ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, RED,             ______,   ORANGE,
          ORANGE,   ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,         ______,    ORANGE,
          ORANGE,   ______,         ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______, ______, ______,    ORANGE,
          ORANGE,   ______, ______, ______,                         ______,                         ______, ______, ______, ______, ______, ______,    ORANGE
    ),
};

#endif // RGB_MATRIX_LEDMAPS_ENABLED
// clang-format on
