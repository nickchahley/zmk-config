#!/bin/bash
if [[ "$#" == 0 ]]; then
	echo "Useage: $0 keyboard [parse, draw]"
	exit 1
fi
case "$2" in
	draw)
		draw=true
		;;
	parse)
		parse=true
		;;
	*)
		draw=true
		parse=true
		;;
esac
case "$1" in
	swoop)
		layout="LAYOUT_split_3x5_3"
		;;
	corne)
		layout="LAYOUT_split_3x6_3"
		;;
	*)
		echo "Unknown board"
		;;
esac

keymap=config/"$1".keymap
yaml=keymap-img/"$1".yaml
svg=keymap-img/"$1".svg

if $parse; then
	keymap parse -z "$keymap" > "$yaml"
fi
if $draw; then
		keymap draw --qmk-keyboard corne_rotated --qmk-layout LAYOUT_split_3x5_3 "$yaml" > "$svg"
fi
