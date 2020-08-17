/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 15:35:30 by salbregh      #+#    #+#                 */
/*   Updated: 2020/04/22 13:51:13 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar(char c, t_printf *flags)
{
	write(1, &c, 1);
	flags->rv++;
}
