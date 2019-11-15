# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 18:50:01 by hmiyake           #+#    #+#              #
#    Updated: 2019/11/14 23:24:09 by hmiyake          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hmiyake.filler

CFILES = main.c \
		 map.c \
		 token.c

OFILES = $(CFILES:.c=.o)

INCLUDES = -I includes

LIBFT = libft -lft

FLG = -Wall -Werror -Wextra -c

all:$(NAME)

$(NAME):
	@make -C $(LIBFT)
	@cd srcs;gcc $(FLG) $(CFILES) $(INCLUDES)
	@cd srcs;gcc $(OFILES) -L ../$(LIBFT) -o ../$(NAME) $(INCLUDES)

clean:
	@make -C libft/ clean
	@cd srcs;rm -f $(OFILES)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all