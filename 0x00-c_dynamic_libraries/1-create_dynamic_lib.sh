#!/bin/bash
gcc -shared -Wall -Werror -pedantic -Wextra -fPIC *.c -o liball.so
