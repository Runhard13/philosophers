# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/06 13:14:41 by cdrennan          #+#    #+#              #
#    Updated: 2021/03/14 18:26:13 by cdrennan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo_three

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror $(INC)

INC		= -Iincludes/

OBJS	= $(SRCS:%.c=%.o)


SRCS	= philo_three.c init.c utils.c threads.c live_as_philo.c printer.c utils2.c

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re