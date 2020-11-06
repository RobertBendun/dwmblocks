PREFIX ?= /usr/local
CC ?= gcc

output: dwmblocks.c blocks.def.h blocks.h blocks/*.c
	${CC} -Wall -Wextra `pkg-config --cflags x11 --libs x11` blocks/*.c dwmblocks.c -o dwmblocks

clean:
	rm -f *.o *.gch dwmblocks
install: output
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	install -m 0755 dwmblocks $(DESTDIR)$(PREFIX)/bin/dwmblocks
uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/dwmblocks
