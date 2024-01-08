/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puthai <puthai@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 02:39:31 by puthai            #+#    #+#             */
/*   Updated: 2024/01/08 04:51:14 by puthai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long nb)
{
	long	len;

	len = 0;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
	}
	if (nb / 10 > 0)
		len += ft_putnbr(nb / 10);
	len += ft_putchar("0123456789"[nb % 10]);
	return (len);
}

int	ft_putnbr_u(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb / 10 > 0)
		len += ft_putnbr(nb / 10);
	len += ft_putchar("0123456789"[nb % 10]);
	return (len);
}

int	ft_putnbr_x(unsigned long nb)
{
	long	len;

	len = 0;
	if (nb / 16 > 0)
		len += ft_putnbr_x(nb / 16);
	len += ft_putchar("0123456789abcdef"[nb % 16]);
	return (len);
}

int	ft_putnbr_x2(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb / 16 > 0)
		len += ft_putnbr_x2(nb / 16);
	len += ft_putchar("0123456789ABCDEF"[nb % 16]);
	return (len);
}

int	ft_putnbr_p(unsigned long nb)
{	
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_putnbr_x(nb);
	return (len);
}
