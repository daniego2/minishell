/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:45:40 by daniego2          #+#    #+#             */
/*   Updated: 2025/04/01 12:23:48 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef enum glosary
{
	IN,
	INN,
	OUT,
	OUTT
}	t_glosary;

typedef struct s_redir
{
	char 	*filename;
	int 	type;
	struct	s_redir *next;
}	t_redir;

typedef struct s_token
{
	char	**command;
	int		in_fd;
	int		out_fd;
	struct	s_token *next;
	struct	s_token *prev;
	struct	s_redir *redir;
}	t_token;

typedef struct s_env
{
	char *key;
	char *value;
	struct s_env *next;
}	t_env;


void			print_env (t_env *env);
void			free_env(t_env *env);
t_env			*create_node(char *key, char *value);
void			add_node(t_env **head, char *key, char *value);
int				envsize(t_env *env);
char			**assemble_env(t_env *env);
void 			get_env(char **env, t_env **environment);

// PIPEX.C:
void	safe_dup2(t_token *token, int fd1, int fd2, int mustclose);
void	create_fork(char **argv, t_token *token, char *path, t_env *env);
int		check_path(t_token *token, char **env);
void 	exec(t_env *env, t_token *token);


// PIPEX_UTILS.C:

char	*path_finder(char **path_batch, char *target, t_token *token);
char	**get_path(char **env, t_token *token, char *path);
void	ft_error(t_token *token, char *message);
void	ft_free_array(char **array);


// TEST_FUNCTIONS.C:
void	print_env (t_env *environment);
void	print_assembled_env(char **env);
void 	init_token(t_token **token);


// BUILT-INS:
int		is_builtin(char *command);
void 	exec_builtin(t_token *token, char **command, t_env *env);
void 	exec_pwd(void);
void 	exec_echo(char **argv);
void 	exec_env(t_env *env);
void 	exec_export (t_env **env, char **command);
void 	exec_unset(t_env **env, char **command);
void 	exec_cd(char **argv);

// REDIRECTIONS.C:
int		get_out_fd(t_token *token);
int 	get_in_fd(t_token *token);
int 	here_doc(char *filename);
int		here_doc_eof(char *line, char *eof);

// 

#endif