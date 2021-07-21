# Keychron K6 QMK Config

My [SonixQMK](https://github.com/SonixQMK/qmk_firmware) Keymap for the Keychron K6 RGB Hot-Swap "SN32F24x"

I have only included the files I have modified, so you will need to replace the files with the ones in SonixQMK after cloning the repro.

- `rules.mk` "Enabled NKRO_ENABLE and Disabled SLEEP_LED_ENABLE"
- `led_matrix.c` "modified for Caps Lock indicator"
- `kaymaps\ansi` folder (with files `keymap.c, config.h, config_led.h, and config_led.c`) "only change keymap.c, has customized key layout, Caps Lock indicator, and Layer RGB effect for FN"
