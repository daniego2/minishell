/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_hd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniego2 <daniego@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:01:37 by daniego2          #+#    #+#             */
/*   Updated: 2025/05/07 16:14:47 by daniego2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_signal;

void	setup_signal_handlers_hd(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ctrl_c_handler_hd);
}

void	ctrl_quit_handler_hd(int sig)
{
	(void)sig;
}

void	ctrl_c_handler_hd(int sig)
{
	if (g_signal < 0)
	{
		(void)sig;
		write(1, "\n", 1);
		g_signal = SIGINT;
		exit(250);
	}
	return ;
}
