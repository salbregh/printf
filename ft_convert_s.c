/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert_s.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 15:33:26 by salbregh      #+#    #+#                 */
/*   Updated: 2020/05/10 00:45:25 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_negative(t_printf *flags)
{
	if (flags->prec < 0)
	{
		flags->dot = 0;
		flags->prec = 0;
	}
	if (flags->width < 0)
	{
		flags->flag = 1;
		flags->width = -flags->width;
	}
}

static void	ft_print_string(char *str, t_printf *flags)
{
	if (flags->width > ft_strlen(str))
	{
		if (flags->prec < ft_strlen(str) && flags->dot != 0)
			flags->width = flags->width - flags->prec;
		else
			flags->width = flags->width - ft_strlen(str);
	}
	else if (flags->width >= flags->prec)
		flags->width = flags->width - flags->prec;
	if (flags->flag == 1)
	{
		ft_putstr(str, flags, 0);
		ft_put_padding(flags, ' ', flags->width);
	}
	else
	{
		if (flags->flag == 2)
			ft_put_padding(flags, '0', flags->width);
		if (flags->flag == 0)
			ft_put_padding(flags, ' ', flags->width);
		ft_putstr(str, flags, 0);
	}
}

void		ft_convert_s(char *str, t_printf *flags)
{
	if (!str)
		str = "(null)";
	if (flags->prec < 0 || flags->width < 0)
		ft_negative(flags);
	if (flags->dot == 1 && flags->prec == 0)
	{
		if (flags->flag == 2 && flags->width != 0)
			ft_put_padding(flags, '0', flags->width);
		else
			ft_put_padding(flags, ' ', flags->width);
		return ;
	}
	if (flags->width <= ft_strlen(str) &&
	(flags->dot == 0 || flags->width < flags->prec))
		flags->width = 0;
	ft_print_string(str, flags);
}
