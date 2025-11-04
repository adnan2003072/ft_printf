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
//
// static int	addr_len(unsigned long long ptr)
// {
// 	int	i;
//
// 	i = 2;
// 	while (ptr >= 16)
// 	{
// 		ptr /= 16;
// 		i++;
// 	}
// 	return (i);
// }
//
// int	ft_putptr(unsigned long long ptr)
// {
// 	char	*res;
// 	int		len;
//
// 	if (ptr == 0)
// 	{
// 		ft_putstr("(nil)");
// 		return (5);
// 	}
// 	len = addr_len(ptr);
// 	res = (char *)malloc(len + 1);
// 	res[0] = '0';
// 	res[1] = 'x';
// 	res[len] = '\0';
// 	while (len >= 2)
// 	{
// 		res[len] = HEX[ptr % 16];
// 		ptr /= 16;
// 		len--;
// 	}
// 	len = ft_strlen(res);
// 	ft_putstr(res);
// 	free(res);
// 	return (len);
// }

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
