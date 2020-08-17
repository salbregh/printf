/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 15:35:53 by salbregh      #+#    #+#                 */
/*   Updated: 2020/05/10 10:45:40 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putstr(const char *str, t_printf *flags, int check)
{
	int	i;
	int len;

	len = ft_strlen(str);
	if (check == 1)
		i = 2;
	if (check == 2)
		i = 3;
	else if (flags->prec < len && flags->dot != 0 && flags->prec != 0)
		i = flags->prec;
	else
		i = ft_strlen(str);
	while (*str && i > 0)
	{
		write(1, &*str, 1);
		str++;
		i--;
		flags->rv++;
	}
}
