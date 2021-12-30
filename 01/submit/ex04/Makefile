# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 22:40:59 by jkhong            #+#    #+#              #
#    Updated: 2021/12/06 22:41:12 by jkhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.cpp 
NAME 	= 	better_sed
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