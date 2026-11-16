# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-bouz <yel-bouz@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 10:17:49 by yel-bouz          #+#    #+#              #
#    Updated: 2025/07/25 14:41:52 by yel-bouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= game
LIBFT			= libft.a
mlx				= libmlx.a

CC				= cc
CFLAGS  = -Wall -Wextra -Werror
N_FLAGS = -g
O_FLAGS = -lXext -lX11 -lm

INC				= libft.h main.h
ALL_SRC			= $(wildcard *.c)
SRC				= $(filter-out test%.c, $(ALL_SRC))
OBJ				= $(SRC:.c=.o)

RM				= rm -f

all: normal

normal: CFLAGS = $(N_FLAGS)
normal: $(LIBFT) $(NAME)

strict: CFLAGS = -Wall -Wextra -Werror
strict: $(LIBFT) $(NAME)

.o: .c $(INC) $(LIBFT)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ)  
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(mlx) $(O_FLAGS) -o $(NAME)

$(LIBFT):
	@echo "Building libft"
	@$(MAKE) -C libft
	@echo "Copying libft.a to root directory"
	@mv libft/$(LIBFT) .

clean:
	@echo "Cleaning minishell objects"
	@$(RM) $(OBJ)
	@echo "Cleaning libft objects"
	@$(MAKE) -C libft clean

fclean: clean
	@echo "Cleaning minishell"
	@$(RM) $(NAME)
	@echo "Cleaning libft"
	@$(MAKE) -C libft fclean
	@$(RM) $(LIBFT)

re : fclean all

bonus: all

.PHONY: all clean fclean re bonus
.SECONDARY: $(OBJ)