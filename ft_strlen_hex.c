/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen_hex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/20 14:58:43 by salbregh      #+#    #+#                 */
/*   Updated: 2020/06/03 17:54:13 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_strlen_hex(unsigned long n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}
