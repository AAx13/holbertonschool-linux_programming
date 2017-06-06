#
# This Makefile will build a .so file and clean the directory of object files
# assuming you want to take the export environment variable method toward
# implementing a shared library.
#
# Execute "make rpath" to build .so file, clean directory of object files and
# implement shared library using the rpath method.
#

CC = gcc
DEPS = holberton.h
CFLAGS = -Wall -Werror -pedantic -Wextra
CFILES = abs.c atoi.c isalpha.c isdigit.c islower.c isupper.c memcpy.c memset.c putchar.c puts.c strcat.c strchr.c strcmp.c strcpy.c strlen.c strncat.c strncpy.c strpbrk.c strspn.c strstr.c
OBJ = abs.o atoi.o isalpha.o isdigit.o islower.o isupper.o memcpy.o memset.o putchar.o puts.o strcat.o strchr.o strcmp.o strcpy.o strlen.o strncat.o strncpy.o strpbrk.o strspn.o strstr.o

# build .o files.
%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c -fPIC $< $(CFILES)

# build .so file and remove .o files.
libholberton.so : $(OBJ)
	$(CC) -shared $(CFLAGS) -o $@ $(OBJ)
	rm *~ *.o

# build .so file, remove .o files, and link shared library using rpath
rpath : $(OBJ)
	$(CC) -shared $(CFLAGS) -o libholberton.so $(OBJ)
	$(CC) -L. -Wl,-rpath=. -o len 0-main.c -lholberton
	rm *~ *.o

clean :
	rm *.o *~ libholberton.so len
