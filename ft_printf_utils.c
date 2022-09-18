/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:43:35 by leyeghia          #+#    #+#             */
/*   Updated: 2022/06/12 18:11:18 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s && s[i])
	{
		write(1, &s[i], sizeof(char));
		i++;
	}
	return (i);
}

int	ft_putpointer(unsigned long p)
{
	int	len;
	int	m;

	m = 0;
	write (1, "0x", 2);
	len = 2;
	len += ft_puthex(p, 'x');
	return (len);
}

int	ft_putnbr(int d)
{
	int	len;

	len = 0;
	if (d == -2147483648)
	{
		len += ft_putchar('-');
		len += ft_putchar('2');
		len += ft_putnbr(147483648);
	}
	else if (d < 0)
	{
		len += ft_putchar('-');
		len += ft_putnbr(-d);
	}
	else if (d > 9)
	{
		len += ft_putnbr(d / 10);
		len += ft_putnbr(d % 10);
	}
	else
		len += ft_putchar(d + 48);
	return (len);
}

int	ft_putunsigned(unsigned int u)
{
	int	len;

	len = 0;
	if (u > 9)
		len += ft_putunsigned(u / 10);
	len += ft_putchar(u % 10 + 48);
	return (len);
}

int	ft_puthex(unsigned long x, const char f)
{
	int	len;

	len = 0;
	if (x > 15)
		len += ft_puthex(x / 16, f);
	x = x % 16;
	if (x < 10)
		len += ft_putchar(x + 48);
	else if (f == 'x')
		len += ft_putchar(x + 87);
	else
		len += ft_putchar(x + 55);
	return (len);
}
