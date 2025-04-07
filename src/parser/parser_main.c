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

static t_tokenizer	*init_tokenizer()
{
	t_tokenizer	*tokenizer;

	tokenizer = ft_calloc(1, sizeof(t_tokenizer));
	if (!tokenizer)
		exit(EXIT_FAILURE);
	tokenizer->text = NULL;
	//printf("Tokenizer text: %s\n", tokenizer->text);
	return (tokenizer);
}

int	main(int argc, char **argv, char **env)
{
	char		*text;
	t_tokenizer	*tokenizer;
	t_token		*tokens;
	t_cmd		*pipeline;
	t_env		*environment;
	int exit_status;

	exit_status = 0;
	if (argc != 1 || !argv)
	{
		return (1);
	}

	// TESTING
	// text = "Hello\"I like asdf to eat cake on\"ABCDE Wednesdays.";
	// text = "I like asdf\"to eat cake on adfs Wednesdays.";
	/* 	text = "\"I like\" asdf\"to eat\"HHH\"cake on\" adfs Wednesdays.";
		text = "ls -l > \"output.txt\" | grep \".c\" | wc -l";
		text = "ls -l -myflag >> \"output.txt\" < yolo.txt | grep \".c\" | wc "
				"-l << uranus.txt > yomama.txt";
					*/
	// FUNCTIONALITY
	environment = malloc(sizeof(t_env) * 2);
	environment = get_env(env);
	tokenizer = init_tokenizer();

 	while (true)
	{
		text = NULL;
		text = readline("> ");
		if (!text)
		{
			printf("Exiting...\n");
			break;
		}
		//printf("Text: %s\n", text);
		tokenizer->text = text;
		//printf("Tokenizer text: %s\n", tokenizer->text);
		tokens = tokenize(tokenizer);
		pipeline = parse_tokens(tokens);
		test_parsed_pipeline(pipeline);
		exit_status = exec(environment, pipeline);
		// WARNING: BE CAREFUL WITH FREEING THE TOKENS AS THEY PARTLY SHARE MEMORY WITH THE COMMANDS.* 		
		//free_tokens(tokens);
		//free_pipeline(pipeline);
		//free(tokenizer->text); 

		tokenizer->text = NULL;
		tokenizer->cursor = 0;
		free(text);
	} 
	return (exit_status); // ONLY FOR -WExtra FLAG
}
