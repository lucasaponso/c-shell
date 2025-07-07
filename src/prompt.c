#include "prompt.h"
#include "users.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <pwd.h>

void build_shell_prompt(char prompt[C_SHELL_MAX_PROMPT])
{
    char hostname[64];
        
    memset(hostname, 0, sizeof(hostname));
    memset(prompt, 0, C_SHELL_MAX_PROMPT);

    if (gethostname(hostname, sizeof(hostname)) != 0)
    {
        return;
    }

    if (!pw->pw_name)
    {
        return;
    }

    strcpy(prompt, pw->pw_name);
    strcat(prompt, "@");
    strcat(prompt, hostname);
    strcat(prompt, " ");

    return;
}




