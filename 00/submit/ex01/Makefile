# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 20:39:21 by jkhong            #+#    #+#              #
#    Updated: 2021/11/30 20:39:28 by jkhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	PhoneBook.cpp	Contact.cpp		main.cpp
NAME 	= 	crappy_phonebook
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