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
int main(void)
{
    pthread_t shell_th_handler;
    int rc;

    load_active_user_c_shell();

    rc = pthread_create(&shell_th_handler, NULL, shell_mngr, NULL);
    
    if (rc)
    {
        return -1;
    }
    
    pthread_join(shell_th_handler, NULL);
    
    return 0;
}