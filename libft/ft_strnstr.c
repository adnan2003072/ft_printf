/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:38:24 by abouzkra          #+#    #+#             */
/*   Updated: 2025/10/24 12:54:46 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	if (little[0] == '\0')
		return ((char *)big);
	if (!big && len == 0)
		return (NULL);
	little_len = ft_strlen(little);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && j < little_len
			&& (i + j) < len)
		{
			if (big[i + j] != little[j])
				break ;
			j++;
		}
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
