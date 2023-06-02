SRCS = main.cpp

NAME = easyfind

OSRCS = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Werror -Wextra -std=c++98

CC = c++

all : $(NAME)

$(NAME) : $(OSRCS)
	$(CC) $(CFLAGS) $(OSRCS) -o $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OSRCS)

fclean : clean
	rm -rf $(NAME)

re : fclean all