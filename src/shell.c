#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "shell.h"
#include "utils.h"

#define C_SHELL_PREFIX "c-shell> "

char shell_in[C_SHELL_MAX_CMD];

void* shell_mngr(void * param)
{
    char * cmd_args[C_SHELL_MAX_ARGS];
    
    while (1)
    {
        printf("%s", C_SHELL_PREFIX);
        
        if (fgets(shell_in, C_SHELL_MAX_CMD, stdin) == NULL)
        {
            break;
        }

        remove_newline(shell_in);

        if (strncmp(shell_in, "exit", max(strlen(shell_in), strlen("exit"))) == 0)
        {
            printf("Exiting shell...\n");
            goto exit;
        }

        delimit_cmd(shell_in, cmd_args);
        
    }
    goto exit;

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