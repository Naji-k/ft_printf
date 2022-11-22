# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nakanoun <nakanoun@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/08 14:47:14 by nakanoun      #+#    #+#                  #
#    Updated: 2022/11/08 14:47:14 by nakanoun      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

AR = ar
CC = cc

FLAGS = -Wall -Wextra -Werror

MAKE = make

SRC = ft_printf.c \
	ft_itoa_base.c \
	ft_printf_utilities.c \
	ft_printf_int.c \
	libft/ft_strlen.c \
	libft/ft_putchar_fd.c\
	libft/ft_putstr_fd.c \


OBJS = ${SRC:.c=.o}


all: ${NAME}

${NAME}:	${OBJS}
	cd libft && $(MAKE)
	${AR} -crs ${NAME} ${OBJS}

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS);
	cd libft && $(MAKE) clean

fclean:	clean
	rm -f $(NAME) a.out
	cd libft && $(MAKE) fclean


re: fclean all
