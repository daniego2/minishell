/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego <daniego@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:57:39 by cargonz2          #+#    #+#             */
/*   Updated: 2025/05/06 14:15:19 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_TYPES_H
# define PARSER_TYPES_H
# include <stdbool.h>

typedef enum e_error
{
	ERROR_NONE,
	ERROR_BAD_ALLOCATION,
	ERROR_BAD_TOKEN,
}						t_error;

typedef struct s_tokenizer
{
	char				*text;
	int					cursor;
}						t_tokenizer;

typedef enum token_type
{
	TOKEN_END,
	TOKEN_WORD,
	TOKEN_REDIR_OUT,
	TOKEN_APPEND,
	TOKEN_REDIR_IN,
	TOKEN_HEREDOC,
	TOKEN_PIPE,
}						t_token_type;

typedef struct s_token
{
	t_token_type		type;
	char				*str;
	struct s_token		*next;
	bool				is_quoted;
}						t_token;

enum					e_redir_type
{
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_IN,
	REDIR_HEREDOC,
};

typedef struct s_redir
{
	char				*filename;
	bool				is_quoted;
	enum e_redir_type	type;
	struct s_redir		*next;
}						t_redir;

typedef struct s_cmd
{
	char				**command;
	struct s_cmd		*next;
	int					in_fd;
	int					out_fd;
	int					exit_status;
	t_redir				*redir;
}						t_cmd;

struct					s_separators
{
	char				*sep_a;
	char				*sep_b;
};

typedef struct s_string_data
{
	char				*str;
	int					key_len;
	int					value_len;
	int					cursor;
	int					quote_a;
	int					quote_b;
}						t_string_data;

#endif
