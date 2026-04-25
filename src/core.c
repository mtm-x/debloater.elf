/*
 * Implementation of adb application remover logic?
 */

#include"exec.h"
#include"debloat.h"

static void remove_package(char *pkg_name){
	*(pkg_name+(strlen(pkg_name)-1)) = '\0';
	printf("%s \n", pkg_name);
	char *command[] = {ADB, "shell", "pm", "uninstall", "--user", "0", pkg_name, NULL};
	int ret = execvp_handler(command, false);
	printf("%d \n", ret);
}	

void list_packages() {

	char *buffer = malloc(MAX_PACKAGE_NAME_LEN);
	if(buffer == nulptr) {
		printf("malloc allocation failed %p", buffer);
		return;
	}
	char *package_name = malloc(MAX_PACKAGE_NAME_LEN);
	if(package_name == nulptr) {
		printf("malloc allocation failed %p", package_name);
		return;
	}
	char **package_list = malloc(2048); /* i seriously dont know */
	if(package_list == nulptr) {
		printf("malloc allocation failed %p", package_list);
		return;
	}

	printf("Enter the application name or better full package name: ");
	scanf("%s", package_name); // need to check whether it is a name or not 

	FILE *stream = popen("adb shell pm list packages", "r");
	if (stream == nulptr) {
		printf("fcked \n");
		return;
	}
	
	unsigned int package_name_count = 0;
	while(fgets(buffer, 50, stream) != NULL) {
		if(strstr(buffer, package_name)) {
		/* 
		 * *(package_list+i) = buffer; 
		 * using above is problematic since every iteration new pkg names are
		 * written in the same 0x1000 memory location so after the loop 
		 * package_list = 0x1000 but it have the last package name 
		 */
			*(package_list+package_name_count ) = strdup(buffer); 
			/* 
			 * pkg name is duplicated to 0x2000
			 * dont forget to free.
			 */
			package_name_count++;
		}
	}	

	unsigned int right_pkg_number = 0;
	if(package_name_count > 1){
		printf("It seems there is more then 1 package name exist. Choose the correct one \n");
		for ( unsigned int count = 0; count < package_name_count; count++){
			printf("%d: %s", count, *(package_list+count));
		}
		printf("Choose the right package: ");
		scanf("%d", &right_pkg_number); //need to check if it is a number or not 
		printf("You selected: %s \n", *(package_list + right_pkg_number));
		remove_package(*(package_list + right_pkg_number)+8);
	}
	// need to free a lot of things
	free(buffer);
	pclose(stream);
}

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
	unsigned char ret = execlp_handler(*command, *command+4, false);
	if (ret != EXIT_SUCCESS){
	       printf("Something fucked up");
	}
	// need to free mallocs
	free(*command);
	free(command);
	/* TODO
	 * need to check whether device is connected or not :)
	 * on the assumption of it is connected moving to packages 
	 */
	return EXIT_SUCCESS;
}

unsigned char check_adb_installed() {
	unsigned char status_exec = execlp_handler("", "", true);
	if (status_exec == ENOENT) {
		printf("Dang!! adb is not installed \n");
		//temp return but call for installation handler
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
