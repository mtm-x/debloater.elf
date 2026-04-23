/*
 * Implementation of adb application remover logic?
 */

#include"exec.h"
#include"debloat.h"

unsigned char check_device_connected() {
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
	unsigned char ret = execlp_handler(*command, *command+4);
	if (ret != EXIT_SUCCESS){
	       printf("Something fucked up");
	}
	return EXIT_SUCCESS;
}

int check_adb_installed() {
	execlp_handler("", "");
	extern volatile bool status_exec;
	printf("%d \n", status_exec);
	if (status_exec == 1) {
		printf("Dang!! adb is not installed \n");
			
		//temp return but call for installation handler
		return EXIT_FAILURE;
	}
//	printf("wtf");
//	check_device_connected();	
	return EXIT_SUCCESS;
}


