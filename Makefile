# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/21 12:09:38 by cwannhed          #+#    #+#              #
#    Updated: 2026/02/21 17:59:05 by cwannhed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_shmup

CC = c++

SRC = main.cpp \
	Game.cpp \
	GameEntity.cpp \
	Player.cpp \
	Enemy.cpp \
	Bullet.cpp

CXXFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -lncurses

all: $(NAME)

$(NAME): $(SRC)
	@echo "$(BLUE)Compiling $(NAME)...$(RESET)"
	$(CC) $(SRC) $(CXXFLAGS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"
	@echo "$(CYAN)Run with: ./$(NAME)$(RESET)"

clean:
	@echo "$(BLUE)Cleaning up...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)Cleanup complete!$(RESET)"

fclean: clean

re: fclean all

.PHONY: all clean fclean re

# Colors
RESET = \033[0m
BLUE = \033[34m
GREEN = \033[32m
CYAN = \033[36m