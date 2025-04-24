#include "minishell.h"

void	ctrl_c_handler(int sig)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ctrl_quit_handler(int sig)
{
	printf("\n");
	printf("Quit\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
void setup_signal_handlers()
{
    signal(SIGQUIT, ctrl_quit_handler);
    signal(SIGINT, ctrl_c_handler);
}