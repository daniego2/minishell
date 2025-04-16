/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:45:40 by daniego2          #+#    #+#             */
/*   Updated: 2025/04/16 19:58:13 by daniego2         ###   ########.fr       */
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
#include <sys/wait.h>
#include <signal.h>

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
void	ctrl_c_handler(int sig);
void	ctrl_quit_handler(int sig);
void	setup_signal_handlers();
void	free_list(t_env *env);


// PIPEX.C:
int		create_fork(t_cmd *cmd, char *path, t_env **env, int *standard_input, int exit_status);
int		check_path(t_cmd *cmd, char **env);
int 	exec(t_env **env, t_cmd *cmd, int exit_status);


// PIPEX_UTILS.C:

char	*path_finder(char *target, char **path_batch);
char	**get_path(char **env, char *path);
void	ft_error(t_cmd *cmd, char *message);
void	ft_free_array(char **array);
char 	*get_path_to_program(t_cmd *cmd, t_env **env);
int 	is_path_to_program(char *command);




// TEST_FUNCTIONS.C:
void	print_env (t_env *environment);
void	print_assembled_env(char **env);
void 	init_cmd(t_cmd **cmd);


// BUILT-INS:
int 	is_builtin_pipeless(char *command);
int		is_builtin(char *command);
int 	exec_builtin(t_cmd *cmd, t_env **env, int exit_status);
int 	exec_pwd(void);
int 	exec_echo(char **argv, int exit_status);
int 	exec_env(t_env *env);
int 	exec_export (t_env **env, char **command);
int 	exec_unset(t_env **env, char **command);
int 	exec_cd(t_env **env, char **argv);
void change_current_directory(t_env **env, char *new_dir);
t_env	*get_environment_variable(t_env *env, char *key);


// REDIRECTIONS.C:
int		get_out_fd(t_cmd *cmd);
int 	get_in_fd(t_cmd *cmd);
int 	here_doc(char *filename);
int		here_doc_eof(char *line, char *eof);

int run_pipeline(t_env *environment, t_cmd *cmd);

// 

#endif