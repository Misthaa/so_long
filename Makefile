# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 15:56:19 by madegryc          #+#    #+#              #
#    Updated: 2024/01/18 14:11:30 by madegryc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS        =	srcs/so_long.c\
                srcs/ft_file.c\
                srcs/ft_map.c\
				srcs/keymoves.c\
				srcs/sprite_animation.c\
				srcs/ft_move.c\
				srcs/ft_move2.c\
				srcs/ft_display_map.c\
				srcs/ft_display_other.c\
				srcs/ft_parsing.c\
				srcs/ft_move_monster.c\
				srcs/ft_move_monster2.c\
				srcs/ft_close.c\
				srcs/ft_file_img.c\
				srcs/ft_check.c\
				srcs/libft/get_next_line.c\
				srcs/libft/get_next_line_utils.c\
				srcs/libft/ft_split.c\
				srcs/libft/ft_strdup.c\
				srcs/libft/ft_strjoin.c\
				srcs/libft/ft_itoa.c\

MAKE = make -s -C 

NAME        =    so_long

OBJS        =    ${SRCS:.c=.o}

CC            =   @cc 

CFLAGS        =    -Wall -Werror -Wextra -g

GREEN=\033[0;32m
NC=\033[0m

all : ${NAME}

PRINTF = ft_printf/libftprintf.a

${NAME} : ${OBJS}
	@${MAKE} ft_printf --no-print-directory
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${PRINTF} MacroLibX/libmlx.so -lSDL2
	@echo "   ▄███████▄  ▄██████▄   ▄█        ▄██████▄  ███▄▄▄▄      ▄██████▄  "
	@echo "  ███    ███ ███    ███ ███       ███    ███ ███▀▀▀██▄   ███    ███"
	@echo "  ███    █▀  ███    ███ ███       ███    ███ ███   ███   ███    █▀  "
	@echo "  ███        ███    ██                        ██   ███  ▄███        "
	@echo "▀██████████▄ ███    ██  Compilation finished  ██   ███ ▀▀███ ████▄  "
	@echo "         ███ ███    ██                        ██   ███   ███    ███ "
	@echo "   ▄█    ███ ███    ███ ███▌    ▄ ███    ███ ███   ███   ███    ███ "
	@echo " ▄████████▀   ▀██████▀  ▀████▄▄██  ▀██████▀   ▀█   █▀    ▀███████▀  "
	@echo "                         ▀                                          "


%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean :
	@rm -f ${OBJS}
	@echo "$(GREEN)Cleaning in progress...$(NC)"
	@echo "$(GREEN)Cleaning completed successfully.$(NC)"

fclean : clean
	@make -s -C ft_printf fclean
	@rm -f ${NAME}

re    : fclean all

.PHONY : re fclean all clean
