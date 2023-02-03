/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hlow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 09:07:30 by gloukas           #+#    #+#             */
/*   Updated: 2022/10/29 09:07:32 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hlow(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 0 && n <= 9)
		len += ft_putchar(n + 48);
	else if (n >= 10 && n < 16)
		len += ft_putchar(n + 87);
	else
	{
		len += ft_putnbr_hlow(n / 16);
		len += ft_putnbr_hlow(n % 16);
	}
	return (len);
}
