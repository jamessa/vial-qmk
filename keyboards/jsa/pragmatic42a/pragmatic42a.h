/* Copyright 2021 James Sa
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

#pragma once

#include "quantum.h"

#define _x_ KC_NO

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, \
    k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, \
    k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, \
                   k44, k45, k46, k47, k48, k49                 \
) { \
  { k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c }, \
  { k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c }, \
  { k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c }, \
  { _x_, _x_, _x_, k44, k45, k46, k47, k48, k49, _x_, _x_, _x_ }  \
}
