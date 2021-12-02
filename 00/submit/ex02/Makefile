# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 20:43:03 by jkhong            #+#    #+#              #
#    Updated: 2021/11/30 20:43:50 by jkhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	Account.cpp		tests.cpp
NAME 	= 	tests
OBJS	=	$(SRCS:.cpp=.o)
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors

all:	$(NAME)

$(NAME)	:	$(OBJS)
			c++ $(FLAGS) $^ -o $(NAME)

$(OBJS)	:	$(SRCS)
			c++ $(FLAGS) $(SRCS) -c

clean	:
			rm -rf $(OBJS)
		
fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

.PHONY = clean fclean re