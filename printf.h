/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 15:38:44 by salbregh      #+#    #+#                 */
/*   Updated: 2020/06/03 10:58:38 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_printf
{
	int			flag;
	int			width;
	int			prec;
	int			dot;
	int			rv;
}				t_printf;

int				ft_printf(const char *str, ...);
void			ft_putchar(char c, t_printf *flags);
void			ft_putstr(const char *str, t_printf *flags, int check);
int				ft_after_per(const char *str,
				int i, t_printf *flags, va_list argptr);
void			ft_convert_s(char *s, t_printf *flags);
void			ft_convert_per(t_printf *flags);
void			ft_putnbr(long n, t_printf *flags, int len);
void			ft_convert_d_i(long n, t_printf *flags);
void			ft_convert_c(int c, t_printf *flags);
int				ft_flags(const char *str, int i, t_printf *flags,
				va_list argptr);
void			ft_free_flags(t_printf *flags, int i);
int				ft_find_length(const char *str, int i, int dot,
				t_printf *flags);
void			ft_put_padding(t_printf *flags, char c, int i);
int				ft_strlen(const char *str);
void			ft_convert_hex(unsigned int i, int caps, t_printf *flags);
void			ft_puthex(unsigned int i, int caps, t_printf *flags, int len);
void			ft_convert_p(unsigned long i, t_printf *flags);
void			ft_convert_u(unsigned int n, t_printf *flags);
int				ft_strlen_hex(unsigned long n);
void			ft_first_padding(long n, t_printf *flags, int len, int check);
void			ft_last_padding(long n, t_printf *flags, int len);

#endif
