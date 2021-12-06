# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 23:19:54 by jkhong            #+#    #+#              #
#    Updated: 2021/12/06 23:24:08 by jkhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	Karen.cpp	main.cpp 
NAME 	= 	karen
OBJS	=	$(SRCS:.cpp=.o)
FLAGS	=	-Wall -Wextra -Werror -Wimplicit-fallthrough=0 -std=c++98 -pedantic-errors

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
