NAME := megaphone
.DEFAULT_GOAL := all
CC := c++

################################################################################
###############                 PRINT OPTIONS                     ##############
################################################################################

M := \033[35m
G := \033[32m
X := \033[0m
BO := $(shell tput bold)
LOG := printf "[$(BO)$(G)ⓘ INFO$(X)] %s\n"
WARN := printf "[$(BO)$(M)ⓘ WARN$(X)] %s\n"

################################################################################
###############                  DIRECTORIES                      ##############
################################################################################

OBJ_DIR := _obj

################################################################################
###############                  SOURCE FILES                     ##############
################################################################################

SRCS := megaphone.cpp

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.cpp=%.o))

################################################################################
########                         COMPILING                      ################
################################################################################

CFLAGS ?= -Wextra -Wall -Werror -std=c++98 -MMD -MP

all: $(NAME)

$(NAME): $(OBJS)
	@$(LOG) "Linking object files to $@"
	@$(CC) $^ $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(LOG) "Compiling $(notdir $@)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@$(LOG) "Creating object directory."
	@mkdir -p $@

debug: CFLAGS += -g
debug: fclean all

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(WARN) "Cleaning $(notdir $(OBJ_DIR))"; \
		rm -rf $(OBJ_DIR); \
	else \
		$(LOG) "No objects to clean."; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		$(WARN) "Cleaning $(notdir $(NAME))"; \
		rm -f $(NAME); \
	else \
		$(LOG) "No library to clean."; \
	fi

testing: all
	@$(LOG) "Execute tests from the subject."
	@$(LOG) "First test: shhhhh... I think the students are asleep..."
	@./$(NAME) "shhhhh... I think the students are asleep..."
	@$(LOG) "Second test: Damnit \" ! \" \"Sorry students, I thought this thing was off.\""
	@./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	@$(LOG) "Third test: "
	@./$(NAME)

re: fclean all

-include $(OBJS:%.o=%.d)

.PHONY: all fclean clean re testing
