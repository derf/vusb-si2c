# Use the following 3 lines on Unix (uncomment the framework on Mac OS X):
USBFLAGS = `libusb-config --cflags`
USBLIBS = `libusb-config --libs` #-framework CoreFoundation

CC       ?= gcc
CFLAGS    = $(USBFLAGS) -O2 -Wall -Wextra -pedantic
LIBS      = $(USBLIBS)

PREFIX ?= /usr/local
bin_dir = ${DESTDIR}${PREFIX}/bin
man_dir = ${DESTDIR}${PREFIX}/man/man1

PROGRAMS = vusb-si2c

all: $(PROGRAMS)

.c.o:
	$(CC) $(CFLAGS) -c $<

si2c.o: si2c.c si2c-util.c si2c-util.h
si2c-util.o: si2c-util.c

vusb-si2c: si2c.o si2c-util.o
	$(CC) -o $@ $^ $(LIBS)

clean:
	rm -f *.o $(PROGRAMS)

install:
	install -m 4755 $(PROGRAMS) $(bin_dir)
#	install -m 0644 man/vusb-si2cset.1 \
#	  $(man_dir)

uninstall:
	rm -f $(bin_dir)/vusb-si2c

.PHONY: all strip clean install uninstall
