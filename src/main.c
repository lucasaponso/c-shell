#include <stdio.h>
#include <pthread.h>
#include "shell.h"
#include "users.h"

/**
 * @brief The following function is the entry
 * point of the program. Starts by creating a thread
 * to manage SHELL.
 * @return int
 */
int main(int argc, char * argv[])
{
    pthread_t shell_th_handler;
    int rc;
    FILE * ptr = stdin;

    if (argc > 1)
    {
        ptr = fopen(argv[1], "r");
        if (!ptr)
        {
            printf("File does not exist\n");
            return -1;
        }   
    }

    load_active_user_c_shell();

    rc = pthread_create(&shell_th_handler, NULL, shell_mngr, ptr);
    
    if (rc)
    {
        return -1;
    }
    
    pthread_join(shell_th_handler, NULL);
    
    return 0;
}