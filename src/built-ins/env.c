#include "minishell.h"

int exec_env(t_env **env)
{
	t_env *aux;

	aux = *env;
	while (aux != NULL)
	{
		printf("%s=%s\n", aux->key, aux->value);
		aux = aux->next;
	}
	return (0);
}