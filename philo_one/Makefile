# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/06 13:14:41 by cdrennan          #+#    #+#              #
#    Updated: 2021/03/08 18:44:49 by cdrennan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo_one

CC		= clang

CFLAGS	= -Wall -Wextra -Werror $(INC)

INC		= -Iincludes/

OBJS	= $(SRCS:%.c=%.o)


SRCS	= philo_one.c init.c utils.c threads.c live_as_philo.c printer.c

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


all: $(NAME) clean

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: args clean fclean re