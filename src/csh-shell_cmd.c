#include "history.h"
#include "shell.h"
#include "utils.h"
#include "csh-shell_cmd.h"
#include "script_mngr.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "users.h"
#include <vars.h>

c_shell_cmd get_best_cmd(const char * cmd)
{
    if (strncmp(cmd, "exit", strlen(cmd)) == 0) return CMD_EXIT;
    if (strncmp(cmd, "help", strlen(cmd)) == 0) return CMD_HELP;
    if (strncmp(cmd, "history", strlen(cmd)) == 0) return CMD_HISTORY;
    if (strncmp(cmd, "run", strlen(cmd)) == 0) return CMD_RUN;
    if (strncmp(cmd, "set", strlen(cmd)) == 0) return CMD_SET;
    if (strncmp(cmd, "get", strlen(cmd)) == 0) return CMD_GET;
    if (strncmp(cmd, "cd", strlen(cmd)) == 0) return CMD_CD;
    if (strncmp(cmd, "getu", strlen(cmd)) == 0) return CMD_GET_USER;
    
    return CMD_UNKNOWN;
}

void cmd_set(const char * name, const char * val)
{
    ShellVar var_to_set;

    if (name == NULL || val == NULL)
    {
        return;
    }

    if (name[0] != '@')
    {
        return;
    }
    
    strncpy(var_to_set.name, name, MAX_VAR_NAME - 1);
    strncpy(var_to_set.value, val, MAX_VAR_VALUE - 1);

    if (var_count >= MAX_VARIABLES)
    {
        printf("Too many variables in system\n");
        return;
    }

    c_shell_set_var(var_to_set);
}

void cmd_get(const char * name)
{
    if (name[0] != '@')
    {
        return;
    }
    
    const char * output = c_shell_get_var(name);

    if (output != NULL)
    {
        printf("%s\n", output);
        return;
    }

    printf("Unknown variable: %s\n", name);
    
}


void cmd_exit()
{
    shell_running = 0;
}

void cmd_run(const char * filename)
{
    if (!filename) 
    {
        printf("Usage: run <scriptfile>\n");
        return;
    }

    csh_lang_parser(filename);
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
    printf("    Use this command anytime you need a reminder of what commands are available and how to use them.\n\n");

    printf("set\n");
    printf("    Sets a shell variable with a given name and value.\n");
    printf("    Usage: set <name> <value>\n");
    printf("    Use this to store values you can reference later in scripts or commands.\n\n");

    printf("run\n");
    printf("    Executes a script file containing shell commands.\n");
    printf("    Usage: run <scriptfile>\n");
    printf("    The script file should contain valid shell commands, one per line.\n\n");

    printf("history\n");
    printf("    Displays a list of all previously executed commands in the current session.\n");
    printf("    Usage: history\n");
    printf("    Helpful for recalling or reusing past commands.\n\n");
}

void cmd_cd(const char * dir)
{
    if (dir == NULL)
    {
        dir = getenv("HOME");
    }

    if (chdir(dir) != 0)
    {
        printf("dir does not exist\n");
    }


    return;
}

void cmd_get_user()
{
    printf("Username      : %s\n", pw->pw_name);
    printf("Password (x)  : %s\n", pw->pw_passwd);  // Usually "x" or "*"
    printf("User ID (UID) : %d\n", pw->pw_uid);
    printf("Group ID (GID): %d\n", pw->pw_gid);
    printf("User Info     : %s\n", pw->pw_gecos);   // Full name/comment field
    printf("Home Dir      : %s\n", pw->pw_dir);
    printf("Shell         : %s\n", pw->pw_shell);
}