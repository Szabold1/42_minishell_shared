# # Makefile for minishell

# Colour codes
RED = \033[01;31m
YELLOW = \033[01;33m
GREEN = \033[01;32m
RESET = \033[0m

# Executable name
NAME = minishell

# Source directories
SRC_DIR = ./src
OBJ_DIR = ./obj

# Libft
LIBFT_DIR = ./libft
LIBFT = ./libft/libft_full.a

# Headers
INCLUDE_DIR = ./include
HEADERS = $(INCLUDE_DIR)/minishell.h

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include
LFLAGS = -L$(LIBFT_DIR) -lft_full -lreadline

# Remove command
RM = rm -rf

# Source files
SRC = main.c

# Object files
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEPS = $(OBJ:.o=.d)

# Include dependency files
-include $(DEPS)

# Compile individual source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Phony targets
all: $(NAME)

clean:
	@cd $(LIBFT_DIR) && $(MAKE) --quiet clean
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)✔️ clean$(RESET)"

fclean: clean
	@cd $(LIBFT_DIR) && $(MAKE) --quiet fclean
	@$(RM) $(NAME)
	@echo "$(RED)✔️ fclean$(RESET)"

re: fclean all

# Target rules
$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LFLAGS)
	@echo "$(GREEN)✔️ $(NAME) created$(RESET)"

# Create object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Library compilation
$(LIBFT): $(LIBFT_DIR)
	@echo "$(YELLOW)compiling libft...$(RESET)"
	@cd $(LIBFT_DIR) && $(MAKE) --quiet full

.PHONY: all clean fclean re