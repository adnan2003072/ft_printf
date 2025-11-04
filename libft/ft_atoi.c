/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:51:09 by abouzkra          #+#    #+#             */
/*   Updated: 2025/10/26 22:33:07 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_sign(char c, size_t *i)
{
	if (c == '-' || c == '+')
	{
		*i += 1;
		if (c == '-')
			return (-1);
	}
	return (1);
}

int	check_overflow_max(long res, int digit, int sign)
{
	long	long_max;

	long_max = ((long)(~0UL >> 1));
	if (sign == 1 && res > (long_max - digit) / 10)
		return (1);
	return (0);
}

int	check_overflow_min(long res, int digit, int sign)
{
	long	long_min;

	long_min = (long)1 << 63;
	if (sign == -1 && - res < (long_min + digit) / 10)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long	res;
	int		sign;
	int		digit;
	size_t	i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] <= 13 && nptr[i] >= 9))
		i++;
	sign = get_sign(nptr[i], &i);
	res = 0;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		digit = nptr[i] - '0';
		if (check_overflow_max(res, digit, sign) == 1)
			return (-1);
		if (check_overflow_min(res, digit, sign) == 1)
			return (0);
		res = res * 10 + digit;
		i++;
	}
	return ((int)(sign * res));
}
