NAME = megaphone

CPP = g++

CPPFLAGS = -Wall -Wextra -std=c++11

SRCS = 	main.cpp \
		PhoneBook.cpp \
		Contact.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $^

%.o: %.cpp 
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
