/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:08:42 by abouzkra          #+#    #+#             */
/*   Updated: 2025/10/24 12:16:38 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	contains(const char *set, const char c);

char	*ft_strtrim(const char *s1, const char *set)
{
	char			*res;
	unsigned int	start;
	unsigned int	end;

	if (!s1)
		return (0);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && contains(set, s1[start]))
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (end >= start && contains(set, s1[end]))
		end--;
	res = (char *)malloc(end - start + 2);
	if (!res)
		return (0);
	ft_strlcpy(res, s1 + start, end - start + 2);
	return (res);
}

static int	contains(const char *set, const char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
