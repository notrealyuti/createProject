#include "include/Alfred.h"

/* Author: yuti
 * First release: 23/09/2022 (from school)
 * Objective: Help all the little coders (like me) 
 * to create a new project super simply
 *
 */


int main(u8 argc, char* args[]) {
	s8 error;
	
	if (argc != 3) {
		puts("Usage: createProject <name> <1/2/3>");
		return 1;
	} 

	struct Project* project = Alfred_init(argc, args, &error);
	if (!error) {  // Cause errors like -1 are not fatal
		puts("Error during project initialization");
		return 1;
	}	
	else if (error < 0) {
		printf("%s\n", usageText);
		return 1;
	}

	// Create the project
	Alfred_create(project);

	// Now the folders/files are created
	
	// Now we can clean up all 
	Alfred_cleanUp(project);


	return 0;
}
