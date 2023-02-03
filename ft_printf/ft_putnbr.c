/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:38:41 by gloukas           #+#    #+#             */
/*   Updated: 2022/10/29 08:38:45 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	len;
	int	nb;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		len += 11;
	}
	else if (n < 0)
	{
		nb = -n;
		len += ft_putchar('-');
		len += ft_putnbr(nb);
	}
	else
	{
		if (n > 9)
			len += ft_putnbr(n / 10);
		len += ft_putchar(n % 10 + 48);
	}
	return (len);
}
