/*
 * Implementation of execvp syscall handler 
 */

#include"debloat.h"
/* Global vars */
volatile bool status_exec = 0; /* if 1 something fucked*/ 


/* 
 * int execvp(const char *filename, char *const argv[]); 
 * should i use const char *command ? yeah
 * hmm is using errno.h good idk 
 */

unsigned char execlp_handler(char *arg1, char *arg2) {
	pid_t pid;
	pid = fork();

	if(pid == -1) {
		printf("Process creation itself fuckd");
		return EXIT_FAILURE;
		// perror idk
	}

	if(pid == 0) {
		//execlp(command, argv, arg1, (char *)0 );
		/* if execlp is successfull he never gonna come back to this line */
		
		status_exec = execlp(ADB, arg1, arg2, c_nulptr); /*by default status_exec is 0 if 1 boom */
		printf("%d \n", status_exec);
		exit(ENOENT);	
		//perror("execvp");
	}


	else {
		/* 
		 * idk 
		 * pid_t waitpid(pid_t pid, int *status, int options);
		 */

		int status;
		waitpid(pid, &status, 0);
	}
	
	return EXIT_SUCCESS;
}
