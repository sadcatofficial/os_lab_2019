gcc -std=c99 -Wall -fPIC -c revert_string.c
gcc -shared -o libdynamic.so revert_string.o
