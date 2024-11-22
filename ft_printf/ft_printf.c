/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:12:07 by madegryc          #+#    #+#             */
/*   Updated: 2023/11/17 21:39:13 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_format(va_list args, char letter)
{
	if (letter == 'c')
		return (ft_putchar(va_arg(args, unsigned int)));
	else if (letter == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (letter == 'p')
		return (ft_print_hexaptr(va_arg(args, unsigned long int), 0));
	else if (letter == 'd' || letter == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (letter == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (letter == 'x')
		return (ft_put_hexaptr_low(va_arg(args, unsigned int)));
	else if (letter == 'X')
		return (ft_put_hexaptr_up(va_arg(args, unsigned int)));
	else if (letter == '%')
		return (ft_putchar('%'));
	return (0);
}

int	is_valid(char l)
{
	return (l == 'c' || l == 's' || l == 'p' || l == 'd'
		|| l == 'i' || l == 'u' || l == 'x' || l == 'X' || l == '%');
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = -1;
	len = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while (s[++i])
	{
		if (s[i] == '%' && is_valid(s[i + 1]))
		{
			len += ft_format(args, s[i + 1]);
			i += 1;
		}
		else if (s[i] == '%' && s[i + 1] == 0)
			len = -1;
		else
			len += ft_putchar(s[i]);
	}
	va_end(args);
	return (len);
}
