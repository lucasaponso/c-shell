#ifndef SHELL_H
#define SHELL_H

#define C_SHELL_MAX_CMD 1024
#define C_SHELL_MAX_ARGS 64

/**
 * @brief The following thread, handles incoming text from
 * the user and executes particular commands.
 * @param param
 * @return void
 */
void* shell_mngr(void * th_id);

/**
 * @brief The following function takes a command, and delimits by a 
 * space, and saves each item in an array.
 * @param cmd The cmd to be delimited
 * @param args The output array
 */
void delimit_cmd(char cmd[C_SHELL_MAX_CMD], char *args[C_SHELL_MAX_ARGS]);

#endif //SHELL_H