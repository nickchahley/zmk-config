# zmk-config
My personal [ZMK firmware](https://github.com/zmkfirmware/zmk/) config for the [Swoop MX](https://github.com/jimmerricks/swoop) using a noname nice!nano v2 (nRF52840 MCU). Layout is based on [urob's zmk config](https://github.com/urob/zmk-config) and [Miryoku](https://github.com/manna-harbour/miryoku_zmk). If you're new and 3x5 or 3x6 keyboard, I highly recommend looking at urob's stuff, it is an elegant and well-documented source of inspiration, and his [timeless homerow mods](https://github.com/urob/zmk-config#timeless-homerow-mods) are the core of what makes a small keyboard layout work for me.

Thanks to [snicklepickles](https://github.com/snicklepickles/zmk-config) (who's repo I originally forked), and everyone else in the community who I've taken snippets and inspiration from. Hopefully you find some ideas here.

Github actions builds may or may not work, as I tend to build locally.


## local builds 
Building locally is much faster for testing and debugging. Paths in `scripts/local-build.sh` are absolute and hardcoded.

Requirements:
- initialize submodule: zmk-nodefree-config (`git submodule init`)
- [zmk toolchain](https://zmk.dev/docs/development/setup)
- install zephyr-sdk (likely to `~/.local/zephyr-sdk`)
- checkout zmk src with mousekeys PR

Use venv (ex. conda) of your choice to isolate west (I use the same one for qmk and west).
```bash
ZMK_HEAD=$(pwd)

# clone repo and initialize submodules
git submodule init

# install west into a venv
conda activate qmk
pip install --user -U west
west --version # verify installed

# install zephyr sdk
cd ~/.local
wget https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.16.3/zephyr-sdk-0.16.3_linux-x86_64.tar.xz
wget -O - https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.16.3/sha256.sum | shasum --check --ignore-missing
cd zephyr-sdk-0.16.3
./setup.sh

# back to wherever zmk repos are
cd "$ZMK_HEAD"

# setup zmk src, urob's fork contains PRs we use, like mouse
git clone git@github.com:urob/zmk.git && cd zmk 
west init -l app/
west update && west zephyr-export
pip3 install --user -r zephyr/scripts/requirements.txt
```

