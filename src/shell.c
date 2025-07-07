#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"
#include "utils.h"
#include "prompt.h"

char shell_in[C_SHELL_MAX_CMD];

void* shell_mngr(void * param)
{
    char * cmd_args[C_SHELL_MAX_ARGS];
    char prompt[C_SHELL_MAX_PROMPT];
    pid_t pid;

    build_shell_prompt(prompt);
    
    while (1)
    {

        printf("%s", prompt);
        
        if (fgets(shell_in, C_SHELL_MAX_CMD, stdin) == NULL)
        {
            break;
        }

        remove_newline(shell_in);
        delimit_cmd(shell_in, cmd_args);

        pid = fork();

        if (pid == 0)
        {
            execvp(cmd_args[0], cmd_args);
            goto exit;
        }
        else if (pid > 0)
        {
            waitpid(pid, NULL, 0);
        }
        else
        {
            printf("Fork failed\n");
            goto exit;
        }
    }

    exit:
        pthread_exit(NULL);
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