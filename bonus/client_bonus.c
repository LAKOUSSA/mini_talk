/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:51:03 by gloukas           #+#    #+#             */
/*   Updated: 2023/01/30 17:06:31 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

int		g_pid;

void	check_args(int ac, char *av[])
{
	int	i;

	i = -1;
	if (ac != 3)
	{
		ft_printf("\e[033;0;31m→	Ops!! Try next time. ❌\e[0m\n");
		exit(1);
	}
	if (ft_atoi(av[1]) <= 0)
	{
		ft_printf("\e[033;0;31m→	Ops!! PID not correct. ❌\e[0m\n");
		exit(1);
	}
	while (av[1][++i])
	{
		if (!ft_isdigit(av[1][i]))
		{
			ft_printf("\e[033;0;31m→	Ops!! PID not correct. ❌\e[0m\n");
			exit(1);
		}
	}
}

void	send_byte_by_byte(int shift, char c, int pid)
{
	while (shift-- > 0)
	{
		if ((c >> shift) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("\e[033;0;31m→	Ops!! PID not correct. ❌\e[0m\n");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("\e[033;0;31m→	Ops!! PID not correct. ❌\e[0m\n");
				exit(1);
			}
		}
		pause();
		usleep(300);
	}
}

void	succes(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (signal == SIGUSR1 && g_pid == info->si_pid)
		ft_printf("\e[033;0;32m→	Sent signal to server. ✅\e[0m\n");
	else
	{
		ft_printf("\e[033;0;31m→	Wrong signal. ❌\e[0m\n");
		exit(1);
	}
}

int	main(int ac, char *av[])
{
	int					i;
	int					shift;
	struct sigaction	si;

	check_args(ac, av);
	i = 0;
	g_pid = ft_atoi(av[1]);
	shift = 32;
	si.sa_sigaction = succes;
	si.sa_flags = SA_SIGINFO;
	sigemptyset(&si.sa_mask);
	if (sigaction(SIGUSR1, &si, NULL) == -1)
	{
		ft_printf("\e[033;0;31m→	Ops!! PID not correct. ❌\e[0m\n");
		exit(1);
	}
	while (av[2][i])
	{
		shift = 8;
		send_byte_by_byte(shift, av[2][i], g_pid);
		i++;
	}
	send_byte_by_byte(shift, '\n', g_pid);
	return (0);
}
