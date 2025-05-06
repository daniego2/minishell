#include "minishell.h"

void update_pwd(t_env **env)
{
    char *path;
    t_env *pwd;

    path = getcwd(NULL, 0);
    if (path == NULL)
        return;
    pwd = get_environment_variable(*env, "PWD");
    free(pwd->value);
    pwd->value = ft_strdup(path);
    free(path);
}


int exec_cd(t_env **env, char **argv)
{
    t_env *home_node;

    home_node = get_environment_variable(*env, "HOME");

    if (!argv[1])
    {
        if (home_node == NULL)
        {
            printf("minishell: cd: HOME not set\n");
            return (1);
        }
        else
            chdir(home_node->value);
    }
    else
		chdir(argv[1]);
    update_pwd(env);
    return (0);
}
