/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:51:12 by gloukas           #+#    #+#             */
/*   Updated: 2023/01/30 17:05:23 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	i;
	static char	c;

	(void)context;
	i++;
	c = c | (signal == SIGUSR1);
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
	else
		c = c << 1;
	usleep(300);
	if (kill(info->si_pid, SIGUSR1))
	{
		ft_printf("\e[033;0;31m→	Ops!! PID not correct. ❌\e[0m\n");
		exit(1);
	}
}

void	check_args(int ac, char *av[])
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("\e[033;0;31m→	Ops!! Try next time. ❌\e[0m\n");
		exit(1);
	}
}

int	main(int ac, char *av[])
{
	struct sigaction	si;

	check_args(ac, av);
	ft_printf("\e[036;4mMy PID\t➤\e[0m\t%d\n\e[0m\n", getpid());
	ft_printf("\e[038;5;236m ✸Waiting for message from client✸ \e[0m\n\n");
	si.sa_sigaction = signal_handler;
	si.sa_flags = SA_SIGINFO;
	sigemptyset(&si.sa_mask);
	if (sigaction(SIGUSR1, &si, NULL) == -1)
	{
		ft_printf("\e[033;0;31m→	Ops!! PID not correct. ❌\e[0m\n");
		exit(1);
	}
	if (sigaction(SIGUSR2, &si, NULL) == -1)
	{
		ft_printf("\e[033;0;31m→	Ops!! PID not correct. ❌\e[0m\n");
		exit(1);
	}
	while (1)
		pause();
	return (0);
}
