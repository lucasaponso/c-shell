#ifndef C_SHELL_CMD

/**
 * @brief The following enum type refers to the
 * available c-shell commands, like exit....
 */
typedef enum {
    CMD_EXIT,
    CMD_HELP,
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


#endif //C_SHELL_CMD