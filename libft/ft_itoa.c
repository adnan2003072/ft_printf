/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:52:06 by abouzkra          #+#    #+#             */
/*   Updated: 2025/10/21 15:26:19 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	nbr_len(int n);

char	*ft_itoa(int n)
{
	char			*res;
	int				len;
	unsigned int	tmp;

	len = nbr_len(n);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	tmp = (unsigned int)n;
	if (n < 0)
	{
		res[0] = '-';
		tmp = (unsigned int)(-n);
	}
	if (tmp == 0)
		res[0] = '0';
	while (tmp > 0)
	{
		res[--len] = tmp % 10 + '0';
		tmp /= 10;
	}
	return (res);
}

static int	nbr_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}
