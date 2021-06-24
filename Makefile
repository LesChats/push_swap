# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaudot <abaudot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 20:43:31 by abaudot           #+#    #+#              #
#    Updated: 2021/06/24 20:43:44 by abaudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME1 = push_swap
NAME2 = checker

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -Iinclude -O2

OBJS_DIR = objs
PRECOMPILE = mkdir -p $(dir $(OBJS_DIR)/$*)


include utils/srcs.mk
include utils/srcs_bonus.mk

OBJS = $(patsubst src/%.c, $(OBJS_DIR)/%.o, $(SRCS))
OBJS_BONUS = $(patsubst src/%.c, $(OBJS_DIR)/%.o, $(SRCS_BONUS))

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
BLUE:="\033[34;1m"
# ==================

OBJ = $(patsubst %.c, %.o, $(SRC))

all : $(NAME1)

$(OBJS_DIR)/%.o: src/%.c $(INCLUDES)
	@$(PRECOMPILE)
	@$(CC) $(CFLAGS) -c -o $@ $<
#	@echo "$(BLUE)Created: $(@:%=%) $(EOC)"

$(NAME1): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

$(NAME2): $(OBJS_BONUS)
	$(CC) -o $@ $^ $(CFLAGS)

bonus: $(NAME1) $(NAME2)

clean:
	@rm -rf $(OBJS_DIR)
fclean: clean
	@rm -f $(NAME1)
	@rm -f $(NAME2)
re: fclean
	make all
