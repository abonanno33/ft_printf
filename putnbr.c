/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonanno <abonanno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:34:47 by abonanno          #+#    #+#             */
/*   Updated: 2024/12/03 11:41:53 by abonanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num)
{
	int	len;

	len = ft_nbrlen(num);
	if (num == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		num = 147483648;
		len = ft_nbrlen(num) + 2;
	}
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar(num + 48);
	return (len);
}

int	ft_putnbr_unsigned(unsigned int num)
{
	int				len;
	unsigned int	num_app;

	len = 0;
	num_app = num;
	if (num_app == 0)
		len = 1;
	while (num_app != 0)
	{
		num_app = num_app / 10;
		len++;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar(num + 48);
	return (len);
}

int	ft_putnbr_hex(unsigned int num)
{
	int				len;
	unsigned int	num_app;

	len = 0;
	num_app = num;
	if (num_app == 0)
		len = 1;
	while (num_app != 0)
	{
		num_app = num_app / 16;
		len++;
	}
	if (num >= 16)
	{
		ft_putnbr_hex(num / 16);
		ft_putnbr_hex(num % 16);
	}
	else
	{
		if (num < 10)
			ft_putchar(num + 48);
		else
			ft_putchar(num + 87);
	}
	return (len);
}

int	ft_putnbr_hex_upper(unsigned int num)
{
	int				len;
	unsigned int	num_app;

	len = 0;
	num_app = num;
	if (num_app == 0)
		len = 1;
	while (num_app != 0)
	{
		num_app = num_app / 16;
		len++;
	}
	if (num >= 16)
	{
		ft_putnbr_hex_upper(num / 16);
		ft_putnbr_hex_upper(num % 16);
	}
	else
	{
		if (num < 10)
			ft_putchar(num + 48);
		else
			ft_putchar(num + 55);
	}
	return (len);
}

int	ft_putvdptr(void *ptr)
{
    uintptr_t	num;
    int			len;

    num = (uintptr_t) ptr;

    if (num == (uintptr_t)LONG_MIN)
        len = ft_putstr("0x8000000000000000");
    else if (num == (uintptr_t)LONG_MAX)
        len = ft_putstr("0x7fffffffffffffff");
    else if (num == (uintptr_t)ULONG_MAX)
        len = ft_putstr("0xffffffffffffffff");
    else if (num == (uintptr_t)(-1))
        len = ft_putstr("-0xffffffffffffffff");
	else if (num == 0)
		len = ft_putstr("(nil)");
    else
    {
		len = ft_putstr("0x");
        len += ft_putnbr_hex((uintptr_t) ptr);
    }
    return (len);
}
