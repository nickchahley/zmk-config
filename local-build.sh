#!/bin/bash
zmk_app="/home/nikoli/personal/keyboard/zmk-firmware/zmk/app"
build_base="/home/nikoli/personal/keyboard/zmk-firmware/miryoku-zmk-swoop/build/swoop"
zmk_config="/home/nikoli/personal/keyboard/zmk-firmware/miryoku-zmk-swoop/config"
board="nice_nano_v2"

build_zmk () {
	west build --build-dir "${build_base}/$1" -b "$board" -- -DZMK_CONFIG="$zmk_config" -DSHIELD="$1"
	cp -v "${build_base}/$1/zephyr/zmk.uf2" "${build_base}/artifacts/$1.uf2"
}

# must be run from within zmk/app
cd "$zmk_app"

# stop if somethings fails to build 
build_zmk swoop_right && build_zmk swoop_left && build_zmk settings_reset

cd -
