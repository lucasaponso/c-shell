#include "shell.h"
#include "utils.h"
#include "c-shell_cmd.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void csh_lang_cmd(char * cmd_args[C_SHELL_MAX_ARGS])
{
    size_t i;
    for (i = 0; cmd_args[i] != NULL; i++)
    {
        printf("%s\n", cmd_args[i]);
    }
}

void csh_lang_init(const char * filename)
{
    FILE * script;
    size_t i;
    char shell_in[C_SHELL_MAX_CMD];
    char * cmd_args[C_SHELL_MAX_ARGS];

    if ((script = fopen(filename, "r")) == NULL) 
    {
        printf("Could not open script: %s\n", filename);
        return;
    }

    while (fgets(shell_in, sizeof(shell_in), script)) 
    {
        remove_newline(shell_in);
        
        if (strlen(shell_in) == 0 || shell_in[0] == '#') continue;

        delimit_cmd(shell_in, cmd_args);
        
        csh_lang_cmd(cmd_args);
    }

    fclose(script);
}