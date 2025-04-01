#include "minishell.h"

int run_pipeline(char **env)
{
    t_env *environment;
	char **assembled_env;
	t_token *token;

	environment = NULL;
	assembled_env = NULL;
	token = malloc(sizeof(t_token));
	environment = malloc(sizeof(t_env));

	init_token(&token);
    get_env(env, &environment);

	exec(environment, token); 
    free_env(environment);

    return 0;
}