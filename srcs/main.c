/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:35:49 by hmiyake           #+#    #+#             */
/*   Updated: 2019/11/16 23:45:34 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

char		*gnl(int fd) {
    static char buf[256];
    int k = 0;
    char c = 0;
    while (read(fd, &c, 1) > 0) {
        if (c == '\n' || k > 255)
            break;
        buf[k++] = c;
    }
    buf[k] = '\0';
    return buf;
}

char		set_player(void)
{
	char	*input;
	char	player;

	input = gnl(0);
	player = ft_strncmp("$$$ exec p1", input, 11) ? 'x': 'o';
	return (player);
}

t_filler	*init(void)
{
	t_filler	*filler;

	filler = (t_filler *)malloc(sizeof(t_filler));
	filler->player = set_player();
	filler->enermy = filler->player == 'o' ? 'x': 'o';
	filler->height = 0;
	filler->width = 0;
	filler->t_height = 0;
	filler->t_width = 0;
	filler->map = NULL;
	filler->token = NULL;
	filler->visited = NULL;
	return (filler);
}

int			main(void)
{
	t_filler	*filler;

	filler = init();
	save_map(filler);
	save_token(filler);
	place(filler);
	return (0);
}
