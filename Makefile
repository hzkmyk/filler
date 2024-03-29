# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 18:50:01 by hmiyake           #+#    #+#              #
#    Updated: 2019/11/20 00:42:30 by hmiyake          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := hmiyake.filler

CFILES := $(addprefix ./srcs/, main.c \
		 map.c \
		 token.c \
		 place.c \
		 place2.c \
		 queue.c \
		 free.c )

OFILES := $(CFILES:.c=.o)

INCLUDES := -I includes
LIBFT := ./libft/
LDFLAGS := -L $(LIBFT) -lft

CFLAGS := -Wall -Werror -Wextra
# -Wshadow -pedantic -g -std=c11

F := -fsanitize=address

all: $(NAME) 

f:
	gcc $(CFILES) -L libft/ -I libft/ $(F) -lft -g
	
$(NAME): $(OFILES)
	@make -C $(LIBFT)
	@$(CC) -o $@ $^ libft/libft.a $(LDFLAGS)

clean:
	@make -C libft/ clean
	@rm -f $(OFILES)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all