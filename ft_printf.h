/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonanno <abonanno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:06:06 by abonanno          #+#    #+#             */
/*   Updated: 2024/12/03 11:32:38 by abonanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int	ft_strlen(char *str);
int	ft_nbrlen(int num);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int num);
int	ft_putnbr_unsigned(unsigned int num);
int	ft_putnbr_hex(unsigned int num);
int	ft_putnbr_hex_upper(unsigned int num);
int	ft_putvdptr(void *ptr);
int	ft_search_type(va_list src, char c);
int	ft_make_print(const char *format, va_list src);
int	ft_printf(const char *format, ...);

#endif