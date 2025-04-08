/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:45:40 by daniego2          #+#    #+#             */
/*   Updated: 2025/04/07 20:07:56 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "../../libft/libft.h"
# include "parser_types.h"
# include <stdlib.h>
# include <fcntl.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

/*
typedef struct s_token
{
	char	**command;
	int		in_fd;
	int		out_fd;
	struct	s_token *next;
	struct	s_redir *redir;
}	t_token;
*/
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
t_env 			*get_env(char **env);

// PIPEX.C:
void	safe_dup2(t_cmd *token, int fd1, int fd2, int mustclose);
int	create_fork(t_cmd *token, char *path, t_env **env, int *standard_input);
int		check_path(t_cmd *token, char **env);
int 	exec(t_env **env, t_cmd *token);


// PIPEX_UTILS.C:

char	*path_finder(char **path_batch, char *target);
char	**get_path(char **env, char *path);
void	ft_error(t_cmd *token, char *message);
void	ft_free_array(char **array);


// TEST_FUNCTIONS.C:
void	print_env (t_env *environment);
void	print_assembled_env(char **env);
void 	init_cmd(t_cmd **token);


// BUILT-INS:
int 	is_builtin_pipeless(char *command);
int		is_builtin(char *command);
int 	exec_builtin(char **command, t_env **env);
int 	exec_pwd(void);
int 	exec_echo(char **argv);
int 	exec_env(t_env **env);
int 	exec_export (t_env **env, char **command);
int 	exec_unset(t_env **env, char **command);
int 	exec_cd(char **argv);

// REDIRECTIONS.C:
int		get_out_fd(t_cmd *token);
int 	get_in_fd(t_cmd *token);
int 	here_doc(char *filename);
int		here_doc_eof(char *line, char *eof);

int run_pipeline(t_env *environment, t_cmd *token);

// 

#endif