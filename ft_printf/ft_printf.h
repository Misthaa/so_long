/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:33:21 by madegryc          #+#    #+#             */
/*   Updated: 2023/11/17 22:29:30 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

size_t		ft_putchar(char c);
size_t		ft_putstr(char *str);
size_t		ft_putnbr(int n);
size_t		ft_putunbr(unsigned int n);
int			ft_print_hexaptr(unsigned long int adr, int depth);
size_t		ft_put_hexaptr_low(unsigned long int n);
size_t		ft_put_hexaptr_up(unsigned long int n);
size_t		ft_format(va_list args, char letter);
int			ft_printf(const char *s, ...);

#endif