#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdint.h>
#include <signal.h>
#include "shell.h"
#include "utils.h"
#include "prompt.h"
#include "csh-shell_cmd.h"
#include "history.h"

char shell_in[C_SHELL_MAX_CMD];

volatile sig_atomic_t shell_running = 1;

void exec_c_shell_cmd(char * cmd_args[C_SHELL_MAX_ARGS])
{
    uint8_t cmd;
    pid_t pid;
    char full_cmd[C_SHELL_MAX_CMD] = "";

    if (cmd_args[0] == NULL) return;

    for (int i = 0; cmd_args[i] != NULL; ++i) 
    {
        strcat(full_cmd, cmd_args[i]);
        strcat(full_cmd, " ");
    }
    
    full_cmd[strcspn(full_cmd, "\n")] = '\0'; // Remove trailing newline if any
    c_shell_add_his(full_cmd);

    if ((cmd = get_best_cmd(cmd_args[0])) != CMD_UNKNOWN)
    {
        switch (cmd)
        {
            case CMD_RUN:
                cmd_run(cmd_args[1]);
                break;
            case CMD_EXIT:
                cmd_exit();
                break;
            case CMD_SET:                    
                cmd_set(cmd_args[1], cmd_args[2]);
                break;
            case CMD_CD:                    
                cmd_cd(cmd_args[1]);
                break;
            case CMD_GET:                    
                cmd_get(cmd_args[1]);
                break;
            case CMD_HELP:
                cmd_help();
                break;
            case CMD_HISTORY:
                cmd_history();
                break;
            
            default:
                break;
        }

        return;
    }
    
    pid = fork();

    if (pid == 0)
    {
        signal(SIGINT, SIG_DFL); //Enable ctrl-c, when child process is running
        execvp(cmd_args[0], cmd_args);
    }
    else if (pid > 0)
    {
        waitpid(pid, NULL, 0);
    }
    else
    {
        printf("Fork failed\n");
        pthread_exit(NULL);
    }
    return;
}

void* shell_mngr(void * param)
{
    char * cmd_args[C_SHELL_MAX_ARGS];
    char prompt[C_SHELL_MAX_PROMPT];
    pid_t pid;
    uint8_t cmd;
    ShellVar var_to_set;
    
    FILE *input = (FILE *)param;

    signal(SIGINT, SIG_IGN); //Disable ctrl-c

    build_shell_prompt(prompt);
    
    while (shell_running)
    {
        if (input == stdin)
        { 
            printc(COLOR_BLUE, "%s", prompt);
        }
        
        if (fgets(shell_in, C_SHELL_MAX_CMD, input) == NULL)
        {
            break;
        }

        remove_newline(shell_in);
        delimit_cmd(shell_in, cmd_args);

        exec_c_shell_cmd(cmd_args);
    }
}

void delimit_cmd(char cmd[C_SHELL_MAX_CMD], char * args[C_SHELL_MAX_ARGS])
{
    char * token = strtok(cmd, " ");
    size_t i = 0;
    
    while ((token != NULL) && (i < C_SHELL_MAX_ARGS - 1))
    {
        args[i++] = token;
        token = strtok(NULL, " ");
    }

    args[i] = NULL;
}