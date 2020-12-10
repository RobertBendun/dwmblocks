# dwmblocks
Modular status bar for dwm written in C (with some status modules in Go). Functions created for my personal use are in folder blocks, feel free to use them in yours.

## Modifing blocks
The statusbar is made from text written to buffer by C functions, compiled with dwmblocks.
Blocks are added and removed by editing the blocks.h header file.
To change functions, you must recompile program.

## Signaling changes
This statusbar can update via signals. For example, the `volume` function has assosieted signal 10. Running `kill -44 $(pidof dwmblocks)` will update `volume` (add 34 to signal number in `blocks.h` file).

## Known issues
Currently to get this build to work on ArchLinux with emojis, installation of AUR package [libxft-bgra-git](https://aur.archlinux.org/packages/libxft-bgra-git/) is required.
