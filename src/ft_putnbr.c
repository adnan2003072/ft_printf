/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <adnanbouzkraouoi037@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 22:11:09 by abouzkra          #+#    #+#             */
/*   Updated: 2025/10/25 23:19:49 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
		len++;
	}
	if (nb >= 10)
		len += ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
	len++;
	return (len);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
		len += ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
	len++;
	return (len);
}
