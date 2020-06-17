gcc -std=c99 -Wall -c revert_string.c
ar crs libstatic.a revert_string.o 
ranlib libstatic.a
