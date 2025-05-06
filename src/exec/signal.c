/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:31:08 by daniego2          #+#    #+#             */
/*   Updated: 2025/05/06 16:31:20 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int g_signal;

void	ctrl_c_handler(int sig)
{
	(void)sig;
	g_signal = SIGINT;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ctrl_quit_handler(int sig)
{
	(void)sig;
	rl_redisplay();
}

void	ctrl_quit_handler_hd(int sig)
{
	(void)sig;
}

void	ctrl_c_handler_hd(int sig)
{
	(void)sig;
	g_signal = SIGINT;		if (!line)
	{
		printf("minishell: warning: here-document delimited by end-of-file (wanted `%s')\n",
			delimiter);
		break ;
	}
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	exit(1);
}

void setup_signal_handlers(void)
{
    signal(SIGQUIT, SIG_IGN);
    signal(SIGINT, ctrl_c_handler);

}

void setup_signal_handlers_hd(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ctrl_c_handler_hd);
}