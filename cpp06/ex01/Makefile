NAME    = serialize
CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98 -Iinclude

SRC_DIR = srcs
OBJ_DIR = objs

ROOT_FILES = main.cpp
SRC_FILES  = Serializer.cpp Data.cpp

SRCS = $(ROOT_FILES) $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(ROOT_FILES:.cpp=.o)) \
       $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

all: $(NAME)
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR): ; @mkdir -p $(OBJ_DIR)
clean: ; @rm -rf $(OBJ_DIR)
fclean: clean ; @rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
	