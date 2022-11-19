GCC = nspire-gcc
AR = arm-none-eabi-ar
GCCFLAGS = -Os -Wall -W -nostdlib -s -I../libz/

PREFIX=/tmp

OBJCOPY := "$(shell which arm-elf-objcopy 2>/dev/null)"
ifeq (${OBJCOPY},"")
	OBJCOPY := arm-none-eabi-objcopy
endif
OBJS = png.o pngerror.o pngget.o pngmem.o \
	pngread.o pngrio.o pngrtran.o pngrutil.o pngset.o \
	pngtrans.o
DISTDIR = .
vpath %.tns $(DISTDIR)

all: $(OBJS)
	$(AR) rcs libpng.a $(OBJS)

%.o: %.c
	$(GCC) $(GCCFLAGS) -c $<

install-headers:
	cp pngconf.h png.h $(PREFIX)/include
\
clean:
	rm -f *.o *.elf
	rm -f libpng.a
