/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:55:11 by leyeghia          #+#    #+#             */
/*   Updated: 2022/04/28 14:41:09 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

static int	ft_check(const char format, va_list ap)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_putchar(va_arg(ap, int));
	else if (format == 's')
		len = ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
		len = ft_putpointer(va_arg(ap, unsigned long));
	else if (format == 'd' || format == 'i')
		len = ft_putnbr(va_arg(ap, int));
	else if (format == 'u')
		len = ft_putunsigned(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		len = ft_puthex(va_arg(ap, unsigned int), format);
	else if (format == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, str);
	if (!str)
		return (0);
	while (str && str[i])
	{
		if (str[i] == '%')
		{	
			len += ft_check(str[++i], ap);
			i++;
		}
		else if (str && str[i] != '%')
		{
			len += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(ap);
	return (len);
}
