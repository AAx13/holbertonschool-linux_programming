#ifndef _SIG_H_
#define _SIG_H_

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>

void print_hello(int);

/* 0 */
int handle_signal(void);
/* 1 */
void (*current_handler_signal(void))(int);
/* 2 */
int handle_sigaction(void);
/* 3 */
void (*current_handler_sigaction(void))(int);

#endif /* _SIG_H_ */
