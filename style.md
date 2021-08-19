# Style Guide

This document outlines the required style guideline for contributing and writing code for the project.

## Names

*Naming conventions are less important within functions but should still be followed as much as possible*

-   Use snake_case for all names, not camelCase
-   For macros, use all uppercase names, otherwise use all lowercase, even for constants
-   Constants should be stored in constant variables whenever possible
-   Define all variables of the same type on one line *unless* they are being initialized to a value
-   All type names (defined by typedef) must be suffixed by \_t
-   All function names and global variable names must be prefixed by a (optimally) 3 letter prefix (such as "sky" for the main folder)

## Spaces

-   Use tabs for indentation, not spaces
-   Leave one blank space between operators (4 + 3 not 4+3)
-   Always put one space after commas

## Braces and parenthesis

-   Opening braces should be on the same line as the function or statement
-   Use parenthesis whenever clarity is needed, especially for bitwise operators

## Structures

-   If using a pointer to a structure, use -> to access members, don't dereference it
-   Do not put spaces between structs, members, and -> (ex: use struct->member not struct -> member)

## Functions

-   All function declarations in a header file where the function body isn't present should use the extern keyword
-   Always put input parameters before output parameters
-   Avoid code duplication whenever possible
-   Use inline functions whenever no includes are used in the function, and it is used often or it is small