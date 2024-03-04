# zmk-config
[ZMK firmware](https://github.com/zmkfirmware/zmk/) config for the [Swoop MX](https://github.com/jimmerricks/swoop).

## requires
- zmk/zmkfirmware on mousekeys PR
- install zephyr-sdk (likely to `~/.local/zephyr-sdk`)
- initialize submodule: zmk-nodefree-config (`git submodule init`)

```bash
# initialize zmk-config submodules
git submodule init

# checkout mouskeys PR (assuming zmk src repo is one above)
cd ../zmk 
git fetch origin pull/2027/head:mousekeyspr
git switch mousekeyspr
```

## Features
- [Miryoku](https://github.com/manna-harbour/miryoku) keyboard layout
- [urob's timeless homerow mods](https://github.com/urob/zmk-config#timeless-homerow-mods) (`config/includes`)

## Todo
- Add mouse emulation layer

