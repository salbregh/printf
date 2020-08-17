/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert_per.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 15:33:14 by salbregh      #+#    #+#                 */
/*   Updated: 2020/05/09 18:57:29 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_convert_per(t_printf *flags)
{
	if (flags->width > 1)
		flags->width = flags->width - 1;
	else
		flags->width = 0;
	if (flags->flag == 1)
	{
		ft_putchar('%', flags);
		ft_put_padding(flags, ' ', flags->width);
	}
	else if (flags->flag == 2)
	{
		ft_put_padding(flags, '0', flags->width);
		ft_putchar('%', flags);
	}
	else
	{
		ft_put_padding(flags, ' ', flags->width);
		ft_putchar('%', flags);
	}
}
