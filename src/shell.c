#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void* shell_mngr(void * param)
{
    while (1)
    {
        printf("Doing stuff\n");
        sleep(10);
    }
    
    
    pthread_exit(NULL);
}