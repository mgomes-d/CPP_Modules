# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 08:55:23 by mgomes-d          #+#    #+#              #
#    Updated: 2023/05/10 09:14:01 by mgomes-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brainz

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f

SRCS_DIR = srcs
OBJS_DIR = objs
INC_DIR = include

SRCS = Zombie.cpp \
       main.cpp \
	   newZombie.cpp \
	   randomChump.cpp

OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:%.cpp=%.o})

all: ${NAME}

${OBJS_DIR}/%.o: ${SRCS_SIR}/%.c | ${OBJS_DIR}
	@mkdir -p ${@D}
	${CC} ${FLAGS} -I ${INC_DIR} -c $< -o $@


${NAME}: ${OBJS}
	${CC} ${FLAGS} -o $@ $^

clean:
	${}