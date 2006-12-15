# Linux Makefile for EPANET

# This will build EPANET as a shared object library (libepanet-gcc.so)
# under Linux/Unix,  and a standalone executable (epanet-gcc) that is
# linked  to this library.

# The following targets are defined:
# make
#     -Builds libepanet-gcc.so, epanet-gcc
# make install
#     -Creates shell wrapper runepanet.sh that executes epanet-gcc.exe.
#      The runepanet.sh wrapper simply exports
#      environment variables that help locate the runtime library,
#      allowing you to specify your own library locations.
#     -Installs epanet-gcc and runepanet.sh
#      in <prefix>/bin, where <prefix> defaults to ~ (and can be set
#      below to something different - see "Install directories")
#     -Installs libepanet-gcc.so in <prefix>/lib
#     -Installs epanet2.h in <prefix>/include.  This is the required
#      header file for the EPANET programmer's toolkit, and thus
#      <prefix>/include should be on your CPP include search path
#      for subsequent use of the toolkit and linking with the
#      library libepanet-gcc.so
# make clean
#     -Removes object and library files, returning the build directory
#      to its pristine state.
# make uninstall
#     -Undoes 'make install'
# make check
#     -Checks the installation by running epanet-gcc against defined
#      test networks and comparing the results quantitatively to a database
#      of known correct results.  Reports comparison statistics and
#      pass/fail status for each test.

# You may wish to change the install path 'prefix',
# or the compiler flags, but these defaults should be fine.

SHELL = /bin/sh

# Target filenames
epanetrootname = epanet-gcc
libname = lib$(epanetrootname).so
exename = $(epanetrootname)
# Shell wrapper
runcmdname = runepanet.sh
# Location of EPANET toolkit includes
epanetincludedir = ../../include
# Search path for sources
epanetsrcdir = ../../src
VPATH = $(epanetsrcdir)

# Install directories
prefix = ~
exec_prefix = $(prefix)
srcdir = .
libdir = $(exec_prefix)/lib
bindir = $(exec_prefix)/bin
includedir = $(prefix)/include
datarootdir = $(prefix)/share
docdir = $(datarootdir)/doc/epanet

# Compiler and flags
CC = gcc
CFLAGS = -g -O -fPIC
CPPFLAGS = -I $(srcdir) -I $(epanetincludedir)
LDFLAGS = -L . -W1,-rpath,$(libdir) -lm

# Installer
INSTALL = install
INSTALL_PROGRAM = $(INSTALL)
INSTALL_DATA = $(INSTALL) -m 644

# Files for the shared object library
epanet_objs=toolkit.o hash.o hydraul.o inpfile.o input1.o input2.o \
	    input3.o mempool.o output.o quality.o report.o \
	    rules.o smatrix.o
# Epanet main program
epanet_main_obj=epanet.o
# Epanet header files
epanet_heads=enumstxt.h funcs.h hash.h mempool.h text.h toolkit.h types.h vars.h
# Epanet main program header files
epanet_main_heads = $(epanetincludedir)/epanet2.h

.PHONY: all
all: $(libname) $(exename)

$(libname): $(epanet_objs)
	$(CC) $(CFLAGS) $(LDFLAGS) -shared -o $@ $^

$(exename): $(epanet_main_obj) $(libname) $(epanet_main_heads)
	$(CC) $(CFLAGS) $(LDFLAGS) $< -l$(epanetrootname) -o $@

$(epanet_objs): $(epanet_heads)

.PHONY: install
install:
	cat $(runcmdname).template | sed 's|libdir|$(libdir)|' \
                                | sed 's|exename|$(bindir)/$(exename)|' \
                                > $(runcmdname)
	$(INSTALL_PROGRAM) -D $(exename) $(bindir)/$(exename)
	$(INSTALL_PROGRAM) -D $(libname) $(libdir)/$(libname)
	$(INSTALL_DATA) -D $(epanetincludedir)/epanet2.h $(includedir)/epanet2.h
	$(INSTALL_PROGRAM) -D $(runcmdname) $(bindir)/$(runcmdname)

.PHONY: uninstall
uninstall:

.PHONY: check
check:

.PHONY: clean
clean:
	-/bin/rm *.o $(libname) $(exename) $(runcmdname)
