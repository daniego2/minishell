/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:39:06 by cargonz2          #+#    #+#             */
/*   Updated: 2025/05/05 16:37:36 by cargonz2         ###   ########.fr       */
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

int					g_signal = 0;

static t_tokenizer	*init_tokenizer(void)
{
	t_tokenizer	*tokenizer;

	tokenizer = ft_calloc(1, sizeof(t_tokenizer));
	if (!tokenizer)
		exit(EXIT_FAILURE);
	tokenizer->text = NULL;
	return (tokenizer);
}

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

int	main(int argc, char **argv, char **env)
{
	char		*text;
	t_tokenizer	*tokenizer;
	t_token		*tokens;
	t_cmd		*pipeline;
	t_env		*environment;
	int			exit_status;
	char		*prompt;

	if (argc != 1 || !argv)
		return (1);
	environment = get_env(env);
	tokenizer = init_tokenizer();
	exit_status = 0;
	setup_signal_handlers();
	print_welcome();
	while (true)
	{
		text = NULL;
		prompt = get_prompt(environment, "USER", "PWD");
		text = readline(prompt);
		free(prompt);
		add_history(text);
		if (text == NULL)
		{
			printf("exit\n");
			break ;
		}
		if (g_signal == SIGINT)
		{
			exit_status = 130;
			g_signal = 0;
		}
		else if (is_text_only_whitespace(text))
			continue ;
		tokenizer->text = text;
		tokens = tokenize(tokenizer, environment, exit_status);
		pipeline = parse_tokens(tokens, environment);
		if (pipeline != NULL)
		{
			exit_status = exec(&environment, pipeline, exit_status);
			unlink("/tmp/.here_doc");
			// WARNING: PIPELINE AND TOKENS CANNOT BE FREED INDEPENDENTLY. ALWAYS KEEP TOGETHER!
			free_pipeline(pipeline);
		}
		free(text);
		free_tokens(tokens);
	}
	free_env(environment);
	free(tokenizer);
	return (exit_status);
}
