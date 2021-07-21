/*
Copyright 2020 Dimitris Mantzouranis

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

bool caps = false;

int caps_leds[] = {30};
int caps_leds_size = sizeof(caps_leds) / sizeof(int);
int led_index;

// Layers
enum layer_names {
    _BASE,
    _FN1,
};

// Mapping to each layer
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /*      Row:         0          1          2          3        4         5        6         7        8        9          10         11         12         13         14         15        */
      [_BASE] = { {   KC_GESC,   KC_1,      KC_2,      KC_3,    KC_4,     KC_5,    KC_6,     KC_7,    KC_8,    KC_9,      KC_0,      KC_MINS,   KC_EQL,    KC_BSPC,   KC_NO,     KC_DEL  },
                  {   KC_TAB,    KC_Q,      KC_W,      KC_E,    KC_R,     KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,      KC_P,      KC_LBRC,   KC_RBRC,   KC_BSLASH, KC_NO,     KC_HOME },
                  {   KC_CAPS,   KC_A,      KC_S,      KC_D,    KC_F,     KC_G,    KC_H,     KC_J,    KC_K,    KC_L,      KC_SCLN,   KC_QUOT,   KC_NO,     KC_ENT,    KC_NO,     KC_END  },
                  {   KC_LSFT,   KC_NO,     KC_Z,      KC_X,    KC_C,     KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,   KC_NO,     KC_RSFT,   KC_UP,     KC_PSCR },
                  {   KC_LCTL,   KC_LGUI,   KC_LALT,   KC_NO,   KC_NO,    KC_NO,   KC_SPC,   KC_NO,   KC_NO,   KC_NO,     KC_RCTRL,  MO(_FN1),  KC_RALT,   KC_LEFT,   KC_DOWN,   KC_RGHT }
                },
      [_FN1] = {  {   KC_GRV,    KC_F1,     KC_F2,     KC_F3,   KC_F4,    KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_NO,     KC_NO,     KC_NO      },
                  {   KC_NO,     RGB_M_P,   RGB_M_B,   RGB_M_R, RGB_M_SW, RGB_M_T, RGB_SPD,  RGB_SPI, KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_PGUP    },
                  {   KC_NO,     KC_VOLD,   KC_VOLU,   KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     RGB_SAD,   RGB_SAI,   KC_NO,     KC_NO,     KC_NO,     KC_PGDOWN  },
                  {   KC_NO,     KC_NO,     KC_NO,     KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,   RGB_RMOD,  RGB_MOD,   KC_NO,     KC_NO,     KC_NO,     RGB_VAI,   RGB_TOG,   },
                  {   KC_NO,     KC_NO,     KC_NO,     KC_NO,   KC_NO,    KC_NO,   RESET,    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     RGB_HUI,   RGB_VAD,   RGB_HUD    }
               }
};


//colours hsv (for RGB FN mapping)
#define Red    {0,255,255}
#define Orange {28,255,255}
#define Yellow {43,255,255}
#define Green  {85,255,255}
#define Blue   {170,255,255}
#define Violet {193,255,255}
#define Sakura {242,171,255}
#define White  {0,0,255}
#define ______ {0,0,0}      //no colour

// start of RGB FN mapping
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    /*  Row:    0        1        2        3        4        5        6        7        8        9        10       11       12       13       14       15    */
    [_FN1] = {  White,   White,   White,   White,   White,   White,   White,   White,   White,   White,   White,   White,   White,   ______,           ______, \
                ______,  Green,   Green,   Green,   Green,   Green,   ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,           ______, \
                ______,  Red,     Red,     ______,  ______,  ______,  ______,  ______,  ______,  ______,  Blue,    Blue,             ______,           ______, \
                ______,           ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,           ______,  Blue,    Blue,   \
                ______,  ______,  ______,                             ______,                             ______,  ______,  ______,  Green,   Blue,    Green,  },
};

void set_layer_color(int layer) {

  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}
// End of RGB FN mapping


// Dip Switch fuctions.
void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {  // BT mode
                // do stuff
            } else {  // Cable mode
                // do stuff
            }
            break;
        case 1:
            if (active) {  // Win/Android mode
                           // do stuff
            } else {       // Mac/iOS mode
                           // do stuff
            }
            break;
    }
}

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    // debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
}

// Caps Lock Led Indicator
bool led_update_user(led_t led_state) {
    caps = led_state.caps_lock;
    return false;
}

// for both Caps Lock and RGB FN Colors
void rgb_matrix_indicators_user(void) {
    if (caps) {
        rgb_matrix_set_color(30, 255, 0, 0);
    }
    switch (biton32(layer_state)) {
    case _FN1:
      set_layer_color(_FN1);
      break;
    }
}
