#!/bin/bash
gcc -Wall -Werror -pedantic -Wextra -fPIC -c pysrc/*.c
gcc -shared -o 100-operations.so *.o
rm *.o
