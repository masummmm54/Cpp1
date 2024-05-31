.SILENT:

COLOUR_DEFAULT = \033[0m
COLOUR_BLACK = \033[0;30m
COLOUR_RED = \033[0;31m
COLOUR_GREEN = \033[0;32m
COLOUR_YELLOW = \033[0;33m
COLOUR_BLUE = \033[0;34m
COLOUR_MAGENTA = \033[0;35m
COLOUR_CYAN = \033[0;36m
COLOUR_WHITE = \033[0;37m
COLOUR_BOLD = \033[1m
COLOUR_UNDERLINE = \033[4m
COLOUR_END = \033[0m

CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I./include/

SRC = main.cpp BitcoinExchange.cpp

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

NAME = btc

$(NAME) : $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	echo "$(COLOUR_GREEN)$(NAME) compiled successfully!$(COLOUR_END)"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean:
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	echo "$(COLOUR_CYAN)$(COLOUR_UNDERLINE)$(NAME) cleaned successfully!$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re
