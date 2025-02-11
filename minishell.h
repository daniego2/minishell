/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:45:40 by daniego2          #+#    #+#             */
/*   Updated: 2025/02/05 20:39:31 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		out_fd;
	int		prev_fd;
	char	*path;
	char	**path_batch;
	char	**command;
	char 	**env;
	struct	s_pipex *next;
}	t_pipex;

typedef struct s_env
{
	char *key;
	char *value;
	struct s_env *next;
}	t_env;

typedef struct s_token  //David dice que esto es una puta mierda y que no se debe hacer asi
{
	int argc;
	char **argv;
	char **command;
	t_list *redireciones;
	t_list *enviroment_ramon;
	int fd[2];
	char *flag;
	struct s_token *next;
	char *path;
}	t_token;

void			print_env (t_env *env);
void			free_env(t_env *env);
t_env			*create_node(char *key, char *value);
void			add_node(t_env **head, char *key, char *value);
int				envsize(t_env *env);
char			**assemble_env(t_env *env);
void 			get_env(char **env, t_env **environment);

// PIPEX.C:
void	execute_process(t_pipex *t_pipex, int fd[2]);
void	setup_child(t_pipex *t_pipex, int fd[2]);
void	create_fork(char **argv, t_pipex *t_pipex);
int		main(int argc, char **argv, char **env);
void 	do_pipex(char **env, t_pipex *t_pipex);


// PIPEX_UTILS.C:
t_pipex	*init_struct(void);
char	*path_finder(char **path_batch, char *target);
char	**get_path(char **env, t_pipex *t_pipex);
void	ft_error(char *message);
void	ft_free_array(char **array);


// TEST_FUNCTIONS.C:
void	print_env (t_env *environment);
void	print_assembled_env(char **env);
void 	init_token(t_token *token);
void 	init_pipex(t_pipex **t_pipex);

#endif