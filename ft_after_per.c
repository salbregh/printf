/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_after_per.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 15:27:03 by salbregh      #+#    #+#                 */
/*   Updated: 2020/05/09 16:55:44 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_after_per(const char *str, int i, t_printf *flags, va_list argptr)
{
	i = ft_flags(str, i, flags, argptr);
	if (str[i] == 'c')
		ft_convert_c(va_arg(argptr, int), flags);
	if (str[i] == 'd' || str[i] == 'i')
		ft_convert_d_i(va_arg(argptr, int), flags);
	if (str[i] == 'p')
		ft_convert_p(va_arg(argptr, unsigned long), flags);
	if (str[i] == 's')
		ft_convert_s(va_arg(argptr, char *), flags);
	if (str[i] == 'u')
		ft_convert_u(va_arg(argptr, unsigned int), flags);
	if (str[i] == 'x')
		ft_convert_hex(va_arg(argptr, unsigned int), 0, flags);
	if (str[i] == 'X')
		ft_convert_hex(va_arg(argptr, unsigned int), 1, flags);
	if (str[i] == '%')
		ft_convert_per(flags);
	if (str[i] != 'c' && str[i] != 'd' && str[i] != 'i' && str[i] != 'p' &&
		str[i] != 's' && str[i] != 'u' && str[i] != 'x' && str[i] != 'X' &&
		str[i] != '%')
		return (-1);
	i++;
	ft_free_flags(flags, 0);
	return (i);
}
