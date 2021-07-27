# Keychron K6 QMK Config

My [SonixQMK](https://github.com/SonixQMK/qmk_firmware) Keymap and config for the Keychron K6 RGB Hot-Swap "SN32F24x"

I have only included the files I have modified, so you will need to replace the files with the ones in SonixQMK after cloning the repro.

- `rules.mk` "Enabled NKRO_ENABLE and Disabled SLEEP_LED_ENABLE"
- `led_matrix.c` "Modified for Caps Lock indicator"
- `kaymaps\ansi\keymap.c` Customized key layout, Caps Lock indicator, and Layer Lighting effect for FN"
- `kaymaps\ansi\config_led.h` "Added the pin assignment for Caps Lock Indicator.
- `kaymaps\ansi\config.h` "Defined FORCE NKey Rollover for it to work, since there currently no EEPROM support yet."

A big thank you to the #keychrone Channel in [SonixQMK Discord](https://discord.gg/w6U7v4rw) community for helping me with getting my config the way it is.

Layer lighting copied from HorrorTroll's Keymap [Layer lighting Effect](https://github.com/HorrorTroll/qmk_firmware/tree/personal/keyboards/redragon/k552/rev1/keymaps/horrortroll)

```
Base
+-------------------------------------------------------------------------------+-----+
| ESC |  1  |  2  |  3  | 4  |  5  | 6  |  7 |  8 |  9 |  0 |  - |  = | BACKSP  | DEL |
+-------------------------------------------------------------------------------+-----|
|  TAB    |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \     | HOME|
+-------------------------------------------------------------------------------+-----|
| CAPSLCK   |  A |  S |  D |  F |  G |  H |  J |  K |  L | ; | ' |  RETURN      | END |
+-------------------------------------------------------------------------+-----+-----|
| LSHIFT     |  Z |  X |  C |  V |  B |  N |  M | , | . |  / |    RSHIFT  |  UP | PSCR|
+-------------------------------------------------------------------------+-----+-----|
|LCTRL| LGUI| LALT |            SPACE            | RCTRL | FN | RATL| LFT | DWN | RGT |
+-------------------------------------------------------------------------------------+
```
```
FN1
+-------------------------------------------------------------------------------+-----+
| ~  | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10 | F11 | F12 |           |     |
+-------------------------------------------------------------------------------+-----|
|       |  M1 | M2 | M3 | M4 | M5 |   |    |    |    |    |    |    |           | PGU |
+-------------------------------------------------------------------------------+-----|
|         | VOD | VOU |   |   |   |    |    |    |    | SAD | SAI |             | PGD |
+-------------------------------------------------------------------------+-----+-----|
|          |    |    |    |    |    |    |    |     |MOD+ |MOD- |         | VAI | TOG |
+-------------------------------------------------------------------------+-----+-----|
|     |     |      |            RESET            |       |    |     | HUI | VAD | HUD |
+-------------------------------------------------------------------------------------+
```