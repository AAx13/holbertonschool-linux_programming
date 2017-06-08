#!/bin/bash
gcc -shared -Wall -Werror -pedantic -Wextra -fPIC -o 100-operations.so pysrc/*.c
