# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 09:52:22 by mgomes-d          #+#    #+#              #
#    Updated: 2023/07/18 10:26:35 by mgomes-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

INC_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS = main.cpp BitcoinExchange.cpp
OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:%.cpp=%.o})

all: ${NAME}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.cpp
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -I ${INC_DIR} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re