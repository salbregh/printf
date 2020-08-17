/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert_p.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 15:31:50 by salbregh      #+#    #+#                 */
/*   Updated: 2020/06/03 22:06:48 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_puthex_p(unsigned long i, t_printf *flags)
{
	unsigned long	tmp;
	char			c;

	while (flags->prec > 0)
	{
		ft_putchar('0', flags);
		flags->prec--;
	}
	if (i == 0)
		return ;
	if (i > 15)
		ft_puthex_p(i / 16, flags);
	tmp = i % 16;
	if (tmp > 9 && tmp < 16)
	{
		c = (i % 16) + 'W';
		ft_putchar(c, flags);
	}
	else
	{
		c = (i % 16) + '0';
		ft_putchar(c, flags);
	}
}

static void		ft_value_zero(t_printf *flags)
{
	if (flags->dot != 0 && flags->flag == 0)
	{
		if (flags->flag == 0 && flags->dot != 0)
			ft_put_padding(flags, ' ', flags->width);
		ft_putstr("0x", flags, 1);
		if (flags->flag == 1 && flags->width != 0)
			ft_put_padding(flags, ' ', flags->width);
	}
	else
	{
		if (flags->flag != 1 && flags->width != 0)
			ft_put_padding(flags, ' ', flags->width);
		ft_putstr("0x0", flags, 2);
		if (flags->flag == 1 && flags->width != 0)
			ft_put_padding(flags, ' ', flags->width);
	}
}

static void		ft_print_hex(unsigned long i, t_printf *flags)
{
	if (flags->flag == 1)
	{
		ft_putstr("0x", flags, 1);
		ft_puthex_p(i, flags);
		ft_put_padding(flags, ' ', flags->width);
	}
	else if (flags->flag == 2)
	{
		ft_putstr("0x", flags, 1);
		ft_put_padding(flags, '0', flags->width);
		ft_puthex_p(i, flags);
	}
	else
	{
		ft_put_padding(flags, ' ', flags->width);
		ft_putstr("0x", flags, 1);
		ft_puthex_p(i, flags);
	}
}

static	void	ft_whenzero(t_printf *flags)
{
	ft_put_padding(flags, ' ', flags->width);
	ft_putstr("0x", flags, 1);
}

void			ft_convert_p(unsigned long i, t_printf *flags)
{
	int		len;

	len = ft_strlen_hex(i) + 2;
	if (i == 0 && flags->dot == 1)
		len--;
	if (flags->prec > len - 2)
		flags->prec = flags->prec - (len - 2);
	else
		flags->prec = 0;
	if (flags->width > len && flags->width > flags->prec + (len - 2))
		flags->width = flags->width - len - flags->prec;
	else
		flags->width = 0;
	if (i == 0 && flags->prec == 0)
	{
		ft_value_zero(flags);
		return ;
	}
	if ((i == 0 || i == 0x0) && flags->prec == 0 && flags->dot != 0)
	{
		ft_whenzero(flags);
		return ;
	}
	else
		ft_print_hex(i, flags);
}
