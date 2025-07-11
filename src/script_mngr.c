#include "shell.h"
#include "utils.h"
#include "csh-shell_cmd.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void csh_lang_parser(const char * filename)
{
    FILE * script;
    char shell_in[C_SHELL_MAX_CMD];
    char * cmd_args[C_SHELL_MAX_ARGS];

    if (!(script = fopen(filename, "r")))
    {
        printf("Could not open script: %s\n", filename);
        return;  
    }

    while (fgets(shell_in, sizeof(shell_in), script)) 
    {
        remove_newline(shell_in);
        
        if (strlen(shell_in) == 0 || shell_in[0] == '#') continue;

        delimit_cmd(shell_in, cmd_args);
        
        exec_c_shell_cmd(cmd_args);
    }

    fclose(script);
}