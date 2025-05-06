#include "minishell.h"

extern int g_signal;

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
	return;
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
	if (g_signal < 0)
	{
		(void)sig;
		write(1, "\n", 1);
		g_signal = SIGINT;
		exit(250);
	}
	return;
	
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