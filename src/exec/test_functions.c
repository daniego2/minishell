// Estas funciones solo estan para testear cosas, no son parte del proyecto

#include "minishell.h"

void print_env (t_env *env)
{
    while (env != NULL)
    {
        printf("Key: %s,        Value: %s\n", env->key, env->value);
        env = env->next;
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

void init_cmd(t_cmd **token)
{
	t_cmd *aux = *token;
	t_cmd *aux2;
	t_cmd *aux3;
	t_redir *redir;
	t_redir *redir2;
	char **environment;


/*  TEST 1: ls -l | wc -l > ennove.txt > charizard.txt */
/*
	aux->command = malloc(sizeof(char *) * 7);
	aux->command[0] = "ls\0";
	aux->command[1] = "-l\0";
	aux->command[2] = NULL;
	aux->prev = NULL;
	aux->redir = NULL;

	aux->next = NULL;

 	aux->next = malloc(sizeof(t_cmd));
	aux = aux->next;

	redir = malloc(sizeof(t_redir));
	redir->filename = "ennove.txt";
	redir->type = OUT;

	redir2 = malloc(sizeof(t_redir));
	redir->next = redir2;
	redir2->filename = "charizard.txt";
	redir2->type = OUT;
	redir2->next = NULL;

	aux->redir = redir;
	aux->command = malloc(sizeof(char *) * 3);
	aux->command[0] = "wc\0";
	aux->command[1] = "-l\0";
	aux->command[2] = NULL;
*/


/*  TEST 2: cat hola.txt | wc -l > mondongo.txt*/

/*
	redir = malloc(sizeof(t_redir));
	redir->filename = "mondongo.txt";
	redir->type = OUT;
	redir->next = NULL;

	aux->command = malloc(sizeof(char *) * 7);
	aux->command[0] = "cat\0";
	aux->command[1] = "hola.txt\0";
	aux->command[2] = NULL;
	aux2 = malloc(sizeof(t_cmd));
	aux->next = aux2;

	aux2->command = malloc(sizeof(char *) * 7);
	aux2->command[0] = "wc\0";
	aux2->command[1] = "-l\0";
	aux2->command[2] = NULL;
	aux2->redir = redir;
	aux2->next = NULL;

*/
/*	TEST 3: env*/
/*
	aux->command = malloc(sizeof(char *) * 7);
	aux->command[0] = "env\0";
	aux->command[1] = NULL;
	aux->next = NULL;
*/

/*  TEST 4: export CHARIZARD=ennove | unset USER | env*/
/*
	aux->command = malloc(sizeof(char *) * 3);
	aux->command[0] = "export\0";
	aux->command[1] = "CHARIZARD=ennove\0";
	aux->command[2] = NULL;
	aux2 = malloc(sizeof(t_cmd));
	aux->next = aux2;

	aux2->command = malloc(sizeof(char *) * 2);
	aux2->command[0] = "unset\0";
	aux2->command[1] = "USER\0";
	aux2->command[2] = NULL;
	aux3 = malloc(sizeof(t_cmd));
	aux2->next = aux3;

	aux3->command = malloc(sizeof(char *) * 2);
	aux3->command[0] = "env\0";
	aux3->command[1] = NULL;
	aux3->next = NULL;
*/

/* TEST 5: << eof wc -l */
/*
	redir = malloc(sizeof(t_redir));
	redir->filename = "eof";
	redir->type = INN;
	redir->next = NULL;

	aux->command = malloc(sizeof(char *) * 4);
	aux->command[0] = "wc\0";
	aux->command[1] = "-l\0";
	aux->command[2] = NULL;
	aux->redir = redir;
	aux->next = NULL;
*/
/* TEST 6: << eof wc -l | << eoff cat*/

/*
	redir = malloc(sizeof(t_redir));
	redir->filename = "eof";
	redir->type = INN;
	redir->next = NULL;

	aux->command = malloc(sizeof(char *) * 4);
	aux->command[0] = "wc\0";
	aux->command[1] = "-l\0";
	aux->command[2] = NULL;
	aux->redir = redir;
	aux2 = malloc(sizeof(t_cmd));
	aux->next = aux2;

	redir2 = malloc(sizeof(t_redir));
	redir2->filename = "eoff";
	redir2->type = INN;
	redir2->next = NULL;

	aux2->command = malloc(sizeof(char *) * 2);
	aux2->command[0] = "cat\0";
	aux2->command[1] = NULL;
	aux2->redir = redir2;
	aux2->next = NULL;
*/


/* TEST 6: cd built-ins*/
/*
	aux->command = malloc(sizeof(char *) * 7);
	aux->command[0] = "cd\0";
	aux->command[1] = "built-ins\0";
	aux->command[2] = NULL;
*/
}