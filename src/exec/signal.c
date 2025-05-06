/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:20:15 by daniego2          #+#    #+#             */
/*   Updated: 2025/05/06 19:20:16 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

void	ctrl_c_handler(int sig)
{
	if (g_signal > 0)
	{
		(void)sig;
		printf("\n");
		rl_on_new_line();
		if (g_signal != 4)
			rl_redisplay();
		g_signal = 2;
		rl_replace_line("", 0);
	}
	return ;
}

void	ctrl_quit_handler(int sig)
{
	(void)sig;
	rl_redisplay();
}

void	setup_signal_handlers(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ctrl_c_handler);
}
