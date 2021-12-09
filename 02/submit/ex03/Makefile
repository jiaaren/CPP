# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 01:29:21 by jkhong            #+#    #+#              #
#    Updated: 2021/12/09 16:54:07 by jkhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	Fixed.cpp	Point.cpp	bsp.cpp		main.cpp
NAME 	= 	bsp
OBJS	=	$(SRCS:.cpp=.o)
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors

all:	$(NAME)

$(OBJS)	:	$(SRCS)
			c++ $(FLAGS) $(SRCS) -c

$(NAME)	:	$(OBJS)
			c++ $(FLAGS) $^ -o $(NAME)

clean	:
			rm -rf $(OBJS)
		
fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

.PHONY = clean fclean re