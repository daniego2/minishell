/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:39:06 by cargonz2          #+#    #+#             */
/*   Updated: 2025/05/07 22:00:39 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Ensure correct handling of every allocation (malloc/calloc).
#include "free.h"
#include "libft.h"
#include "minishell.h"
#include "parser.h"
#include "parser_types.h"
#include "prompt.h"
#include "tokenizer.h"
#include "utils1.h"
#include <assert.h> // WARN: Delete.
#include <stdlib.h>
#include <unistd.h>
#include "main_helper.h"

int					g_signal = 1;

bool	is_text_only_whitespace(char *text)
{
	int	i;

	i = 0;
	while (text[i] != '\0' && ft_isspace(text[i]))
		i++;
	if (text[i] == '\0')
		return (true);
	else
		return (false);
}

int	check_signal(int exit_status)
{
	if (g_signal == SIGINT)
	{
		g_signal = 0;
		exit_status = 130;
	}
	return (exit_status);
}

int	run_exec(t_env *env, t_cmd *pipeline, int exit_status)
{
	if (pipeline != NULL)
	{
		exit_status = exec(&env, pipeline, exit_status);
		unlink("/tmp/.here_doc");
		free_pipeline(pipeline);
	}
	return (exit_status);
}

int	main_loop(t_env *env, t_tokenizer *tokenizer, t_token *tokens,
	t_cmd *pipeline)
{
	char	*text;
	char	*prompt;
	int		exit_status;

	exit_status = 0;
	while (true)
	{
		text = NULL;
		prompt = get_prompt(env, "USER", "PWD");
		text = readline(prompt);
		free(prompt);
		add_history(text);
		if (text == NULL)
			break ;
		exit_status = check_signal(exit_status);
		if (is_text_only_whitespace(text))
			continue ;
		tokenizer->text = text;
		tokens = tokenize(tokenizer, env, exit_status);
		pipeline = parse_tokens(tokens, env);
		exit_status = run_exec(env, pipeline, exit_status);
		free(text);
		free_tokens(tokens);
	}
	return (exit_status);
}

int	main(int argc, char **argv, char **env)
{
	t_tokenizer	*tokenizer;
	t_env		*environment;
	int			exit_status;
	t_token		*tokens;
	t_cmd		*pipeline;

	if (argc != 1 || !argv)
		return (1);
	environment = get_env(env);
	tokenizer = init_tokenizer();
	exit_status = 0;
	setup_interactive_signals();
	print_welcome();
	tokens = NULL;
	pipeline = NULL;
	exit_status = main_loop(environment, tokenizer, tokens, pipeline);
	free_env(environment);
	free(tokenizer);
	printf("exit\n");
	return (exit_status);
}
