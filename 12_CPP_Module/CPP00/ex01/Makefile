NAME = phonebook
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp\
	Phonebook.cpp\
	Contact.cpp

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

$(OBJS_DIR)/%.o : %.cpp
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all	  

.PHONY: all clean fclean re

.SILENT: $(OBJS)
