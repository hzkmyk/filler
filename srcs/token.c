/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:32:14 by hmiyake           #+#    #+#             */
/*   Updated: 2019/11/19 23:19:08 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	token_size(t_filler *filler)
{
	char	*input;
	char	**token_size;

	input = gnl(0);
	token_size = ft_strsplit(input, ' ', ':');
	filler->origin_t_height = ft_atoi(token_size[1]);
	filler->t_width = ft_atoi(token_size[2]);
	ft_free(token_size);
}

void	init_token(t_filler *filler)
{
	int		i;
	char	*temp;

	i = 0;
	filler->token = (char **)malloc(sizeof(char *) * filler->origin_t_height);
	while (i < filler->origin_t_height)
	{
		temp = gnl(0);
		filler->token[i] = ft_strdup(temp);
		i++;
	}
}

void	trim_token(t_filler *filler)
{
	int		y;
	int		x;
	t_coor	biggest_p;

	y = 0;
	biggest_p.y = 0;
	biggest_p.x = 0;
	while (y < filler->origin_t_height)
	{
		x = 0;
		while (x < filler->t_width)
		{
			if (filler->token[y][x] == '*')
			{
				if (y > biggest_p.y)
					biggest_p.y = y;
				if (x > biggest_p.x)
					biggest_p.x = x;
			}
			x++;
		}
		y++;
	}
	filler->t_height = biggest_p.y + 1;
	filler->t_width = biggest_p.x + 1;
}

void	save_token(t_filler *filler)
{
	token_size(filler);
	init_token(filler);
	trim_token(filler);
}
