PLATFORM=nsp

default: all
.PHONY: default clean all

vpath %.a libs

LIBS = libSDL.a libSDL_image.a libSDL_gfx.a libjpeg.a libpng.a libz.a

all: .$(PLATFORM).stamp

BUILTIN_LIBS=

define get_lib_from_gcc #uh oh
	$(shell $(CC) -print-search-dirs | cut -f 1 | sed -r 's/^libraries: ?=?//g' | \
	 sed -r 's/^install: ?=?//g' | sed -r 's/^programs: ?=?//g' | tr ':' '\n' | \
	 { cat; echo $(shell dirname $(shell which $(CC)))/../lib/; } | \
	 xargs -i find {} -name '$(1)' 2>/dev/null | head -1)
endef

define if-dirty-arch
	$(shell \
	OTHERSTAMPS=$(filter-out ./.$(PLATFORM).stamp,$(wildcard ./.*.stamp)); \
	[ -f "$$OTHERSTAMPS" ] && [ "$$OTHERSTAMPS" !=  "" ] && echo "$(1)" || echo "$(2)")
endef

define if-no-stamp
	$(shell [ "$(wildcard ./.*.stamp)" = "" ] && echo "$(1)" || echo "$(2)")
endef


include Makefile.$(PLATFORM)

$(BUILTIN_LIBS):
	@mkdir -p lib
	cp $(call get_lib_from_gcc,$@) lib/$@


.$(PLATFORM).stamp: $(call if-dirty-arch,"stamp-clean $(LIBS)") $(call if-no-stamp,$(LIBS),"lib/") ./include
	@echo stamp less than = $<
	touch ./.$(PLATFORM).stamp -r lib

stamp-clean: clean
	@echo "cleaned files due to platform switch"

clean-data:
	@rm -f lib/*.a
	@rm -rf ./include
	@rm -f ./.*.stamp

clean: clean-data shared-clean
shared-clean:
	$(foreach mkfile, $(wildcard ./Makefile.*),	\
		$(MAKE) -f $(mkfile) platform-clean;	\
	)
