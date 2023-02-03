/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 08:21:31 by gloukas           #+#    #+#             */
/*   Updated: 2022/10/31 08:21:35 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_help1(const char *s, va_list ap, int i)
{
	int	len;

	len = 0;
	if (s[i] == 'p')
		len += ft_putnbr_add(va_arg(ap, void *));
	else if (s[i] == 'd' || s[i] == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (s[i] == 'u')
		len += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (s[i] == 'x')
		len += ft_putnbr_hlow(va_arg(ap, unsigned int));
	else if (s[i] == 'X')
		len += ft_putnbr_hupp(va_arg(ap, unsigned int));
	return (len);
}

static int	ft_help2(const char *s, va_list ap, int i)
{
	int		len;
	char	*p;

	len = 0;
	if (s[i] == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (s[i] == 's')
	{
		p = va_arg(ap, char *);
		if (p == NULL)
		{
			len += ft_putstr("(null)");
		}
		else
			len += ft_putstr(p);
	}
	else if (s[i] == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	va_list(ap);
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] == '\0')
			return (len);
		while (s[i] != '%' && s[i])
		{
			len += ft_putchar(s[i]);
			i++;
		}
		if (s[i] == '%' && s[i++])
		{
			len += ft_help1(s, ap, i);
			len += ft_help2(s, ap, i);
			i++;
		}
	}
	va_end(ap);
	return (len);
}
