/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puthai <puthai@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 03:27:39 by puthai            #+#    #+#             */
/*   Updated: 2024/01/08 04:52:06 by puthai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	check_type(va_list *args, char c);
int	ft_putnbr(long nb);
int	ft_putnbr_u(unsigned int nb);
int	ft_putnbr_x(unsigned long nb);
int	ft_putnbr_x2(unsigned int nb);
int	ft_putnbr_p(unsigned long nb);

#endif
