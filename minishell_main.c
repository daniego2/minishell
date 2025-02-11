#include "minishell.h"

int main(int argc, char **argv, char **env)
{
    t_env *environment;
	char **assembled_env;
	t_token *token;
	t_pipex *pipex;

	environment = NULL;
	assembled_env = NULL;
	token = malloc(sizeof(t_token));
	pipex = malloc(sizeof(t_pipex));
	environment = malloc(sizeof(t_env));
	//init_token(token);
	
	init_pipex(&pipex);
	//environment = NULL;
    get_env(env, &environment);
	assembled_env = assemble_env(environment);
	//print_assembled_env(assembled_env);
	do_pipex(assembled_env, pipex);
    free_env(environment);

    return 0;
}