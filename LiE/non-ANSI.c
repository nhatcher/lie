
#include <unistd.h>  /* needed for |isatty| */
#include <stdio.h> 

int no_terminal(FILE* f) { return 0;/*!isatty(fileno(f));*/ }

void sysinit(void)  {}

