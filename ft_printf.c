/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puthai <puthai@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:39:38 by puthai            #+#    #+#             */
/*   Updated: 2024/01/08 05:00:09 by puthai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
		i += ft_putchar(str[i]);
	return (i);
}

int	check_type(va_list *args, char c)
{
	int	length;

	length = 0;
	if (c == 'c')
		length += ft_putchar(va_arg(*args, int));
	else if (c == 's')
		length += ft_putstr(va_arg(*args, char *));
	else if (c == 'p')
		length += ft_putnbr_p(va_arg(*args, unsigned long));
	else if (c == 'd' || c == 'i')
		length += ft_putnbr(va_arg(*args, int));
	else if (c == 'u')
		length += ft_putnbr_u(va_arg(*args, unsigned int));
	else if (c == 'x')
		length += ft_putnbr_x(va_arg(*args, unsigned int));
	else if (c == 'X')
		length += ft_putnbr_x2(va_arg(*args, unsigned int));
	else if (c == '%')
		length += ft_putchar('%');
	return (length);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		length;
	int		i;

	length = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			length += check_type(&args, s[i]);
		}
		else
			length += ft_putchar(s[i]);
		i++;
	}
	return (length);
}
