#include<debloat.h>

/*const char *command ?*/
int find_exec_path (char *commad) {
	bool EXE_FOUND = false;
	char *command_name = command;
	char *path_env = getenv("PATH");

	char *path_env_cpy = strdup(path_env);
	
	/*Is this below check necessary*/
	if(path_env_cpy) {
		/* Okay idk */

	}
	return 0;
}
		
