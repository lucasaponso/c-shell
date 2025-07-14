#include <stdio.h>
#include <pthread.h>
#include "shell.h"
#include "users.h"
#include "vars.h"
#include "log.h"
#include <unistd.h>
#include "log.h"
#include "utils.h"

pthread_t shell_th_handler;

/**
 * @brief The following function is the entry
 * point of the program. Starts by creating a thread
 * to manage SHELL.
 * @return int
 */
int main(int argc, char * argv[])
{
    c_shell_init_syslog();
    load_active_user_c_shell();
    c_shell_set_var_env();

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

    
    rc = pthread_create(&shell_th_handler, NULL, shell_mngr, ptr);
    
    if (rc)
    {
        c_shell_log("Shell failed to init", C_SHELL_LOG_CRIT);
        return -1;
    }
    
    pthread_join(shell_th_handler, NULL);
    
    return 0;
}