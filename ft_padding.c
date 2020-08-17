/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_padding.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 15:35:14 by salbregh      #+#    #+#                 */
/*   Updated: 2020/05/09 18:14:57 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_put_padding(t_printf *flags, char c, int i)
{
	while (i > 0)
	{
		ft_putchar(c, flags);
		i--;
	}
}

void		ft_first_padding(long n, t_printf *flags, int len, int check)
{
	if (check == 0)
	{
		ft_put_padding(flags, ' ', flags->width);
		ft_putnbr(n, flags, len);
	}
	if (check == 1)
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar('-', flags);
			ft_put_padding(flags, '0', flags->width);
			ft_putnbr(n, flags, len);
		}
		else
		{
			ft_put_padding(flags, '0', flags->width);
			ft_putnbr(n, flags, len);
		}
	}
}

void		ft_last_padding(long n, t_printf *flags, int len)
{
	ft_putnbr(n, flags, len);
	ft_put_padding(flags, ' ', flags->width);
}
