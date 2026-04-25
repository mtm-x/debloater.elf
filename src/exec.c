/*
 * Implementation of execvp syscall handler 
 */

#include"debloat.h"

/* 
 * int execvp(const char *filename, char *const argv[]); 
 * should i use const char *command ? yeah
 * hmm is using errno.h good idk 
 */

static void redirect_to_dev_null() {
	/*
	 * To prevent the child process's output from printing to the shell, you need to redirect its standard output
         * and standard error (stderr) to /dev/null using the dup2() system call before calling execvp()
         * returns file descritor a unique number for opened file or -1 
	 */

	int dev_null_fd = open("/dev/null", O_WRONLY); 
	
	if (dev_null_fd == -1) {
		perror("open /dev/null failed");
		exit(EXIT_FAILURE);
	}
        
	/* Redirect stdout to /dev/null */
	if (dup2(dev_null_fd, STDOUT_FILENO) == -1) {
		perror("dup2 stdout failed");
		exit(EXIT_FAILURE);
	}

	/* Redirect stderr to /dev/null */
	if (dup2(dev_null_fd, STDERR_FILENO) == -1) {
		perror("dup2 stderr failed");
		exit(EXIT_FAILURE);
	}

	close(dev_null_fd);
	
}

unsigned char execlp_handler(const char *arg1, const char *arg2, bool REDIRECT) {
	pid_t pid;
	pid = fork();

	if(pid == -1) {
		printf("Process creation itself fuckd");
		return EXIT_FAILURE;
		// perror idk
	}

	if(pid == 0) {
		
		if(REDIRECT) redirect_to_dev_null();

		/*
		 * execlp(command, argv, arg1, (char *)0 );
		 * if execlp is successfull he never gonna come back to this line 
		 */
		
		execlp(ADB, arg1, arg2, c_nulptr); 
		/*
		 * by default status_exec is 0 if 1 boom but seriously this status_exec 
		 * will be 1 inside the child process memory and using this same variable 
		 * in the parent process will do nothing rather it will be always 0 
		 */

		exit(ENOENT);	
	}
	else {
		/* 
		 * idk 
		 * pid_t waitpid(pid_t pid, int *status, int options);
		 */
		int status;
		waitpid(pid, &status, 0);
		return WEXITSTATUS(status);
	}
}

unsigned char execvp_handler(char *arg[], bool REDIRECT) { /* char const *arg[] ? */
	pid_t pid;
	pid = fork();

	if(pid == -1) {
		printf("Process creation itself fuckd");
		return EXIT_FAILURE;
	}

	if(pid == 0) {
		
		if(REDIRECT) redirect_to_dev_null();
		execvp(ADB, arg); 
		exit(ENOENT);	
	}

	else {
		int status;
		waitpid(pid, &status, 0);
		return WEXITSTATUS(status);
	}
}


