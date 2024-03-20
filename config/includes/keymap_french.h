/* Copyright 2015-2016 Jack Humbert
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

/* Modifying this work with MacOS local "french numeric"
 */

#pragma once

#include <dt-bindings/zmk/hid_usage.h>
#include <dt-bindings/zmk/hid_usage_pages.h>
#include <dt-bindings/zmk/modifiers.h>
#include <dt-bindings/zmk/keys.h>

// clang-format off

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ ² │ & │ é │ " │ ' │ ( │ - │ è │ _ │ ç │ à │ ) │ = │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │ A │ Z │ E │ R │ T │ Y │ U │ I │ O │ P │ ^ │ $ │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │ Q │ S │ D │ F │ G │ H │ J │ K │ L │ M │ ù │ * │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │ < │ W │ X │ C │ V │ B │ N │ , │ ; │ : │ ! │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define FR_SUP2 GRAVE   // ²
#define FR_AMPS N1    // &
#define FR_EACU N2    // é
#define FR_DQUO N3    // "
#define FR_SQT  N4    // '
#define FR_LPAR N5    // (
#define FR_MINUS N6    // -
#define FR_EGRV N7    // è
#define FR_UNDER N8    // _
#define FR_CCED N9    // ç
#define FR_AGRV N0    // à
#define FR_RPAR MINUS   // )
#define FR_EQUAL  EQUAL   // =
// Row 2
#define FR_A    Q    // A
#define FR_Z    W    // Z
#define FR_E    E    // E
#define FR_R    R    // R
#define FR_T    T    // T
#define FR_Y    Y    // Y
#define FR_U    U    // U
#define FR_I    I    // I
#define FR_O    O    // O
#define FR_P    P    // P
#define FR_CARET LBKT  // ^ (dead)
#define FR_DLLR  RBKT  // $
// Row 3
#define FR_Q    A    // Q
#define FR_S    S    // S
#define FR_D    D    // D
#define FR_F    F    // F
#define FR_G    G    // G
#define FR_H    H    // H
#define FR_J    J    // J
#define FR_K    K    // K
#define FR_L    L    // L
#define FR_M    SEMI // M
#define FR_UGRV SQT  // ù
#define FR_STAR STAR // *
// Row 4
#define FR_LABK STAR // <
#define FR_W    Z    // W
#define FR_X    X    // X
#define FR_C    C    // C
#define FR_V    V    // V
#define FR_B    B    // B
#define FR_N    N    // N
#define FR_COMMA M    // ,
#define FR_SEMI COMMA // ;
#define FR_COLON DOT   // :
#define FR_EXCL SLASH  // !

/* Shifted symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │   │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ° │ + │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │   │   │   │   │   │   │   │   │ ¨ │ £ │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │   │   │   │   │   │   │ % │ µ │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │ > │   │   │   │   │   │   │ ? │ . │ / │ § │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
#define FR_N1    LS(FR_AMPS) // 1
#define FR_N2    LS(FR_EACU) // 2
#define FR_N3    LS(FR_DQUO) // 3
#define FR_N4    LS(FR_SQT) // 4
#define FR_N5    LS(FR_LPAR) // 5
#define FR_N6    LS(FR_MINUS) // 6
#define FR_N7    LS(FR_EGRV) // 7
#define FR_N8    LS(FR_UNDER) // 8
#define FR_N9    LS(FR_CCED) // 9
#define FR_N0    LS(FR_AGRV) // 0
#define FR_DEG  LS(FR_RPAR) // °
#define FR_PLUS LS(FR_EQUAL)  // +
// Row 2
#define FR_DIAE LS(FR_CARET) // ¨ (dead)
#define FR_PND  LS(FR_DLLR)  // £
// Row 3
#define FR_PRCNT LS(FR_UGRV) // %
#define FR_MICR LS(FR_STAR) // µ
// Row 4
#define FR_RABK LS(FR_LABK) // >
#define FR_QUES LS(FR_COMM) // ?
#define FR_DOT  LS(FR_SEMI) // .
#define FR_FSLH LS(FR_COLON) // /
#define FR_SECT LS(FR_EXCL) // §

/* AltGr symbols
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │   │   │ ~ │ # │ { │ [ │ | │ ` │ \ │   │ @ │ ] │ } │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │ € │   │   │   │   │   │   │   │   │ ¤ │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │   │   │   │   │   │   │   │   │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │   │   │   │   │   │   │   │   │   │   │   │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
// Row 1
// #define FR_TILDE RA(FR_EACU) // ~ (dead)
#define FR_TILDE RA(FR_N) // ~ (dead) (interpret from AA kbd)
#define FR_HASH RA(FR_DQUO) // #
#define FR_LBRC RA(FR_SQT)  // {
#define FR_LBKT RA(FR_LPAR) // [
#define FR_PIPE RA(FR_MINUS) // |
#define FR_GRAVE  RA(FR_EGRV) // ` (dead)
#define FR_BSLH RA(FR_UNDER) // (backslash)
#define FR_AT   RA(FR_AGRV) // @
#define FR_RBKT RA(FR_RPAR) // ]
#define FR_RBRC RA(FR_EQUAL)  // }
// Row 2
#define FR_EURO RA(KC_E)   // €
#define FR_CURR RA(FR_DLLR) // ¤
