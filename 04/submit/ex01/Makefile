# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 18:45:45 by jkhong            #+#    #+#              #
#    Updated: 2021/12/13 15:20:28 by jkhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	Animal.cpp	Cat.cpp		Dog.cpp		Brain.cpp  main_deepcopy.cpp
NAME 	= 	a.out
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