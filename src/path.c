#include<debloat.h>

/*const char *command ?*/
int find_exec_path (char *commad) {
	bool EXE_FOUND = false;
	char *command_name = command;
	char *path_env = getenv("PATH"); /* Gets the actual pointer to where the env varables paths are defined dont try to modify lol */

	char *path_env_cpy = strdup(path_env);
	
	/*Is this below check necessary*/
	if(path_env_cpy) {
		/* Okay idk 
		 * needs to split the path with strtok()
		 * opendir 
		 * check the all the file names in the dir againts our command_name which also have the executable file permission hmm then cool no need to install the package
		 * */



	}
	return 0;
}
		
