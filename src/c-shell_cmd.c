#include "history.h"
#include "shell.h"
#include "utils.h"
#include "c-shell_cmd.h"
#include "script_mngr.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

c_shell_cmd get_best_cmd(const char * cmd)
{
    if (strncmp(cmd, "exit", strlen(cmd)) == 0) return CMD_EXIT;
    if (strncmp(cmd, "help", strlen(cmd)) == 0) return CMD_HELP;
    if (strncmp(cmd, "history", strlen(cmd)) == 0) return CMD_HISTORY;
    if (strncmp(cmd, "run", strlen(cmd)) == 0) return CMD_RUN;
    
    return CMD_UNKNOWN;
}

void cmd_exit()
{
    exit(1);
}

void cmd_run(const char * filename)
{
    if (!filename) 
    {
        printf("Usage: run <scriptfile>\n");
        return;
    }

    csh_lang_init(filename);
}

void cmd_history()
{
    size_t i;

    if (his_count < 1)
    {
        printf("Nothing to show...\n");
        return;
    }

    for (i = 0; i < his_count; i++)
    {
        printf("[%d]: %s\n", i + 1, c_shell_history[i]);
    }
}

void cmd_help()
{
    printf("Available Commands:\n\n");

    printf("exit\n");
    printf("    Terminates the shell program immediately.\n");
    printf("    Usage: exit\n");
    printf("    When you type 'exit', the shell will close and return control to your operating system.\n");
    printf("    Use this command when you want to quit the shell.\n\n");

    printf("help\n");
    printf("    Displays this help text listing available commands and their descriptions.\n");
    printf("    Usage: help\n");
    printf("    Use this command anytime you need a reminder of what commands are available and how to use them.\n");
}