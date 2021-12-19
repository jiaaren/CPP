SRCS    =	Base.cpp	main.cpp
NAME    =	base
OBJS    =   $(SRCS:.cpp=.o)
FLAGS   =   -Wall -Wextra -Werror -std=c++98 -pedantic-errors

all:    $(NAME)

$(OBJS) :	$(SRCS)
			c++ $(FLAGS) $(SRCS) -c

$(NAME) :	$(OBJS)
			c++ $(FLAGS) $^ -o $(NAME)

clean   :
			rm -rf $(OBJS)

fclean  :   clean
			rm -rf $(NAME)

re		:	fclean all
