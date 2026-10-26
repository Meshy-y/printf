/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesh <mesh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 13:34:54 by bsarkoez          #+#    #+#             */
/*   Updated: 2026/10/26 21:14:27 by mesh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *count)
{
	if (!s)
	{
		ft_putstr("(null)", count);
		return ;
	}
	write(1, s, ft_strlen(s));
	*count += ft_strlen(s);
}

void	ft_putchar(char c, int *count)
{
	write (1, &c, 1);
	*count += 1;
}