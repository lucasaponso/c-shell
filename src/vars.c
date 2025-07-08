#include "vars.h"
#include <string.h>
#include <stdio.h>

ShellVar variables[MAX_VARIABLES];
size_t var_count = 0;

char * c_shell_get_var(const char * name)
{
    for (size_t i = 0; i < var_count; i++)
    {
        if (strcmp(name, variables[i].name) == 0)  // FIXED: strcmp, and indexing
        {
            return variables[i].value;  // FIXED: return value, not name
        }
    }

    printf("Unknown variable: %s\n", name);
    return NULL;  // FIXED: must return something
}

int c_shell_set_var(const char *name, const char *value)
{
    // Check if it exists first
    for (size_t i = 0; i < var_count; i++)
    {
        if (strcmp(name, variables[i].name) == 0)
        {
            strncpy(variables[i].value, value, MAX_VAR_VALUE - 1);
            variables[i].value[MAX_VAR_VALUE - 1] = '\0';
            return 0;
        }
    }

    // Add new variable
    if (var_count >= MAX_VARIABLES)
    {
        printf("Too many variables in system.\n");
        return -1;
    }

    strncpy(variables[var_count].name, name, MAX_VAR_NAME - 1);
    variables[var_count].name[MAX_VAR_NAME - 1] = '\0';

    strncpy(variables[var_count].value, value, MAX_VAR_VALUE - 1);
    variables[var_count].value[MAX_VAR_VALUE - 1] = '\0';

    var_count++;
    return 0;
}
