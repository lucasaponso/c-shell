#ifndef VARS_H

#include <unistd.h>

#define MAX_VAR_NAME 64
#define MAX_VAR_VALUE 256
#define MAX_VARIABLES 100

typedef struct {
    char name[MAX_VAR_NAME];
    char value[MAX_VAR_VALUE];
} ShellVar;


char * c_shell_get_var(const char * name);
int c_shell_set_var(const char * name, const char * value);

#endif //VARS_H
