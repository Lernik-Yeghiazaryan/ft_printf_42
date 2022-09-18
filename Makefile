# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leyeghia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 18:49:12 by leyeghia          #+#    #+#              #
#    Updated: 2022/04/28 14:56:38 by leyeghia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS 	= $(shell find "." -name "*.c")

OBJS	= ${SRCS:.c=.o}

CC		= cc -o
AR		= ar rcs
RM		= rm -f
FLAGS	= -Wall -Wextra -Werror

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all: 	$(NAME)

${NAME}:	${OBJS}
		${AR} ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
