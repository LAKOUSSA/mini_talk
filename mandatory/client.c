/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:50:49 by gloukas           #+#    #+#             */
/*   Updated: 2023/01/31 16:52:12 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

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
		usleep(300);
	}
}

int	main(int ac, char *av[])
{
	int	pid;
	int	i;
	int	shift;

	check_args(ac, av);
	i = 0;
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		shift = 8;
		send_byte_by_byte(shift, av[2][i], pid);
		i++;
	}
	send_byte_by_byte(shift, '\n', pid);
	return (0);
}
