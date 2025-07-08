#ifndef HISTORY_H
#define HISTORY_H

#include <stdlib.h>

#define C_SHELL_MAX_HISTORY 1000

/**
 * @brief Array holding history
 */
extern char * c_shell_history[C_SHELL_MAX_HISTORY];

/**
 * @brief Tracker of size of history array
 */
extern size_t his_count;

/**
 * @brief The following function adds a cmd 
 * to the history array
 * @param cmd Command to add to the history array
 */
void c_shell_add_his(const char * cmd);

#endif //HISTORY_H