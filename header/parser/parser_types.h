/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:57:39 by cargonz2          #+#    #+#             */
/*   Updated: 2025/03/28 14:12:13 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_TYPES_H
# define PARSER_TYPES_H
# include <stdbool.h>

typedef struct s_tokenizer
{
	char					*text;
	int						cursor;
}							t_tokenizer;

typedef enum token_type
{
	TOKEN_END,
	TOKEN_WORD,
	TOKEN_REDIR_OUT,
	TOKEN_APPEND,
	TOKEN_REDIR_IN,
	TOKEN_HEREDOC,
	TOKEN_PIPE,
}							t_token_type;

typedef struct s_token
{
	t_token_type			type;
	char					*str;
	struct s_token			*next;
}							t_token;

enum						redir_type
{
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_IN,
	REDIR_HEREDOC,
};

typedef struct s_redir
{
	char					*filename;
	enum redir_type			type;
	struct s_redir			*next_redir;
}							t_redir;

typedef struct s_command_node
{
	char **command_str_arr; // NOTE: program_name + args + NULL
	struct s_command_node	*next;
	t_redir					*redir;
}							t_command_node;

#endif
