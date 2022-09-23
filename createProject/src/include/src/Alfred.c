#include "../Alfred.h"

struct Project* Alfred_init(u8 argc, char* args[], s8* error) {
    struct Project* self = (struct Project*)malloc(sizeof(struct Project));
    if (!self)
        return NULL;

    // Set the name
    strcpy(self->name, args[1]);
    self->mode = atoi(args[2]);
    // Eror
    if (self->mode > 3 || self->mode <= 0) {
        printf("%s\n", usageText);
        free(self);
        *error = -1;
        return NULL;
    }
    
    *error = 1;  // its ok 
    return self;
}

void Alfred_create(struct Project* project) {
    FILE* fp;
    char str[100];  // a very useful string to use with sprintf

    switch (project->mode) {
        case MODE_TEST:
                
            // Create the folder
            if (mkdir(project->name, S_IRWXU) < 0) {
                puts("Couldn't create the folder");
                return;
            }
            
            // Create the def file
            sprintf(str, "%s/def.h", project->name);
            fp = fopen(str, "w");
            fprintf(fp, "%s", defH);
            fclose(fp);                    
            
            // Create the .c file
            sprintf(str, "%s/%s.c", project->name, project->name);
            fp = fopen(str, "w");
            fprintf(fp, "%s", mainC);
            fclose(fp);

            // Create the desc file
            sprintf(str, "%s/description", project->name);
            fp = fopen(str, "w");
            fclose(fp);

            // write the description
            sprintf(str, "vim %s/description", project->name);
            system(str);

            break;

        case MODE_BASE:
            // Create the folder
            if (mkdir(project->name, S_IRWXU) < 0) {
                puts("Couldn't create the folder");
                return;
            }

            // Create the def file
            sprintf(str, "%s/def.h", project->name);
            fp = fopen(str, "w");
            fprintf(fp, "%s", defH);
            fclose(fp);                    
            
            // Create the .c file
            sprintf(str, "%s/%s.c", project->name, project->name);
            fp = fopen(str, "w");
            fprintf(fp, "%s", mainC);
            fclose(fp);

            // Create the desc file
            sprintf(str, "%s/description", project->name);
            fp = fopen(str, "w");
            fclose(fp);

            // Create the makefile
            sprintf(str, "%s/Makefile", project->name);
            fp = fopen(str, "w");
            fprintf(fp, makeF, project->name);
            fclose(fp);

            // write the description
            sprintf(str, "vim %s/description", project->name);
            system(str);

            break;

        case MODE_PROJ:

        // Folders
            // Create the main folder
            if (mkdir(project->name, S_IRWXU) < 0) {
                puts("Couldn't create the main folder");
                return;
            }

            // Create the build folder
            sprintf(str, "%s/build", project->name);
            if (mkdir(str, S_IRWXU) < 0) {
                puts("Couldn't create the folder");
                return;
            }

            // Create the src folder
            sprintf(str, "%s/src", project->name);
            if (mkdir(str, S_IRWXU) < 0) {
                puts("Couldn't create the folder");
                return;
            }

            // Create the src/include folder
            sprintf(str, "%s/src/include", project->name);
            if (mkdir(str, S_IRWXU) < 0) {
                puts("Couldn't create the folder");
                return;
            }

            // Create the src/inclde/src folder
            sprintf(str, "%s/src/include/src", project->name);
            if (mkdir(str, S_IRWXU) < 0) {
                puts("Couldn't create the folder");
                return;
            }


            // Create the src/main.c file
            // Create the src/main.c file
            sprintf(str, "%s/src/main.c", project->name);
            fp = fopen(str, "w");
            fprintf(fp, mainCProj, project->name);
            fclose(fp);

            // Create the src/include 
            sprintf(str, "%s/src/include/%s.h", project->name, project->name);
            fp = fopen(str, "w");
            fclose(fp);

            // Create the src/include/%s.h
            sprintf(str, "%s/src/include/%s.h", project->name, project->name);
            fp = fopen(str, "w");
            fprintf(fp, "%s", "#ifndef SIMBOL\n#define SIMBOL\n\n\n\n\n#endif");
            fclose(fp);

            // Create the src/include/src/.c
            sprintf(str, "%s/src/include/src/%s.c", project->name, project->name);
            fp = fopen(str, "w");
            fprintf(fp, "#include \"../%s.h\"", project->name);
            fclose(fp);

            // Create the makefile
            sprintf(str, "%s/Makefile", project->name);
            fp = fopen(str, "w");
            fprintf(fp, makeFProj, project->name);
            fclose(fp);

            // Create the definition file for ints
            sprintf(str, "%s/src/include/def.h", project->name);
            fp = fopen(str, "w");
            fprintf(fp, "%s", defH);
            fclose(fp);

            // Create the desc file
            sprintf(str, "%s/description", project->name);
            fp = fopen(str, "w");
            fclose(fp);

            // TODO: insert a mini simple editor for the description file
            // use the getch() func from the github guy
            // Ends with CTRL+C 
            // NO: change mind
            // you need vim to do this
            sprintf(str, "vim %s/description", project->name);
            system(str);
    
    }
}


void Alfred_cleanUp(struct Project* self) {
    // TODO
    free(self);
}