CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp srcs/Bureaucrat.cpp srcs/Format.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = format

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
