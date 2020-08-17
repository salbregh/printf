/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 15:35:47 by salbregh      #+#    #+#                 */
/*   Updated: 2020/05/09 17:17:12 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr(long n, t_printf *flags, int len)
{
	char	c;

	if (n < 0)
	{
		ft_putchar('-', flags);
		n = -n;
	}
	while (flags->prec)
	{
		flags->prec--;
		ft_putchar('0', flags);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, flags, len);
		ft_putnbr(n % 10, flags, len);
	}
	else
	{
		c = n + '0';
		ft_putchar(c, flags);
	}
}
