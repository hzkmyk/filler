# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 18:50:01 by hmiyake           #+#    #+#              #
#    Updated: 2019/11/15 22:18:47 by hmiyake          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hmiyake.filler

CFILES = main.c \
		 map.c \
		 token.c \
		 place.c

OFILES = $(CFILES:.c=.o)

INCLUDES = -I includes

LIBFT = libft -lft

FLG = -Wall -Werror -Wextra

F = -fsanitize=address


all:
	cd srcs;gcc $(FLG) $(CFILES) $(INCLUDES) -L ../$(LIBFT) -o ../$(NAME) $(INCLUDES)
$(NAME):
	@make -C $(LIBFT)
	@cd srcs;gcc $(FLG) $(CFILES) $(INCLUDES) -L ../$(LIBFT) -o ../$(NAME) $(INCLUDES)


clean:
	@make -C libft/ clean
	@cd srcs;rm -f $(OFILES)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all