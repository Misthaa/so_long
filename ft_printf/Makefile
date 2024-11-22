# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 15:56:19 by madegryc          #+#    #+#              #
#    Updated: 2024/01/15 13:25:33 by madegryc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS        =	ft_printf.c\
				ft_printf_utils.c\
				ft_hexa_utils.c\

NAME        =    libftprintf.a

OBJS        =    ${SRCS:.c=.o}

CC            =    cc

CFLAGS        =    -Wall -Werror -Wextra

all : ${NAME}

${NAME} : ${OBJS}
	@${CC} ${CFLAGS} ${SRCS} -c
	@ar rc ${NAME} ${OBJS}

clean :
	@rm -f ${OBJS}

fclean : clean
	@rm -f ${NAME}

re    : fclean all

.PHONY : re fclean all clean
