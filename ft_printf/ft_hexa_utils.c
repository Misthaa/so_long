/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:33:33 by madegryc          #+#    #+#             */
/*   Updated: 2023/11/17 21:37:15 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexaptr(unsigned long int adr, int depth)
{
	int	len;

	len = 0;
	if (adr == 0)
		return (write (1, "(nil)", 5));
	if (!depth)
		len += write(1, "0x", 2);
	if (adr >= 16)
		len += ft_print_hexaptr(adr / 16, depth + 1);
	len += ft_putchar("0123456789abcdef"[adr % 16]);
	return (len);
}

size_t	ft_put_hexaptr_low(unsigned long int n)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_put_hexaptr_low(n / 16);
	len += ft_putchar("0123456789abcdef"[n % 16]);
	return (len);
}

size_t	ft_put_hexaptr_up(unsigned long int n)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_put_hexaptr_up(n / 16);
	len += ft_putchar("0123456789ABCDEF"[n % 16]);
	return (len);
}
