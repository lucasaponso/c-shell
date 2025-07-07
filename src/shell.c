#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "shell.h"
#include "utils.h"

#define C_SHELL_PREFIX "c-shell> "
#define C_SHELL_MAX_CMD 1024

char shell_in[C_SHELL_MAX_CMD];

void* shell_mngr(void * param)
{
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
    }
    goto exit;

    exit:
        pthread_exit(NULL);
    
    
}