#include "vars.h"
#include <string.h>
#include <stdio.h>

ShellVar variables[MAX_VARIABLES];
size_t var_count = 0;

char * c_shell_get_var(const char * name)
{
    size_t i;
    for (i = 0; i < var_count; i++)
    {
        if (strcmp(name, variables[i].name) == 0)
        {
            return variables[i].value;
        }
    }
    
    return NULL;
}

int c_shell_set_var(ShellVar var_to_set)
{
    size_t i;
    for (i = 0; i < var_count; i++)
    {
        if (strcmp(var_to_set.name, variables[i].name) == 0)
        {
            strncpy(variables[i].value, var_to_set.value, MAX_VAR_VALUE - 1);
            variables[i].value[MAX_VAR_VALUE - 1] = '\0';
            return 0;
        }
    }

    if (var_count >= MAX_VARIABLES)
    {
        printf("Too many variables in system.\n");
        return -1;
    }

    strncpy(variables[var_count].name, var_to_set.name, MAX_VAR_NAME - 1);
    variables[var_count].name[MAX_VAR_NAME - 1] = '\0';

    strncpy(variables[var_count].value, var_to_set.value, MAX_VAR_VALUE - 1);
    variables[var_count].value[MAX_VAR_VALUE - 1] = '\0';

    var_count++;
    return 0;
}
