#include "history.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * c_shell_history[C_SHELL_MAX_HISTORY];
size_t his_count = 0;

void c_shell_add_his(const char * cmd)
{
    if (cmd == NULL || strlen(cmd) == 0) return;

    if (his_count < C_SHELL_MAX_HISTORY)
    {
        c_shell_history[his_count++] = strdup(cmd);
    }
    else
    {
        free(c_shell_history[0]);
        memmove(&c_shell_history[0], &c_shell_history[1], sizeof(char*) * (C_SHELL_MAX_HISTORY - 1));
        c_shell_history[C_SHELL_MAX_HISTORY - 1] = strdup(cmd);
    }
}