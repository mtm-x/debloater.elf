#ifndef _EXEC_H
#define _EXEC_H

unsigned char execlp_handler(char *arg1, char *arg2, bool REDIRECT);
unsigned char execvp_handler(char *arg[], bool REDIRECT);
	

#endif
