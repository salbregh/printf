/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 15:34:57 by salbregh      #+#    #+#                 */
/*   Updated: 2020/06/03 11:14:45 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_va_end(va_list argptr, int i)
{
	va_end(argptr);
	if (i == 1)
		return (-1);
	else
		return (0);
}

int				ft_printf(const char *str, ...)
{
	t_printf	flags;
	va_list		argptr;
	int			i;

	va_start(argptr, str);
	i = 0;
	ft_free_flags(&flags, 1);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			i = ft_after_per(str, i, &flags, argptr);
			if (i == -1)
				return (ft_va_end(argptr, 1));
		}
		else
		{
			ft_putchar(str[i], &flags);
			i++;
		}
	}
	ft_free_flags(&flags, 0);
	ft_va_end(argptr, 0);
	return (flags.rv);
}
