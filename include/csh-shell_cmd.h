#ifndef C_SHELL_CMD
#define C_SHELL_CMD

#include "vars.h"

/**
 * @brief The following enum type refers to the
 * available c-shell commands, like exit....
 */
typedef enum {
    CMD_RUN,
    CMD_EXIT,
    CMD_HELP,
    CMD_HISTORY,
    CMD_SET,
    CMD_UNKNOWN
} c_shell_cmd;

/**
 * @brief The following function retrieves the best
 * enum type, dependent on the string passed in.
 * @param cmd A string to find it's enum counterpart
 */
c_shell_cmd get_best_cmd(const char * cmd);

/**
 * @brief The following command exits the shell
 */
void cmd_exit();

/**
 * @brief The following command shows available commands to use.
 */
void cmd_help();

/**
 * @brief The following command displays the history.
 * For the shell.
 */
void cmd_history();

/**
 * @brief The following function calls the command processor
 * for CSH_LANG.
 */
void cmd_run();

/**
 * @brief The following command set's a variables 
 * value in the shell.
 */
void cmd_set(const char * name, const char * val);

#endif //C_SHELL_CMD