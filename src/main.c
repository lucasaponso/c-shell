#include <stdio.h>
#include <pthread.h>
#include "shell.h"

int main(int argc, char ** argv)
{
    pthread_t shell_th_handler;
    int rc;

    rc = pthread_create(&shell_th_handler, NULL, shell_mngr, NULL);
    
    if (rc)
    {
        return -1;
    }
    
    pthread_join(shell_th_handler, NULL);
    
    return 0;
}