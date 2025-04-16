#include "minishell.h"

int exec_cd(t_env **env, char **argv)
{
    if (!argv[1])
    {
		//getenv() NO EXISTE EN EL PROYECTO
        if (chdir(getenv("HOME")) != 0)
        {
            perror("cd: No Home directory");
            return (1);
        }
    }
    else
	{
		chdir(argv[1]);
	}
    return (0);
}
