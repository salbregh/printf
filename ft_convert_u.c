/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert_u.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 15:33:44 by salbregh      #+#    #+#                 */
/*   Updated: 2020/05/27 10:03:33 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_numblength(long i)
{
	int		count;

	count = 1;
	if (i < 0)
	{
		if (i == -2147483648)
			return (11);
		count++;
		i = -i;
	}
	while (i >= 10)
	{
		i = i / 10;
		count++;
	}
	return (count);
}

static void		ft_zero_value(t_printf *flags)
{
	if (flags->prec == 0)
	{
		if (flags->width > 0)
			ft_put_padding(flags, ' ', flags->width);
		return ;
	}
	else
	{
		if (flags->flag == 0)
		{
			ft_put_padding(flags, ' ', flags->width - flags->prec);
			ft_put_padding(flags, '0', flags->prec);
		}
		if (flags->flag == 1)
		{
			ft_put_padding(flags, '0', flags->prec);
			ft_put_padding(flags, ' ', flags->width - flags->prec);
		}
		if (flags->flag == 2)
		{
			ft_put_padding(flags, ' ', flags->width - flags->prec);
			ft_put_padding(flags, '0', flags->prec);
		}
	}
	return ;
}

void			ft_convert_u(unsigned int n, t_printf *flags)
{
	long		len;

	len = ft_numblength(n);
	if (n == 0 && flags->dot == 1)
	{
		ft_zero_value(flags);
		return ;
	}
	if (flags->flag == 2 && flags->prec < flags->width && flags->prec != 0)
		flags->flag = 0;
	if (flags->prec > len)
		flags->prec = flags->prec - len;
	else
		flags->prec = 0;
	if (flags->width > flags->prec + len)
		flags->width = flags->width - len - flags->prec;
	else
		flags->width = 0;
	if (flags->flag == 0)
		ft_first_padding(n, flags, len, 0);
	if (flags->flag == 1)
		ft_last_padding(n, flags, len);
	if (flags->flag == 2)
		ft_first_padding(n, flags, len, 1);
}
