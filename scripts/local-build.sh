#!/bin/bash
zmk_app="/home/nikoli/personal/keyboard/zmk-firmware/zmk/app"
build_base="/home/nikoli/personal/keyboard/zmk-firmware/zmk-config/build/swoop"
zmk_config="/home/nikoli/personal/keyboard/zmk-firmware/zmk-config/config"
board="nice_nano_v2"

p_flag=''

print_usage() {
  printf "Usage: ..."
}

while getopts 'p' flag; do
  case "${flag}" in
    p) p_flag='true' ;;
    *) print_usage
       exit 1 ;;
  esac
done


build_zmk () {
	if [ "$p_flag" = true ]; then
		echo "Pristine Build"
		west build --build-dir "${build_base}/$1" -p -b "$board" -- -DZMK_CONFIG="$zmk_config" -DSHIELD="$1" \
			&& cp -v "${build_base}/$1/zephyr/zmk.uf2" "${build_base}/artifacts/$1.uf2"
	else
		west build --build-dir "${build_base}/$1" -b "$board" -- -DZMK_CONFIG="$zmk_config" -DSHIELD="$1" \
			&& cp -v "${build_base}/$1/zephyr/zmk.uf2" "${build_base}/artifacts/$1.uf2"
	fi
}

# must be run from within zmk/app
cd "$zmk_app"

# '&&': stop if somethings fails to build 
build_zmk swoop_right \
	&& build_zmk swoop_left \
	&& build_zmk settings_reset

cd -
