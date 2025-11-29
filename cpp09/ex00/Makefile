NAME     = btc
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP -I include

SRCS     = main.cpp srcs/BitcoinExchange.cpp
OBJS     = $(SRCS:.cpp=.o)
DEPS     = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# 👇 AVANT .PHONY et APRÈS les règles !
-include $(DEPS)

.PHONY: all clean fclean re
