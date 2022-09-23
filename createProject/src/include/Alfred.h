#ifndef ALFRED_H 
#define ALFRED_H

#include "Def.h"
#include "Mode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


struct Project {
    char name[30];
    char description[200];
    u8 mode;    
};

// Init the project
struct Project* Alfred_init(u8 argc, char* args[], s8* error);

// Create all the folders/files ...
void Alfred_create(struct Project* project);

// Clean up
void Alfred_cleanUp(struct Project* self);


#endif 