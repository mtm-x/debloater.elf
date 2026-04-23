#include"debloat.h"
#include"core.h"

/* TODO
 * hmm, check adb is installed or not if not install it ( create exe_finder  
 * check for adb device.
 * and all the commands for now 
 */

int main (void) {
	
	int ret = check_adb_installed();
	if ( ret != EXIT_SUCCESS ){
		return -1;
	}
	return 0;
}
