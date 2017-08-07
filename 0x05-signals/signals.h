#ifndef _SIG_H_
#define _SIG_H_

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>

int handle_signal(void);
void print_hello(int);
void set_print_hello(void);
void (*current_handler_signal(void))(int);

#endif /* _SIG_H_ */
