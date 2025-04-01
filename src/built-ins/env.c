#include "../minishell.h"

void exec_env(t_env *env)
{
	int i = 0;
	while (env != NULL)
	{
		printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}