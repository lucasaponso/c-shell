#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdbool.h>

#define COLOR_RED     "\033[1;31m"
#define COLOR_GREEN   "\033[1;32m"
#define COLOR_YELLOW  "\033[1;33m"
#define COLOR_BLUE    "\033[1;34m"

#define COLOR_RESET   "\033[0m"
#define printc(color, fmt, ...) printf(color fmt COLOR_RESET, ##__VA_ARGS__)

/**
 * @brief The following function removes a newline character
 * from the string. ("\n")
 * @param str
 * @return void
 */
void remove_newline(char * str);

/**
 * @brief The following function checks whether the script
 * line relates to an increment of a variable
 * @param line
 */
bool is_increment_directive(const char *line);

/**
 * @brief The following function handles an increment of
 * an existing variable.
 * @param line
 */
void handle_increment_directive(char * var_name, char * existing_value);

/**
 * @brief The following function checks whether the script line
 * relates to an assignment of a variable
 * @param line
 */
bool is_assignment_line(const char *line);

/**
 * @brief The following function handles the assignment
 * of a variable
 * @param line
 */
void handle_assignment_line(char *line);


#endif //UTILS_H