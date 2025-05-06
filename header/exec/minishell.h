/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:45:40 by daniego2          #+#    #+#             */
/*   Updated: 2025/05/05 18:45:35 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../../libft/libft.h"
# include "parser_types.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdarg.h>
# include <stdbool.h>
# include <sys/wait.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_io
{
	int				*standard_input;
	int				fd[2];
}					t_io;

char				**assemble_env(t_env *env);

void				handle_child_process(t_cmd *cmd, char *path, t_env **env,
						t_io io);
int					handle_parent_process(int pid, int *standard_input, int *fd,
						int exit_status);
int					create_fork(t_cmd *cmd, char *path, t_env **env,
						int *standard_input);

char				*path_finder(char *target, char **path_batch);
char				**get_path(char **env, char *path);
char				*find_env_path(char **env_cpy);
char				*process_path_directories(char *command, char *env_path);
char				*get_path_to_program(t_cmd *cmd, t_env **env);

int					is_path_to_program(char *command);
int					handle_standard_command(t_cmd *cmd, t_env **env, char *path,
						int *standard_input);
int					process_command(t_cmd *cmd, t_env **env,
						int *standard_input, int exit_status);
int					exec(t_env **env, t_cmd *cmd, int exit_status);

char			**allocate_no_delimiter(char *str);
char			**allocate_with_delimiter(char *str, char *delimiter_pos);
char				**ft_split_first(char *str, char delimiter);
t_env				*get_env(char **env);

int					envsize(t_env *env);
t_env				*create_node(char *key, char *value);
void				add_node(t_env **head, char *key, char *value);

void				free_env(t_env *env);
void				ft_free_array(char **array);

void			handle_heredoc_child(int temp_fd, char *delimiter,
						t_env *env, bool is_quoted);
int			handle_heredoc_parent(int pid);
int					here_doc(char *delimiter, bool is_quoted, t_env *env);
int					get_out_fd(t_cmd *cmd);
int					get_in_fd(t_cmd *cmd, t_env *env);

void				ctrl_c_handler(int sig);
void				ctrl_quit_handler(int sig);
void				ctrl_quit_handler_hd(int sig);
void				ctrl_c_handler_hd(int sig);
void				setup_signal_handlers(void);
void				setup_signal_handlers_hd(void);

int					is_builtin(char *command);
int					is_builtin_pipeless(char *command);
int					exec_builtin(t_cmd *cmd, t_env **env, int exit_status);

void				update_pwd(t_env **env);
int					exec_cd(t_env **env, char **argv);
int					is_valid_flag(char *argv);
int					exec_echo(char **argv);
int					exec_env(t_env *env);
int					update_existing_env(t_env *env, char *key, char *value);
void				swap_env(t_env *a, t_env *b);
void				sort_env(t_env **env);
t_env				*copy_env(t_env *env);
void				print_sorted_env(t_env *env);
char				*get_key(char *command);
char				*get_value(char *command);
int					exec_export(t_env **env, char **command);
int					exec_pwd(void);
int					exec_unset(t_env **env, char **command);
int					exec_exit(char **command);

t_env				*get_environment_variable(t_env *env, char *key);
char				*expand_heredoc_str(char *str, t_env *environment,
						int exit_status);
void				free_pipeline(t_cmd *command_node);
void 				print_among_us(int exit_status);
int					delimiter_is_quoted(char *delimiter);
void 				print_welcome(void);

#endif
