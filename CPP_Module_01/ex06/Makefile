NAME := harlFilter
.DEFAULT_GOAL := all
CC := c++

################################################################################
###############                 PRINT OPTIONS                     ##############
################################################################################

G := \033[32m
X := \033[0m
BO := $(shell tput bold)
LOG := printf "[$(BO)$(G)ⓘ INFO$(X)] %s\n"

################################################################################
###############                  DIRECTORIES                      ##############
################################################################################

OBJ_DIR := _obj
INC_DIRS := .
SRC_DIRS := .

# Tell the Makefile where headers and source files are
vpath %.hpp $(INC_DIRS)
vpath %.cpp $(SRC_DIRS)

################################################################################
###############                  SOURCE FILES                     ##############
################################################################################

SRCS := Harl.cpp main.cpp

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.cpp=%.o))

################################################################################
########                         COMPILING                      ################
################################################################################

CFLAGS ?= -Wextra -Wall -Werror -std=c++98 -MMD -MP $(addprefix -I, $(INC_DIRS)) -g
LDFLAGS := 

all: $(NAME)

$(NAME): $(OBJS) | $(LIBFT)
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
		$(LOG) "Cleaning $(notdir $(OBJ_DIR))"; \
		rm -rf $(OBJ_DIR); \
	else \
		$(LOG) "No objects to clean."; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		$(LOG) "Cleaning $(notdir $(NAME))"; \
		rm -f $(NAME); \
	else \
		$(LOG) "No library to clean."; \
	fi

test:
	@echo
	@$(LOG) "Testing a single line document";
	@./ex04 tests/single_line single "something else"
	@diff tests/single_line tests/single_line.replace || true
	@echo
	@$(LOG) "Testing a double line document";
	@./ex04 tests/double_line as et
	@diff tests/double_line tests/double_line.replace || true
	@echo
	@$(LOG) "Testing a double line document";
	@./ex04 tests/empty_lines "I'm" You
	@diff tests/empty_lines tests/empty_lines.replace || true

re: fclean all

-include $(OBJS:%.o=%.d)

.PHONY: all fclean clean re test
