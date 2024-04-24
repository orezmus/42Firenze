NAME = fixed
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp\
	Fixed.cpp

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[m

$(OBJS_DIR)/%.o : %.cpp
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME): object files created$(RESET)"
	@echo "$(GREEN)$(NAME): $(NAME) compiled$(RESET)"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)$(NAME): object files deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME): $(NAME) deleted$(RESET)"

re: fclean all	 

.PHONY: all clean fclean re

.SILENT: $(OBJS)
