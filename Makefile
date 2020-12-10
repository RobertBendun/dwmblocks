PREFIX ?= /usr/local
CC ?= gcc

output: dwmblocks.c blocks.h blocks/*.c _cgo_export.h sunrise.a
	${CC} -Wall -Wextra `pkg-config --cflags x11 --libs x11` blocks/*.c sunrise.a -lpthread dwmblocks.c -o dwmblocks

clean:
	rm -rf _obj/ *.o *.gch dwmblocks sunrise.a sunrise.h _cgo_export.h

install: output
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	install -m 0755 dwmblocks $(DESTDIR)$(PREFIX)/bin/dwmblocks

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/dwmblocks

_cgo_export.h: blocks/sunrise.go
	go tool cgo -exportheader $@ $^

sunrise.a: blocks/sunrise.go
	go build -buildmode=c-archive $^
