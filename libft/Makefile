# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-bouz <yel-bouz@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 12:17:46 by yel-bouz          #+#    #+#              #
#    Updated: 2025/07/25 10:30:40 by yel-bouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
COMPILER = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c \
      ft_isascii.c ft_isprint.c ft_toupper.c \
      ft_tolower.c ft_strlen.c ft_strchr.c \
      ft_strrchr.c ft_strlcpy.c ft_strlcat.c \
      ft_strncmp.c ft_strnstr.c ft_memset.c \
      ft_bzero.c ft_memcpy.c ft_memmove.c \
      ft_memchr.c ft_memcmp.c ft_atoi.c \
      ft_calloc.c ft_strdup.c ft_substr.c \
      ft_strjoin.c ft_strtrim.c ft_split.c \
      ft_itoa.c ft_strmapi.c ft_striteri.c \
      ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
      ft_putnbr_fd.c


OBJ = $(SRC:.c=.o)

OB = ${BONUS:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${AR} $@ ${OBJ}

%.o: %.c
	@${COMPILER} ${CFLAGS} -c $< -o $@

bonus: ${OB}
	${AR} ${NAME} ${OB}

clean:
	@rm -f ${OBJ} ${OB}

fclean: clean
	rm -f ${NAME} 

re: fclean all

.PHONY: all bonus clean fclean re
.SECONDARY: $(OBJ)
