#ifndef MODE_H
#define MODE_H


// Every time you want to test something
#define MODE_TEST 1
// When you want to create a simple project
#define MODE_BASE 2
// When you want to create a big project 
#define MODE_PROJ 3

/*
    Specify the componets

    MODE_TEST : name.c + desc + def.h

    MODE_BASE :   OK      OK      OK   + Makefile  

    MODE_PROJ :   OK      OK      OK       OK     + build / src folders 

*/

static const char defH[] = 

    "#ifndef DEF_H\n"
    "#define DEF_H\n"
    "#include <stdint.h>\n\n"

    "// Boolean\n"
    "#define true  1\n"
    "#define false 0\n\n"
    "typedef uint8_t bool;\n\n"
    "// Unsigned\n" 
    "typedef uint8_t  u8;\n"
    "typedef uint16_t u16;\n"
    "typedef uint32_t u32;\n"
    "typedef uint64_t u64;\n\n"
    "// Signed\n"
    "typedef int8_t  s8;\n"
    "typedef int16_t s16;\n"
    "typedef int32_t s32;\n"
    "typedef int64_t s64;\n\n"

    "#endif\n";

static const char mainC[] =

    "#include \"def.h\"\n"\
    "#include <stdio.h>\n\n\n\n"\
    "int main(u8 argc, char* args[]) {\n\n\n\n"\
    "\treturn 0;\n"
    "}\n";

static const char mainCProj[] =

    "#include \"include/%s.h\"\n"
    "int main(int argc, char* args[]) {\n\n\n\n"
    "\treturn 0;\n"
    "}\n";

static char makeF[] =
    "NAME=\"%s\"\n"
    "_build:\n"
    "\tgcc -std=c99 ${NAME}.c -o ${NAME}\n"
    "run:\n"
    "\t./${NAME}\n";


static char makeFProj[] =
    "NAME=\"%s\"\n"
    "_build:\n"
    "\tgcc -std=c99 src/include/src/*.c src/main.c -o build/${NAME}\n"
    "run:\n"
    "\t./build/${NAME}\n";


static char usageText[] =
    "Usage: createProject <name> <1/2/3>n\n"
    "1: Test\n"
    "2: Base\n"
    "3: Projects\n";

    

#endif 