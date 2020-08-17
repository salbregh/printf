/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_flags.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 15:34:28 by salbregh      #+#    #+#                 */
/*   Updated: 2020/05/09 19:12:05 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_wildcard(t_printf *flags, va_list argptr)
{
	if (flags->dot == 0)
	{
		flags->width = va_arg(argptr, int);
		if (flags->width < 0)
		{
			flags->width = -flags->width;
			flags->flag = 1;
		}
	}
	if (flags->dot == 1)
	{
		flags->prec = va_arg(argptr, int);
		if (flags->prec < 0)
		{
			flags->dot = 0;
			flags->prec = 0;
		}
	}
}

int			ft_flags(const char *str, int i, t_printf *flags, va_list argptr)
{
	while (str[i] != 'c' && str[i] != 'd' && str[i] != 'i' && str[i] != 'p' &&
		str[i] != 's' && str[i] != 'u' && str[i] != 'x' && str[i] != 'X' &&
		str[i] != '%')
	{
		if (str[i] == '-')
			flags->flag = 1;
		if (str[i] == '.')
			flags->dot = 1;
		if (str[i] == '0' && flags->flag != 1 && flags->dot == 0)
			flags->flag = 2;
		if (str[i] >= '0' && str[i] <= '9')
			i = ft_find_length(str, i, flags->dot, flags);
		if (str[i] == '*')
			ft_wildcard(flags, argptr);
		i++;
	}
	return (i);
}
