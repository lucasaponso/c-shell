#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

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
 * @brief The following function finds
 * the max of two integers
 * @param a
 * @param b
 * @return int
 */
int max(size_t a, size_t b);

#endif //UTILS_H