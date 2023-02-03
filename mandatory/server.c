/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:50:47 by gloukas           #+#    #+#             */
/*   Updated: 2023/01/30 17:07:48 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	signal_handler(int signal)
{
	static int	i;
	static char	c;

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
	check_args(ac, av);
	ft_printf("\e[036;4mMy PID\t➤\e[0m\t%d\n\e[0m\n", getpid());
	ft_printf("\e[038;5;236m ✸Waiting for message from client✸ \e[0m\n\n");
	if (signal(SIGUSR1, signal_handler) == SIG_ERR)
	{
		ft_printf("\e[033;0;31m→	Ops!! PID not correct. ❌\e[0m\n");
		exit(1);
	}
	if (signal(SIGUSR2, signal_handler) == SIG_ERR)
	{
		ft_printf("\e[033;0;31m→	Ops!! PID not correct. ❌\e[0m\n");
		exit(1);
	}
	while (1)
		pause();
	return (0);
}
