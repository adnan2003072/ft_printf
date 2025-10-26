/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <adnanbouzkraouoi037@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:38:22 by abouzkra          #+#    #+#             */
/*   Updated: 2025/10/25 23:20:23 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

void	ft_formats(va_list args, char c, int *len)
{
	if (c == 'c')
		*len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		*len += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		*len += ft_putptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		*len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		*len += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		*len += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == '%')
		*len += ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_formats(args, str[i + 1], &len);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
