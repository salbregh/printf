# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: salbregh <salbregh@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/04/10 15:37:53 by salbregh      #+#    #+#                  #
#    Updated: 2020/06/03 09:09:45 by salbregh      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf

SRCS		=	ft_printf.c\
				ft_putchar.c\
				ft_putstr.c\
				ft_after_per.c\
				ft_convert_s.c\
				ft_convert_per.c\
				ft_putnbr.c\
				ft_convert_d_i.c\
				ft_convert_c.c\
				ft_flags.c\
				ft_free_flags.c\
				ft_find_length.c\
				ft_padding.c\
				ft_strlen.c\
				ft_convert_hex.c\
				ft_puthex.c\
				ft_convert_p.c\
				ft_convert_u.c\
				ft_strlen_hex.c

CFILES		=	$(SRCS)

OFILES		=	$(CFILES:.c=.o)

FLAGS		=	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OFILES)
		@ar rc $(NAME).a $(OFILES)
		@echo "Printf libary is compiled"

%.o:		%.c
		@echo "Compiling $^ ..."
		@gcc -o $@ $(FLAGS) -c $^

clean:
		@echo "Cleaning all .o files..."
		@rm -f $(OFILES)

fclean:		clean
		@echo "Cleaning all .o files and .a file..."
		@rm -f $(NAME).a

re:			fclean all
