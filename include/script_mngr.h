#ifndef SCRIPT_MNGR_H

#include "shell.h"
#include <stdlib.h>

/**
 * @brief The following function iterates
 * through a given script file. And calls c_shell_cs_cmd
 * to process the parsed cmd
 * @param filename The script being parsed
 */
void c_shell_cs_init(const char * filename);


/**
 * @brief The following function takes a line and processes
 * the commands, it strictly checks that the commands follow the 
 * C_SHELL LANG Specificiations.
 */
void c_shell_cs_cmd(char * cmd_args[C_SHELL_MAX_ARGS]);


#endif //SCRIPT_MNGR_H