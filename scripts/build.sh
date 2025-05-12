#!/bin/bash

# TODO: usage
# TODO: mkdir artifacts if dne
# TODO: move settings reset to be its own shield
# TODO: steal stuff from urob's script

print_usage() {
  printf "Usage: [-p pristine] <shield name>"
}

p_flag=''
while getopts 'p' flag; do
  case "${flag}" in
    p) p_flag='true' ;;
    *) print_usage
       exit 1 ;;
  esac
done

if [[ ($# == 0 ) || ( $@ == "--help" ) || ( $@ == "-h" ) ]]
then
	echo "Usage: $0 <shield>"
	echo "Build firmware for shield using 'config/<shield>.conf'"
	echo "board is assumed nice_nano_v2"
	exit 1
fi
shield="$1"

[[ -z $HOST_CONFIG_DIR ]] && HOST_CONFIG_DIR="."
[[ -z $ZMK_APP ]] && ZMK_APP="../zmk/app"

build_base=$(realpath "$HOST_CONFIG_DIR/build/${shield}")
zmk_config=$(realpath "$HOST_CONFIG_DIR/config")
board="nice_nano_v2"


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

# +-------------------------+
# | AUTOMATE CONFIG OPTIONS |
# +-------------------------+

cd "$HOST_CONFIG_DIR"

# TODO: update this path to inclue/.. to test after getting corne working
if [[ -f config/combos.dtsi ]]; then
    # update maximum combos per key
    count=$(
        tail -n +10 config/combos.dtsi |
            grep -Eo '[LR][TMBH][0-9]' |
            sort | uniq -c | sort -nr |
            awk 'NR==1{print $1}'
    )
    sed -Ei "/CONFIG_ZMK_COMBO_MAX_COMBOS_PER_KEY/s/=.+/=$count/" config/*.conf
    echo "Setting MAX_COMBOS_PER_KEY to $count"

    # update maximum keys per combo
    count=$(
        tail -n +10 config/combos.dtsi |
            grep -o -n '[LR][TMBH][0-9]' |
            cut -d : -f 1 | uniq -c | sort -nr |
            awk 'NR==1{print $1}'
    )
    sed -Ei "/CONFIG_ZMK_COMBO_MAX_KEYS_PER_COMBO/s/=.+/=$count/" config/*.conf
    echo "Setting MAX_KEYS_PER_COMBO to $count"
fi
# must be run from within zmk/app
cd "$ZMK_APP"

# '&&': stop if somethings fails to build 
build_zmk "${shield}_right" \
	&& build_zmk "${shield}_left"
	# && build_zmk "settings_reset"

cd -
