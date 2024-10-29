# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 16:32:03 by yrio              #+#    #+#              #
#    Updated: 2024/01/11 09:39:34 by yrio             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror
SRC = main.c compute_utils.c compute_utils2.c \
	ft_printf_utils.c ft_printf.c int_utils.c lst_utils.c \
	lst_utils2.c lst_utils3.c push_utils.c rotate_utils.c \
	rrotate_utils.c sort_utils.c sort_utils2.c sort_utils3.c \
	str_utils.c swap_utils.c
SRC_LIBFT = ft_split.c
SRCS = $(SRC) $(SRC_LIBFT)

OBJ = $(SRC:.c=.o)
OBJ_LIBFT = $(SRC_LIBFT:.c=.o)
OBJS = $(OBJ) $(OBJ_LIBFT)

all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) -o $(NAME) $(OBJS) -lm
	
$(OBJ): $(SRC)
	cc $(FLAGS) -c $(SRC)

$(OBJ_LIBFT): libft/$(SRC_LIBFT)
	cc $(FLAGS) -c libft/$(SRC_LIBFT)

clean:
	rm -f prog *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus