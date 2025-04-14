#include "minishell.h"

int exec_cd(char **argv)
{
    if (!argv[1])
    {
        // Cambiar getenv() por la expansión de la variable de entorno HOME
        if (chdir(getenv("HOME")) != 0)
        {
            perror("cd: No Home directory");
            return (1);
        }
    }
    else
    {
        if (chdir(argv[1]) != 0)
        {
            perror("cd");
            return (1); 
        }
    }
    return (0);
}
