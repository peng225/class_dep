# class\_dep
Class field and method dependency analysis tool.

## Required packages

- clang
- libclang-dev
- cmake
- ninja

## How to use

+ Edit the parameters in Makefile.
+ mkdir build
+ make

## Parameters

Following parameters in Makefile should be set.

|  Parameter       |  Meaning  |
| ----             | ---- |
|  SRC             |  Name of a source file to be analized  |
|  CLASS           |  Name of a C++ class to be analized  |
|  DSTDIR          |  Output path  |
|  CLASS\_DEP\_OPT |  Specify if you also want to analyze base classes |

## Known issues

- Virtual inheritance is not supported.
- Field access at member initializer is ignored.
- Access to methods or fields of indirect ancestor class is ignored.

