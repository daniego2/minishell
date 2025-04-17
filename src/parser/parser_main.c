/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:56:20 by cargonz2          #+#    #+#             */
/*   Updated: 2025/03/19 13:19:06 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Ensure correct handling of every allocation (malloc/calloc).
#include "free.h"
#include "libft.h"
#include "minishell.h"
#include "parser.h"
#include "parser_types.h"
#include "testing.h"
#include "tokenizer.h"
#include "utils1.h"
#include "utils2.h"
#include <assert.h> // WARN: Delete.
#include <stdlib.h>
#include <unistd.h>

static t_tokenizer	*init_tokenizer(void)
{
	t_tokenizer	*tokenizer;

	tokenizer = ft_calloc(1, sizeof(t_tokenizer));
	if (!tokenizer)
		exit(EXIT_FAILURE);
	tokenizer->text = NULL;
	// printf("Tokenizer text: %s\n", tokenizer->text);
	return (tokenizer);
}

int	len(char *s)
{
	return (ft_strlen(s));
}

char	*get_prompt(t_env *env, char *key_a, char *key_b)
{
	char	*prompt;
	t_env	*var_a;
	t_env	*var_b;
	char	*sep_a;
	char	*sep_b;
	int		prompt_len;

	sep_a = "\033[36m ";
	sep_b = "\033[31m > \033[0m";
	var_a = get_environment_variable(env, key_a);
	var_b = get_environment_variable(env, key_b);
	prompt_len = len(sep_a) + len(sep_b);
	if (var_a != NULL)
		prompt_len += len(var_a->value);
	if (var_b != NULL)
		prompt_len += len(var_b->value);
	prompt = ft_calloc(5 + prompt_len + 1, sizeof(char));
	ft_memcpy(prompt, "\033[34m", 5);
	if (var_a != NULL)
	{
		ft_memcpy(&prompt[5], var_a->value, len(var_a->value));
		ft_memcpy(&prompt[len(prompt)], sep_a, len(sep_a));
	}
	if (var_b != NULL)
		ft_memcpy(&prompt[len(prompt)], var_b->value, len(var_b->value));
	ft_memcpy(&prompt[len(prompt)], sep_b, len(sep_b));
	return (prompt);
}

int	main(int argc, char **argv, char **env)
{
	char		*text;
	t_tokenizer	*tokenizer;
	t_token		*tokens;
	t_cmd		*pipeline;
	t_env		*environment;
	int			exit_status;

 	if (argc != 1 || !argv)
		return (1); 
	environment = get_env(env);
	tokenizer = init_tokenizer();
	exit_status = 0;	
	while (true)
	{
		setup_signal_handlers();
		text = NULL;
		text = readline(get_prompt(environment, "USER", "PWD"));
		add_history(text);

		// Esto no debería considerar los espacios "exit   "
		if (text == NULL || ft_strcmp(text, "exit") == 0)
		{
			printf("exit\n");
			break;
		}
		else if (text[0] == '\0')
		continue ;
		tokenizer->text = text;
		tokens = tokenize(tokenizer);
		pipeline = parse_tokens(tokens, environment);
		if (pipeline != NULL)
		{
			// ISSUE: This makes things crash?
			// test_parsed_pipeline(pipeline);
			exit_status = exec(&environment, pipeline, exit_status);
			// printf("Exit Status B: %d\n", pipeline->exit_status);
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
