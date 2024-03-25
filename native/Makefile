# Build options
# Running ./configure --help from the top-level source directory will print usage information for configure.
# In most cases, the only options which should be needed are:
#
# --prefix, 
#  used to control where musl will be installed.
#  The prefix for musl defaults to /usr/local/musl rather than /usr/local to
#  avoid breaking an existing non-musl environment on the host.
#  If musl will be used as the primary system libc, prefix should usually be set to /usr or /.
#
#
# --syslibdir,
#  used to specify the location at which the dynamic linker should be installed and found at runtime.
#  The default of /lib should only be overridden when installing in /lib is impossible,
#  since the pathname of the dynamic linker is stored in all dynamic-linked executables,
#  and executables using non-standard paths for the dynamic linker may be difficult to deploy on other systems.
#
# Both --prefix and --syslibdir should reflect the final runtime location where musl will be installed. If musl should be installed to a different location to prepare a package file or new target system image, the DESTDIR variable can be set when running make install. In this case, DESTDIR will be prepended to all installation paths, but will not be saved anywhere in the files installed.
#
#
# --prefix=<path> Where to install musl.
#  	A good choice is something like $HOME/musl.
# --exec-prefix=<path> This is where the musl-gcc wrapper gets installed to.
#  	It should point to somewhere in your PATH. A good choice is something like $HOME/bin.
# --syslibdir=<path> This is where the dynamic linker gets installed into.
#  	The default is /lib; this path will be baked into binaries built by musl-gcc,
#  	so you should not alter it if you want your dynamic binaries to be portable.
#  	Installing to /lib on most systems requires root privileges,
#  	so a typical choice for non-root users would be $HOME/musl/lib.





MUSL_SRC_URL := 'https://musl.libc.org/releases/musl-1.2.4.tar.gz'

MUSL_PREFIX := $(CURDIR)/musl-install
MUSL_EXEC_PREFIX := $(CURDIR)/musl-install/
MUSL_LIB_PREFIX := $(CURDIR)/musl-install/lib
export PATH := $(CURDIR)/musl-install/bin:$(PATH)

MUSL_GCC := musl-gcc -L $(CURDIR)/musl-install/lib -I $(CURDIR)/musl-install/include
none:
	@echo "PWD is " $(CURDIR)
	@echo "Valid target [none/download/build-musl/init/test/clean-test]"

download:
	mkdir -p musl-src
	wget $(MUSL_SRC_URL) -O musl-src.tar.gz 
	tar -xzf musl-src.tar.gz --strip-components 1 -C musl-src 
	rm -f musl-src.tar.gz
	# cd musl-src
	echo $(CURDIR)
# https://wiki.musl-libc.org/getting-started.html
build-musl:
	mkdir -p musl-build $(MUSL_PREFIX) $(MUSL_LIB_PREFIX) $(MUSL_EXEC_PREFIX)
	cd musl-build &&\
	../musl-src/configure \
		--enable-debug \
		--prefix=$(MUSL_PREFIX) \
		--exec-prefix=$(MUSL_EXEC_PREFIX) \
		--syslibdir=$(MUSL_LIB_PREFIX) && \
	make && make install
# https://github.com/rofl0r/musl/blob/master/INSTALL
init: download build-musl

.PHONY: test
test: build-musl
	cd test &&\
	$(MUSL_GCC) -ggdb -Og -Wall *.c &&\
	./a.out 
test-static: build-musl
	cd test &&\
	$(MUSL_GCC) -ggdb -Og -Wall --static *.c &&\
	./a.out 
debug:test
	tgdb test/a.out

clean-test:
	cd test &&\
	rm -f *.out *.o
	


clean-download:
	rm -rf musl-src
clean-build-musl:
	rm -rf musl-build $(MUSL_PREFIX)
clean:clean-download clean-build-musl clean-test
	
