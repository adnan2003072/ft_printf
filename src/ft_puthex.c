/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <adnanbouzkraouoi037@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 22:45:12 by abouzkra          #+#    #+#             */
/*   Updated: 2025/10/25 23:19:40 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_puthex(unsigned int nb, char format)
{
	int	len;

	len = 0;
	if (nb >= 16)
		len += ft_puthex(nb / 16, format);
	if (format == 'x' || nb % 16 < 10)
		ft_putchar(HEX[nb % 16]);
	if (format == 'X' && nb % 16 >= 10)
		ft_putchar(HEX[nb % 16] - 32);
	len++;
	return (len);
}
