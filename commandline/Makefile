# Use the following 3 lines on Unix (uncomment the framework on Mac OS X):
USBFLAGS = `libusb-config --cflags`
USBLIBS = `libusb-config --libs` #-framework CoreFoundation

CC       ?= gcc
CFLAGS    = $(USBFLAGS) -O2 -Wall -Wextra -pedantic
LIBS      = $(USBLIBS)

PREFIX ?= /usr/local
bin_dir = ${DESTDIR}${PREFIX}/bin
man_dir = ${DESTDIR}${PREFIX}/man/man1

PROGRAMS = vusb-si2c vusb-si2cset

all: $(PROGRAMS)

.c.o:
	$(CC) $(CFLAGS) -c $<

si2c.o: si2c.c si2c-util.c si2c-util.h
si2c-util.o: si2c-util.c
si2cset.o: si2cset.c si2c-util.c si2c-util.h

vusb-si2c: si2c.o si2c-util.o
	$(CC) -o $@ $^ $(LIBS)

vusb-si2cset: si2cset.o si2c-util.o
	$(CC) -o $@ $^ $(LIBS)

clean:
	rm -f *.o $(PROGRAMS)

install:
	install -m 4755 $(PROGRAMS) $(bin_dir)
#	install -m 0644 man/vusb-si2cset.1 \
#	  $(man_dir)

uninstall:
	rm -f $(bin_dir)/vusb-si2c
	rm -f $(bin_dir)/vusb-si2cset
	rm -f $(man_dir)vusb-si2cset.1

.PHONY: all strip clean install uninstall
