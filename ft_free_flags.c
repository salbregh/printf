/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_flags.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 15:34:43 by salbregh      #+#    #+#                 */
/*   Updated: 2020/05/09 17:16:34 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_free_flags(t_printf *flags, int i)
{
	flags->prec = 0;
	flags->width = 0;
	flags->dot = 0;
	flags->flag = 0;
	if (i == 1)
		flags->rv = 0;
}
