/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsarkoez <bsarkoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:02:40 by bsarkoez          #+#    #+#             */
/*   Updated: 2026/10/27 13:43:06 by bsarkoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "unistd.h"
# include "stdlib.h"
# include "stdarg.h"

# include <stdarg.h>
# include <unistd.h>

# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putnbr(long n, int *count);
void	ft_puthex(unsigned long n, char *base, int *count);
void	ft_putptr(void *ptr, int *count);

#endif