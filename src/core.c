/*
 * Implementation of adb application remover logic?
 */

#include"exec.h"
#include"debloat.h"

static unsigned char check_device_connected() {
	/* No need for this type of implementation tbh */

	char **command = malloc(1*sizeof(char *));

	if (command == nulptr) {
		printf("malloc allocation failed %p", command);
		return ENOMEM;
	}

	*command = malloc(strlen("adb devices")+1);
	if (*command == nulptr) {
		printf("malloc allocation failed %p", *command);
		return ENOMEM;
	}

	strcpy(*command, "adb devices");
	unsigned char ret = execlp_handler(*command, *command+4, false);
	if (ret != EXIT_SUCCESS){
	       printf("Something fucked up");
	}
	// need to free mallocs
	free(*command);
	free(command);
	return EXIT_SUCCESS;
}

unsigned char check_adb_installed() {
	unsigned char status_exec = execlp_handler("", "", true);
	if (status_exec == ENOENT) {
		printf("Dang!! adb is not installed \n");
			
		//temp return but call for installation handler
		return EXIT_FAILURE;
	}
	check_device_connected();
	return EXIT_SUCCESS;
}


