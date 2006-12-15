Description of EPANET PACKAGE
=============================
This archive contains the source code for the EPANET 2 network
hydraulic and water quality solver. The solver provides functions
for simulating the extended period hydraulic and water quality
behavior of water distribution system pipe networks. It is written
in ANSI-compatible C and can be compiled into either a Windows
Dynamic Link Library (DLL) or a Linux/Unix shared object library
(SO) of functions; a command-line executable is supplied that links
with this library and provides basic simulation capabilities for
both Linux/Unix and Windows.  A Windows user interface provides a
complete modeling package on that platform.

To build the libraries or the executable, makefiles are supplied for
Linux/Unix, and for Windows under Cygwin/MinGW. To build on Windows
using MSVC, you can use the supplied solution and project files.

The DLL is used with the EPANET 2 user interface executable
(epanet2w.exe) to form a complete Windows modeling package. The
functions exported from this DLL, or from the shared object library
(depending on platform), constitute the EPANET API and are
collectively known as the "EPANET Programmer's Toolkit."  We may
also refer to this API as "The Toolkit" or simply "the library." The
EPANET Programmer's Toolkit allows developers to construct their own
customized pipe network analysis applications.

The following C-code files comprise the DLL or SO library:
    TOOLKIT.C -- exported toolkit functions comprising the library interface
    INPUT1.C  -- controls processing of input data
    INPUT2.C  -- reads data from input file
    INPUT3.C  -- parses individual lines of input data
    INPFILE.C -- saves modified input data to a text file
    RULES.C   -- implements rule-based control of piping system
    HYDRAUL.C -- computes extended period hydraulic behavior
    QUALITY.C -- tracks transport & fate of water quality
    OUTPUT.C  -- handles transfer of data to and from binary files
    REPORT.C  -- handles reporting of results to text file
    SMATRIX.C -- sparse matrix linear equation solver routines
    MEMPOOL.C -- memory pool management routines
    HASH.C    -- hash table routines

These C modules require the following supplied header files:
    TOOLKIT.H  -- function prototypes of exported library functions
    FUNCS.H    -- prototypes of all other functions
    TYPES.H    -- declaration of global constants and data structures
    VARS.H     -- declaration of global variables
    HASH.H     -- header file for hash table routines
    MEMPOOL.H  -- header file for memory pool routines
    ENUMSTXT.H -- string constants for enumerated types
    TEXT.H     -- declaration of all other string constants

In addition to the above which form the library, the following files
are supplied for building a standalone executable and any other C
code applications that link with the library:
    EPANET.C  -- main module for the standalone executable
    EPANET2.H -- function prototypes of exported library functions,
                 and definitions of codes used by the exported
                 functions.  This header must be included by any
                 toolkit application (i.e. one that links with the
                 EPANET toolkit library).  The prototypical example
                 of this is EPANET.C.

The comments at the top of each file lists the date when the latest
update was made, and these updates can be located in the code by
searching for the keywords "/*** Updated".

Other useful documentation that can be consulted includes the EPANET
Programmers Toolkit Windows Help file and the EPANET Version 2 Users
Manual.

The EPANET package is organized by the following directory structure:

EPANET
  |___________________________________
    |          |          |          |
    build      doc        include    src
    |________________________
      |          |          |
      Cyg        Linux      MSVC

The 'build' directory includes subdirectories for building the
EPANET library and standalone executable on Windows under Cygwin
(Cyg), on Linux (Linux), and on Windows using the Microsoft Visual C
compiler (MSVC).  Look in the directory corresponding to your
platform for the makefiles or solution files that will build EPANET.

The 'doc' directory contains this file as well as other
documentation about EPANET, the 'include' directory contains header
files that are required for linking with the EPANET library, and the
'src' directory contains all EPANET source and header files required
to build the library.
