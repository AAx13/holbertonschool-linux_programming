#ifndef _SIG_H_
#define _SIG_H_

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
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
/* 4 */
int trace_signal_sender(void);
/* 10 */
int pid_exist(pid_t pid);
/* 12 */
void all_in_one(void);
/* 13 */
int sigset_init(sigset_t *set, int *signals);
/* 14 */
int signals_block(int *signals);
/* 15 */
int signals_unblock(int *signals);
/* 16 */
int handle_pending(void (*handler)(int));


#endif /* _SIG_H_ */
