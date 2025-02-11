// Estas funciones solo estan para testear cosas, no son parte del proyecto

#include "minishell.h"

void print_env (t_env *environment)
{
    while (environment != NULL)
    {
        printf("Key: %s,        Value: %s\n", environment->key, environment->value);
        environment = environment->next;
    }
}

void print_assembled_env(char **env)
{
	int i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
void print_token(t_token *token)
{

}

void init_token(t_token *token)
{
	token->argc = 2;
	token->argv = NULL;
	token->redireciones = NULL;
	token->enviroment_ramon = NULL;
	token->fd[0] = 0;
	token->fd[1] = 0;
	token->flag = NULL;
	token->command = malloc(sizeof(char *) * 3);
	token->command[0] = malloc(sizeof(char) * 3);
	token->command[0] = "ls\0";
	token->command[1] = malloc(sizeof(char) * 3);
	token->command[1] = "-l\0";
	token->command[2] = NULL;
	token->path = "/bin/ls";
}

void init_pipex(t_pipex **ppx)
{
	t_pipex *aux = *ppx;
	
	aux->out_fd = 0;
	aux->prev_fd = 0;
	aux->path = "/bin/ls";
	aux->path_batch = NULL;
	aux->command = malloc(sizeof(char *) * 2);
	aux->command[0] = "ls\0";
	aux->command[1] = NULL;
	aux->env = NULL;
	aux->next = NULL;

	aux->next = malloc(sizeof(t_pipex));
	aux = aux->next;

	aux->out_fd = 0;
	aux->prev_fd = 0;
	aux->path = "/usr/bin/ping";
	aux->path_batch = NULL;
	aux->command = malloc(sizeof(char *) * 5);
	aux->command[0] = ft_strdup("ping");
	aux->command[1] = ft_strdup("google.com");
	aux->command[2] = ft_strdup("-c");
	aux->command[3] = ft_strdup("4");
	aux->command[4] = NULL;
	aux->env = NULL;
	aux->next = NULL;


}