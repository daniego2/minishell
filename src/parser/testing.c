/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:47:29 by cargonz2          #+#    #+#             */
/*   Updated: 2025/04/01 13:33:34 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// WARN: delete!
#include "parser_types.h"
#include "stdio.h"

// WARN: Delete.
void	test_parsed_pipeline(t_cmd *pipeline)
{
	t_redir	*redir;

	printf("\n\nFINAL PARSING\n");
	for (int i = 0; pipeline != NULL; i++)
	{
		printf("\nCOMMAND #%d:\n", i);
		// Print command itself.
		for (int j = 0; pipeline->command[j] != NULL; j++)
		{
			if (j == 0)
			{
				printf("command: %s\n", pipeline->command[0]);
			}
			else
			{
				printf("argument #%d: %s\n", j, pipeline->command[j]);
			}
		}
		redir = pipeline->redir;
		for (int j = 0; redir != NULL; j++)
		{
			printf("\nRedir #%d:\n", j);
			printf("type: %d\n", redir->type);
			printf("filename: %s\n", redir->filename);
			redir = redir->next;
		}
		pipeline = pipeline->next;
		printf("\n");
	}
}
