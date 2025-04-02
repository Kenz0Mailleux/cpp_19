NAME = weapon
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp srcs/Weapon.cpp srcs/HumanA.cpp srcs/HumanB.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
