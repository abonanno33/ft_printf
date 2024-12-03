/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonanno <abonanno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:35:13 by abonanno          #+#    #+#             */
/*   Updated: 2024/12/03 11:32:56 by abonanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_search_type(va_list src, char c)
{
	if (c == 'c')
		return (ft_putchar((char) va_arg(src, int)));
	if (c == 's')
		return (ft_putstr((char *) va_arg(src, char *)));
	if (c == 'p')
		return (ft_putvdptr(va_arg(src, void *)));
	if (c == 'd')
		return (ft_putnbr((int) va_arg(src, int)));
	if (c == 'i')
		return (ft_putnbr((int) va_arg(src, int)));
	if (c == 'u')
		return (ft_putnbr_unsigned((unsigned int) va_arg(src, unsigned int)));
	if (c == 'x')
		return (ft_putnbr_hex((unsigned int) va_arg(src, int)));
	if (c == 'X')
		return (ft_putnbr_hex_upper((unsigned int) va_arg(src, int)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_make_print(const char *format, va_list src)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_search_type(src, format[i]);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	src;
	int		count;

	va_start(src, format);
	count = ft_make_print(format, src);
	va_end(src);
	return (count);
}
