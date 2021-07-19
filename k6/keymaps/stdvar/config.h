/* Copyright 2020 Adam Honse <calcprogrammer1@gmail.com>
 * Copyright 2020 Dimitris Mantzouranis <d3xter93@gmail.com>
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

#include "config_common.h"
#include "config_led.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x0C45
#define PRODUCT_ID      0x5004
#define DEVICE_VER      0x0001

#define MANUFACTURER    Keychron
#define PRODUCT         K6
#define DESCRIPTION     K6RGB

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 16

#define DIODE_DIRECTION COL2ROW
#define MATRIX_COL_PINS { A8, A9, A10, A11, A12, A13, A14, A15, B0, B1, B2, B3, B4, B5, B6, B7 }
#define MATRIX_ROW_PINS { D11, D10, D9, D8, D7 }

// Connects each switch in the dip switch to the GPIO pin of the MCU
#define DIP_SWITCH_PINS { D5, D6 }

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 10
#define TAPPING_TERM 200
