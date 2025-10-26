/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:04:57 by abouzkra          #+#    #+#             */
/*   Updated: 2025/10/20 08:44:06 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const t_uchar	*s;
	t_uchar			*d;

	if (!dest && !src)
		return (NULL);
	s = src;
	d = dest;
	if (d <= s)
	{
		while (n--)
			*(d++) = *(s++);
	}
	else
	{
		while (n--)
			*(d + n) = *(s + n);
	}
	return (dest);
}
