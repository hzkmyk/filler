/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 22:03:15 by hmiyake           #+#    #+#             */
/*   Updated: 2019/11/20 00:40:13 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		validate(t_filler *filler, int y, int x)
{
	t_coor	t;
	int		once;

	t.y = filler->t_height;
	t.x = filler->t_width;
	once = 0;
	if ((x + t.x > filler->width) || (y + t.y > filler->height))
		return (0);
	while (t.y--)
	{
		t.x = filler->t_width;
		while (t.x--)
		{
			if (filler->token[t.y][t.x] == '*')
			{
				if (ft_tolower(filler->map[y + t.y][x + t.x]) == filler->enermy)
					return (0);
				if (ft_tolower(filler->map[y + t.y][x + t.x]) == filler->player)
					once++;
			}
		}
	}
	if (once != 1)
		return (0);
	return (1);
}

void	print_piece(int y, int x)
{
	char	*yy;
	char	*xx;

	yy = ft_itoa(y);
	xx = ft_itoa(x);
	write(1, yy, ft_strlen(yy));
	write(1, " ", 1);
	write(1, xx, ft_strlen(xx));
	write(1, "\n", 1);
	free(xx);
	free(yy);
}

int		update_best(t_filler *filler, t_coor coor, t_coor *best_coor, int low)
{
	int	total;
	int	t_y;
	int	t_x;

	total = 0;
	t_y = 0;
	while (t_y < filler->t_height)
	{
		t_x = 0;
		while (t_x < filler->t_width)
		{
			if (filler->token[t_y][t_x] == '*' &&
			filler->token[t_y][t_x] != filler->player)
				total += filler->map[coor.y + t_y][coor.x + t_x];
			t_x++;
		}
		t_y++;
	}
	if (low > total)
	{
		low = total;
		*best_coor = (t_coor){coor.y, coor.x};
	}
	return (low);
}

void	best_coor(t_filler *filler)
{
	t_coor	coor;
	t_coor	best_coor;
	int		lowest;

	coor.y = 0;
	best_coor = (t_coor){0, 0};
	lowest = 2147483647;
	while (coor.y < filler->height)
	{
		coor.x = 0;
		while (coor.x < filler->width)
		{
			if (validate(filler, coor.y, coor.x))
				lowest = update_best(filler, coor, &best_coor, lowest);
			coor.x++;
		}
		coor.y++;
	}
	print_piece(best_coor.y, best_coor.x);
}

void	place(t_filler *filler)
{
	t_queue	*queue_a;
	t_queue	*queue_b;

	queue_a = q_init();
	queue_b = q_init();
	visited_map(filler);
	save_tar_coor(filler, queue_a);
	heat_map(filler, queue_a, queue_b, 1);
	free(queue_a);
	free(queue_b);
	best_coor(filler);
}
