/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <adnanbouzkraouoi037@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:17:23 by abouzkra          #+#    #+#             */
/*   Updated: 2025/10/26 15:14:02 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX "0123456789abcdef"

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int nb);
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_putptr(unsigned long long ptr);
int		ft_puthex(unsigned int nb, char format);

#endif
