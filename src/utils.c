#include <string.h>
#include <stdbool.h>
#include <vars.h>
#include <log.h>
#include <stdio.h>
#include "utils.h"

void remove_newline(char *str) 
{
    size_t len = strlen(str);
    
    if (len > 0 && str[len - 1] == '\n') 
    {
        str[len - 1] = '\0';
    }
}

bool is_increment_directive(const char *line)
{
    size_t len = strlen(line);
    return (len > 4 && line[0] == '@' && strcmp(&line[len - 2], "++") == 0);
}

void handle_increment_directive(char * var_name, char * existing_value)
{
    ShellVar var;
    int current_value = 0;

    current_value = atoi(existing_value) + 1;

    strncpy(var.name, var_name, MAX_VAR_NAME - 1);
    var.name[MAX_VAR_NAME - 1] = '\0';
    snprintf(var.value, MAX_VAR_VALUE, "%d", current_value);

    c_shell_set_var(var);
}

bool is_assignment_line(const char *line)
{
    return strchr(line, '=') != NULL;
}

void handle_assignment_line(char *line)
{
    ShellVar var;

    char *equals = strchr(line, '=');
    if (!equals) return;

    *equals = '\0';
    char *name = line;
    char *value = equals + 1;

    strncpy(var.name, name, MAX_VAR_NAME - 1);
    var.name[MAX_VAR_NAME - 1] = '\0';

    strncpy(var.value, value, MAX_VAR_VALUE - 1);
    var.value[MAX_VAR_VALUE - 1] = '\0';

    if (var_count >= MAX_VARIABLES)
    {
        c_shell_log("Too many variables in system", C_SHELL_LOG_CRIT);
        return;
    }

    c_shell_set_var(var);
}