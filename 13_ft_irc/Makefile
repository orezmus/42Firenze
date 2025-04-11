NAME = ircserv
CC = c++
INC = includes
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INC)
	
SRCS_LIST = main.cpp\
	Server.cpp \
	Channel.cpp \
	Client.cpp \
	Command.cpp \
	Command2.cpp \
	Utility.cpp \

OBJS_DIR = objs
SRCS_DIR = srcs

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_LIST))
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS_LIST:.cpp=.o))

GREEN = \033[1;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[m

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.cpp
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)Compiling$(RESET) $<... $(GREEN)Done$(RESET)"
	
all: $(NAME)

$(NAME):$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME)... $(GREEN)Ready$(RESET)"


clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)Removing$(RESET) object files... $(GREEN)Done$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Removing$(RESET) $(NAME)... $(GREEN)Done$(RESET)"

re: fclean all	 

.PHONY: all clean fclean re

.SILENT: $(OBJS)