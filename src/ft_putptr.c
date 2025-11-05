/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <adnanbouzkraouoi037@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:53:19 by abouzkra          #+#    #+#             */
/*   Updated: 2025/10/26 23:35:18 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_puthex_long(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr >= 16)
		len += ft_puthex_long(ptr / 16);
	ft_putchar(HEX[ptr % 16]);
	len++;
	return (len);
}

int	ft_putptr(unsigned long long ptr)
{
	if (ptr == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	return (ft_puthex_long(ptr) + 2);
}
