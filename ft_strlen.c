/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 15:36:18 by salbregh      #+#    #+#                 */
/*   Updated: 2020/04/10 15:36:19 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
