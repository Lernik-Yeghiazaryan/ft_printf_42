/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:45:30 by leyeghia          #+#    #+#             */
/*   Updated: 2022/04/27 20:23:45 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int				ft_putchar(char c);
int				ft_putstr(char *s);
int				ft_putpointer(unsigned long p);
int				ft_putnbr(int d);
int				ft_putunsigned(unsigned int u);
int				ft_puthex(unsigned long x, const char f);
int				ft_printf(const char *str, ...);

#endif
