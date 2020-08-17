/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert_d_i.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 15:30:56 by salbregh      #+#    #+#                 */
/*   Updated: 2020/06/03 18:26:11 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_numblength(long n)
{
	int		count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void		ft_value_zero(t_printf *flags)
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
}

static void		ft_padding(long n, t_printf *flags, int len)
{
	if (flags->flag == 0)
		ft_first_padding(n, flags, len, 0);
	if (flags->flag == 1)
		ft_last_padding(n, flags, len);
	if (flags->flag == 2)
		ft_first_padding(n, flags, len, 1);
}

void			ft_convert_d_i(long n, t_printf *flags)
{
	int		len;

	len = ft_numblength(n);
	if (n == 0 && flags->dot == 1)
	{
		ft_value_zero(flags);
		return ;
	}
	if (flags->flag == 2 && flags->prec < flags->width && flags->prec != 0)
		flags->flag = 0;
	if (flags->prec > len || (n < 0 && flags->prec > len - 1))
	{
		flags->prec = flags->prec - len;
		if (n < 0)
			flags->prec++;
	}
	else
		flags->prec = 0;
	if (flags->dot == 1 && flags->flag == 2)
		flags->flag = 0;
	if (flags->width > flags->prec + len)
		flags->width = flags->width - len - flags->prec;
	else
		flags->width = 0;
	ft_padding(n, flags, len);
}
