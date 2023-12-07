NAME := account
SHELL := /bin/bash
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
INC_DIRS := .

vpath %.hpp $(INC_DIRS)

################################################################################
###############                  SOURCE FILES                     ##############
################################################################################

SRCS := Account.cpp tests.cpp

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.cpp=%.o))

################################################################################
########                         COMPILING                      ################
################################################################################

CFLAGS ?= -Wextra -Wall -Werror -std=c++98 -MMD -MP $(addprefix -I, $(INC_DIRS))

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

re: fclean all

-include $(OBJS:%.o=%.d)

.PHONY: all fclean clean re testing

testing:
	@./account > recovered_details.log
	@diff <(cut -d']' -f2 19920104_091532.log) <(cut -d']' -f2 recovered_details.log); \
	if [ $$? -eq 0 ]; then \
	    echo "The bank details are equivalent (despite the date and time)"; \
	    exit 0; \
	else \
	    echo "The bank details are not equivalent"; \
	    exit 1; \
	fi
