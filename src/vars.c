#include "vars.h"
#include <string.h>
#include <stdio.h>

#define MAX_LINE_LEN 512


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

void c_shell_set_var_env()
{
    FILE * env_file;
    ShellVar var;
    char line_in_file[MAX_LINE_LEN];
    env_file = fopen(".c_env", "r"); //TODO: Change to hash define

    if (!env_file)
    {
        return;
    }


    while (fgets(line_in_file, sizeof(line_in_file), env_file)) 
    {
        // Remove newline
        line_in_file[strcspn(line_in_file, "\n")] = '\0';

        // Find '='
        char * equals = strchr(line_in_file, '=');
        if (!equals) continue; // Skip malformed line

        // Split into name and value
        *equals = '\0';
        char *name = line_in_file;
        char *value = equals + 1;

        // Create and set ShellVar using existing function
        strncpy(var.name, name, MAX_VAR_NAME - 1);
        var.name[MAX_VAR_NAME - 1] = '\0';

        strncpy(var.value, value, MAX_VAR_VALUE - 1);
        var.value[MAX_VAR_VALUE - 1] = '\0';

        if (var_count >= MAX_VARIABLES)
        {
            printf("Too many variables in system\n");
            return;
        }

        c_shell_set_var(var);
    }

    fclose(env_file);
}


void c_shell_set_var(ShellVar var_to_set)
{
    size_t i;

    for (i = 0; i < var_count; i++)
    {
        if (strcmp(var_to_set.name, variables[i].name) == 0)
        {
            strncpy(variables[i].value, var_to_set.value, MAX_VAR_VALUE - 1);
            variables[i].value[MAX_VAR_VALUE - 1] = '\0';
            return;
        }
    }

    strncpy(variables[var_count].name, var_to_set.name, MAX_VAR_NAME - 1);
    variables[var_count].name[MAX_VAR_NAME - 1] = '\0';

    strncpy(variables[var_count].value, var_to_set.value, MAX_VAR_VALUE - 1);
    variables[var_count].value[MAX_VAR_VALUE - 1] = '\0';

    var_count++;
    return;
}
