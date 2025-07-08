#ifndef VARS_H
#define VARS_H

#include <unistd.h>

#define MAX_VAR_NAME 64
#define MAX_VAR_VALUE 256
#define MAX_VARIABLES 100

/**
 * @brief The following structure describes
 * a variable instance It has a variable name and it's
 * value
 */
typedef struct {
    char name[MAX_VAR_NAME];
    char value[MAX_VAR_VALUE];
} ShellVar;

/**
 * @brief The following function retrieves a value
 * from a given variable
 * @param name The name of the variable to search
 * @return char *
 */
char * c_shell_get_var(const char * name);

/**
 * @brief The following function set's a given variables value.
 * If the variable exists, the value is overwritten.
 * @param name The variable to be set
 * @param value The value to set in the variable
 * @return int
 */
int c_shell_set_var(ShellVar var_to_set);

#endif //VARS_H
