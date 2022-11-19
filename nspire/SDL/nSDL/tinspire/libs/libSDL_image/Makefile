CC = nspire-gcc
AR = arm-none-eabi-ar
RANLIB = arm-none-eabi-ranlib
INCLUDE ?= -I../../../include
CFLAGS = -Wall -Wextra -Os -DLOAD_GIF -DLOAD_LBM -DLOAD_PCX -DLOAD_PNM -DLOAD_TGA -DLOAD_PNG -DLOAD_XCF -DLOAD_JPG

PREFIX=/tmp
TARGET = libSDL_image.a
SOURCES = \
	IMG.c \
	IMG_bmp.c \
	IMG_gif.c \
	IMG_jpg.c \
	IMG_lbm.c \
	IMG_pcx.c \
	IMG_png.c \
	IMG_pnm.c \
	IMG_tga.c \
	IMG_tif.c \
	IMG_webp.c \
	IMG_xcf.c \
	IMG_xpm.c \
	IMG_xv.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(AR) cr $@ $^
	$(RANLIB) $@

.c.o:
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

install-headers:
	cp SDL_image.h $(PREFIX)/include

clean:
	rm -f $(OBJECTS) $(TARGET)
