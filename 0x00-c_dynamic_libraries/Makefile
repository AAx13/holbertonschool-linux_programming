#
# This Makefile will build a .so file and clean the directory of object files
# assuming you want to take the export environment variable method toward
# implementing a shared library.
#
# Execute "make rpath" to build .so file, clean directory of object files and
# implement shared library using the rpath method.
#

CC = gcc
DEPS = headers/holberton.h
CFLAGS = -Wall -Werror -pedantic -Wextra
CFILES = src/*.c
OBJ = *.o

# build .o files.
%.o : src/%.c $(DEPS)
	$(CC) $(CFLAGS) -c -fPIC $< $(CFILES)

# build .so file and remove .o files.
libholberton.so : $(OBJ)
	$(CC) -shared $(CFLAGS) -o $@ $(OBJ)
	rm *~ *.o

# build .so file, remove .o files, and link shared library using rpath
rpath : $(OBJ)
	$(CC) -shared $(CFLAGS) -o libholberton.so $(OBJ)
	$(CC) -L. -Wl,-rpath=. -o len mainfiles/0-main.c -lholberton
	rm *~ *.o

clean :
	rm *.o *~ len
