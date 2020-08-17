/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/17 18:52:20 by salbregh      #+#    #+#                 */
/*   Updated: 2020/05/09 17:16:54 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_puthex(unsigned int i, int caps, t_printf *flags, int len)
{
	unsigned int		tmp;
	char				c;

	while (flags->prec)
	{
		flags->prec--;
		ft_putchar('0', flags);
	}
	if (i > 15)
		ft_puthex(i / 16, caps, flags, len);
	tmp = i % 16;
	if (tmp > 9 && tmp < 16)
	{
		if (caps == 1)
			c = (i % 16) + '7';
		else
			c = (i % 16) + 'W';
		ft_putchar(c, flags);
	}
	else
	{
		c = (i % 16) + '0';
		ft_putchar(c, flags);
	}
}
