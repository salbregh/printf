/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_length.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 15:34:13 by salbregh      #+#    #+#                 */
/*   Updated: 2020/05/09 19:12:33 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_find_length(const char *str, int i, int dot, t_printf *flags)
{
	long int	res;

	res = 0;
	while (str[i] != '\0' && str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (dot == 0)
		flags->width = res;
	if (dot == 1)
		flags->prec = res;
	if (i > 0)
		i = i - 1;
	return (i);
}
