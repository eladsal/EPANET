/*
*******************************************************************************

EPANET.C -- Main Program for Hydraulic & Water Quality Simulator for
            Water Distribution Networks

This is the main module of the EPANET program. It uses a series of
functions, all beginning with the letters EN, to control program behavior.


VERSION:    2.00
DATE:       5/30/00
            9/7/00
            10/25/00
            3/1/01
            11/19/01
            6/24/02
            3/29/06
AUTHOR:     L. Rossman
            US EPA - NRMRL

EPANET performs extended period hydraulic and water quality analysis of
looped, pressurized piping networks. In addition to this main program,
the EPANET program consists of the following code modules:

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
    MEMPOOL.C -- memory allocation routines
    HASH.C    -- hash table routines

These modules can be compiled as either a shared object library on linux/Unix
(SO) or as a dynamic link library (DLL) on Windows.  A DLL is produced if
the preprocessor variable 'WIN32' is defined.  A standalone executable is produced
by compiling this main program epanet.c and linking with either the DLL or SO
library, as appropriate for the build platform.  Makefiles are supplied to
build the SO library on linux/unix (Makefile.linux) and a native windows
DLL under Cygwin/MinGW; see the Makefile for details.  Otherwise, you will need to
use your favorite compiler and linker to build the appropriate library and
standalone executable.

See TOOLKIT.H for function prototypes of exported toolkit functions
See FUNCS.H for prototypes of all other functions
See TYPES.H for declaration of global constants and data structures
See VARS.H for declaration of global variables
See TEXT.H for declaration of all string constants
See ENUMSTXT.H for assignment of string constants to enumerated types

The following naming conventions are used in all modules of this program:
1. Names of exportable toolkit functions begin with the "EN" prefix.
2. All other function names are lowercase.
3. Global variable names begin with an uppercase letter.
4. Local variable names are all lowercase.
5. Declared constants and enumerated values defined in TYPES.H are
   all uppercase.
6. String constants defined in TEXT.H begin with a lower case character
   followed by an underscore and then all uppercase characters (e.g.
   t_HEADLOSS)

--------------------------------------------------------------------------

The macro ERRCODE(x) is defined in TYPES.H. It says if the current
value of the error code variable (errcode) is not fatal (< 100) then
execute function x and set the error code equal to its return value.

*******************************************************************************
*/


#include <epanet2.h>
#include <stdio.h>
#include <stdlib.h>

static char *usageString="usage: epanet <epanet-input-file> <epanet-output-file> [binary-output-file]\n";

/*
----------------------------------------------------------------
   Entry point used to compile a stand-alone executable.
----------------------------------------------------------------
*/

int   main(int argc, char *argv[])
/*--------------------------------------------------------------
**  Input:   argc    = number of command line arguments
**           *argv[] = array of command line arguments
**  Output:  none
**  Purpose: main program segment
**
**  Command line for stand-alone operation is:
**    progname f1  f2  f3
**  where progname = name of executable this code was compiled to,
**  f1 = name of input file, f2 = name of report file, and
**  f3 = name of binary output file (optional).
**--------------------------------------------------------------
*/
{
    char *f1,*f2,*f3;
    char blank[] = "";
    int  errcode;
    char errmsg[80];

/* Check for proper number of command line arguments */
    if (argc < 3) {
       printf(usageString);
       exit(9);
    }
    else
    {

    /* Call the main control function */
       f1 = argv[1];
       f2 = argv[2];
       if (argc > 3) f3 = argv[3];
       else          f3 = blank;

       printf("\n... EPANET Version 2.0\n");

       errcode = ENepanet(f1,f2,f3,NULL);

       if (errcode > 0) {
          ENgeterror(errcode,errmsg,80);
          fprintf(stderr,"\nEPAnet run-time error...\n");
          fprintf(stderr,"%s\n",errmsg);
          fprintf(stderr,"...now exiting to system...\n");
          exit(9);
       } else
       printf("\nEPANET normal termination.\n");

    }
    return(0);
}                                       /* End of main */
