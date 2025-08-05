#include "vars.h"
#include <string.h>
#include "log.h"
#include <stdio.h>
#include "utils.h"

#define MAX_LINE_LEN 512
#define C_SHELL_ENV_LOC ".c_env"

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
    char line_in_file[MAX_LINE_LEN];
    size_t line_len;
    char * var_name = NULL;
    char * existing_value = NULL;
    increment_type type;
        
    if (!(env_file = fopen(C_SHELL_ENV_LOC, "r")))
    {
        c_shell_log("No env file presented", C_SHELL_LOG_INFO);
        return;
    }

    while (fgets(line_in_file, sizeof(line_in_file), env_file)) 
    {
        // Strip trailing newline
        //line_in_file[strcspn(line_in_file, "\n")] = '\0';
        remove_newline(line_in_file);
        
        line_len = strlen(line_in_file);
        
        // Handle standard VAR=VALUE line
        if (is_assignment_line(line_in_file)) 
        {
            handle_assignment_line(line_in_file);
        }

        // Handle increment directive: @VAR++
        if (is_increment_directive(line_in_file, &type)) 
        {
            line_in_file[line_len - 2] = '\0';             // Remove '++'
            var_name = &line_in_file[0];        // Skip '@'
            existing_value = c_shell_get_var(var_name);
            
            if (existing_value != NULL) //variable exists
            {
                handle_increment_directive(var_name, existing_value, type);
                continue;
            }

            printf("Error: Variable does not exist: %s\n", var_name);
            exit(1);
        }

    }

    fclose(env_file);
    c_shell_log("ENV variables successfully read from file", C_SHELL_LOG_INFO);
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
