#include "minishell.h"

int run_pipeline(t_env *environment, t_cmd *token)
{
	exec(environment, token); 
	printf("CMD Executed\n");
    //free_env(environment);
	printf("ENV Free\n");

    return 0;
}