/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:47:29 by cargonz2          #+#    #+#             */
/*   Updated: 2025/03/28 14:22:43 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// WARN: delete!
#include "parser_types.h"
#include "stdio.h"

// WARN: Delete.
void	test_parsed_pipeline(t_command_node *pipeline)
{
	t_redir	*redir;

	printf("\n\nFINAL PARSING\n");
	for (int i = 0; pipeline != NULL; i++)
	{
		printf("\nCOMMAND #%d:\n", i);
		// Print command itself.
		for (int j = 0; pipeline->command_str_arr[j] != NULL; j++)
		{
			if (j == 0)
			{
				printf("command: %s\n", pipeline->command_str_arr[0]);
			}
			else
			{
				printf("argument #%d: %s\n", j, pipeline->command_str_arr[j]);
			}
		}
		redir = pipeline->redir;
		for (int j = 0; redir != NULL; j++)
		{
			printf("\nRedir #%d:\n", j);
			printf("type: %d\n", redir->type);
			printf("filename: %s\n", redir->filename);
			redir = redir->next_redir;
		}
		pipeline = pipeline->next;
		printf("\n");
	}
}
