#include"debloat.h"
#include"core.h"

/* TODO
 * hmm, check adb is installed or not if not install it ( create exe_finder  
 * check for adb device.
 * and all the commands for now 
 * need to replace all printf with fprintf 
 * general sizes with macros 
 */

int main (void) {
	
	unsigned char ret = check_adb_installed();
	if ( ret != EXIT_SUCCESS ){
		/* adb installation 
		 * return -1;
		 */
	}
	check_device_connected(); /* it will be always returns success rn */
	list_packages();
	return 0;
}
