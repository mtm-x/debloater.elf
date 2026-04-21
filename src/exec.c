/*
 * Implementation of execvp syscall handler 
 */

#include"debloat.h"

/* int execvp(const char *filename, char *const argv[]); 
 * should i use const char *command ? 
 */

int execvp_handler ( char *command, char *argv[]) {
	/* I need to create a process child by forking the current process */

	pid_t pid;
	pid = fork();

	if(pid == -1) {
		return -1; /*improve these dummy -1s */
		// perror idk
	}

	if(pid == 0) {
		execvp(command, argv);
		/* if execvp is successfull he never gonna come back to this line */
		perror("execvp");
	}

	else {
		/* idk 
		 * pid_t waitpid(pid_t pid, int *status, int options);
		 */

		int status;
		waitpid(pid, &status, 0);
	}
	
	return 0;
	
}

