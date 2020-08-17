/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert_hex.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 15:33:59 by salbregh      #+#    #+#                 */
/*   Updated: 2020/05/09 18:26:07 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_set_flags(t_printf *flags, int len)
{
	if (flags->prec > len)
		flags->prec = flags->prec - len;
	else
		flags->prec = 0;
	if (flags->width > (len + flags->prec))
		flags->width = flags->width - len - flags->prec;
	else
		flags->width = 0;
}

void		ft_convert_hex(unsigned int i, int caps, t_printf *flags)
{
	int	len;

	len = ft_strlen_hex(i);
	if (flags->dot == 1 && flags->prec == 0 && i == 0)
	{
		ft_put_padding(flags, ' ', flags->width);
		return ;
	}
	ft_set_flags(flags, len);
	if (flags->flag == 1)
	{
		ft_puthex(i, caps, flags, len);
		ft_put_padding(flags, ' ', flags->width);
	}
	else
	{
		if (flags->flag == 0)
			ft_put_padding(flags, ' ', flags->width);
		else if (flags->dot != 0 && (flags->prec <= flags->width ||
			flags->prec > flags->width))
			ft_put_padding(flags, ' ', flags->width);
		else
			ft_put_padding(flags, '0', flags->width);
		ft_puthex(i, caps, flags, len);
	}
}
