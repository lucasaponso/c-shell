#ifndef PROMPT_H
#define PROMPT_H

#define C_SHELL_MAX_PROMPT 1024

/**
 * @brief The following function builds the shell
 * prompt. It contains the hostname, user.
 * @param prompt The prompt to be printed to the screen in the
 * shell
 */
void build_shell_prompt(char prompt[C_SHELL_MAX_PROMPT]);

#endif //PROMPT_H