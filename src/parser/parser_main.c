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
#include "minishell.h"
#include "parser.h"
#include "parser_types.h"
#include "testing.h"
#include "tokenizer.h"
#include "utils1.h"
#include <stdlib.h>

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

int	main(int argc, char **argv, char **env)
{
	char		*text;
	t_tokenizer	*tokenizer;
	t_token		*tokens;
	t_cmd		*pipeline;
	t_env		*environment;

	if (argc != 1 || !argv)
		return (1);
	environment = malloc(sizeof(t_env) * 2);
	environment = get_env(env);
	tokenizer = init_tokenizer();
	while (true)
	{
		setup_signal_handlers();
		text = NULL;
		text = readline("> ");
		if (text == NULL || ft_strncmp(text, "exit", 5) == 0)
		{
			printf("exit\n");
			return (1);
		}
		else if (text[0] == '\0')
			continue ;
		tokenizer->text = text;
		tokens = tokenize(tokenizer);
		pipeline = parse_tokens(tokens);
		if (pipeline != NULL)
		{
			//test_parsed_pipeline(pipeline); // THIS ONE IS PROBLEMATIC. SECOND INPUT ALWAYS RESULT IN SEGFAULT.
			pipeline->exit_status = exec(&environment, pipeline);
			// WARNING: PIPELINE AND TOKENS CANNOT BE FREED INDEPENDENTLY. ALWAYS KEEP TOGETHER!
			free_pipeline(pipeline);
		}
		free(text);
		free_tokens(tokens);
		printf("TERMINA EL WHILE\n\n\n\n");
	}
	free(tokenizer);
	return (pipeline->exit_status); // ONLY FOR -WExtra FLAG
}
