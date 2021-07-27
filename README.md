# Keychron K6 QMK Config

My [SonixQMK](https://github.com/SonixQMK/qmk_firmware) Keymap and config for the Keychron K6 RGB Hot-Swap "SN32F24x"

I have only included the files I have modified, so you will need to replace the files with the ones in SonixQMK after cloning the repro.

- `rules.mk` "Enabled NKRO_ENABLE and Disabled SLEEP_LED_ENABLE"
- `led_matrix.c` "Modified for Caps Lock indicator"
- `kaymaps\ansi\keymap.c` Customized key layout, Caps Lock indicator, and Layer Lighting effect for FN"
- `kaymaps\ansi\config_led.h` "Added the pin assignment for Caps Lock Indicator.

A big thank you to the #keychrone Channel in [SonixQMK Discord](https://discord.gg/w6U7v4rw) community for helping me with getting my config the way it is.

Layer lighting copied from HorrorTroll's Keymap [Layer lighting Effect](https://github.com/HorrorTroll/qmk_firmware/tree/personal/keyboards/redragon/k552/rev1/keymaps/horrortroll)
