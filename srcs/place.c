/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 22:03:15 by hmiyake           #+#    #+#             */
/*   Updated: 2019/11/18 23:36:06 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
FILE	*f;

void	save_tar_coor(t_filler *filler, t_queue *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < filler->height)
	{
		j = 0;
		while (j < filler->width)
		{
			if (ft_tolower(filler->map[i][j]) == filler->enermy)
			{
				enqueue(a, i, j);
				filler->visited[i][j] = 1;
			}
			j++;
		}
		i++;
	}
}

int		canheat_beplaced(t_filler *filler, t_coor coor)
{
	if (coor.x < 0 || coor.x >= filler->width)
		return (0);
	if (coor.y < 0 || coor.y >= filler->height)
		return (0);
	if (filler->map[coor.y][coor.x] != '.' || filler->visited[coor.y][coor.x])
		return (0);
	return (1);
}

void	set_heat(t_filler *filler, t_coor coor, int heat, t_queue *queue)
{
	if (canheat_beplaced(filler, (t_coor){coor.y, coor.x}))
	{
		filler->map[coor.y][coor.x] = heat;
		enqueue(queue, coor.y, coor.x);
		filler->visited[coor.y][coor.x] = 1;
	}
}

void	place_heat(t_filler *filler, char heat, t_coor coor, t_queue *queue)
{
	set_heat(filler, (t_coor){coor.y, coor.x - 1}, heat, queue);
	set_heat(filler, (t_coor){coor.y, coor.x + 1}, heat, queue);
	set_heat(filler, (t_coor){coor.y - 1, coor.x}, heat, queue);
	set_heat(filler, (t_coor){coor.y - 1, coor.x - 1}, heat, queue);
	set_heat(filler, (t_coor){coor.y - 1, coor.x + 1}, heat, queue);
	set_heat(filler, (t_coor){coor.y + 1, coor.x}, heat, queue);
	set_heat(filler, (t_coor){coor.y + 1, coor.x - 1}, heat, queue);
	set_heat(filler, (t_coor){coor.y + 1, coor.x + 1}, heat, queue);
}

void printMap(char **map, int height, int width)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			fprintf(f, "%2d ", map[i][j]);
		fprintf(f, "\n");
	}
}

void	heat_map(t_filler *filler, t_queue *a, t_queue *b, char heat)
{
	t_coor	coor;

	
	while (!is_empty(a))
	{
		coor = dequeue(a);
		place_heat(filler, heat, coor, b); 
	}
	if (is_empty(b))
		return ;
	heat_map(filler, b, a, heat + 1);		
}

int		validate(t_filler *filler, int y, int x)
{
	int	i;
	int	j;
	int	once;

	i = filler->t_height;
	j = filler->t_width;
	once = 0;
	if ((x + j > filler->width) || (y + i > filler->height))
		return (0);
	while (i--)
	{
		j = filler->t_width;
		while (j--)
		{
			if (filler->token[i][j] == '*')
			{
				if (ft_tolower(filler->map[y + i][x + j]) == filler->enermy)
					return (0);
				if (ft_tolower(filler->map[y + i][x + j]) == filler->player)
					once++;
			}
		}
	}
	if (once != 1)
		return (0);
	return (1);
}

void	whatsthebest(t_filler *filler)
{
	int		lowest[2];
	t_coor	coor;
	t_coor	best_coor;
	int		yy;
	int		xx;

	lowest[0] = 2147483647;
	coor.y = 0;
	yy = 0;
	best_coor = (t_coor){0, 0};
	while (coor.y < filler->height)
	{
		coor.x = 0;
		while (coor.x < filler->width)
		{
			if (validate(filler, coor.y, coor.x))
			{
				lowest[1] = 0;
				while (yy < filler->t_height)
				{
					xx = 0;
					while (xx < filler->t_width)
					{
						if (filler->token[yy][xx] == '*')
							lowest[1] += filler->map[coor.y + yy][coor.x + xx];
						xx++;
					}
					yy++;
				}
				if (lowest[0] > lowest[1])
				{
					lowest[0] = lowest[1];
					best_coor = (t_coor){coor.y, coor.x};
				}
			}
			coor.x++;
		}
		coor.y++;
	}
	fprintf(f, "best y:%d best x:%d\n", best_coor.y, best_coor.x);
	write (1, ft_itoa(best_coor.y), ft_strlen(ft_itoa(best_coor.y)));
	write(1, " ", 1);
	write (1, ft_itoa(best_coor.x), ft_strlen(ft_itoa(best_coor.x)));
	write (1, "\n", 1);
	// printf("%d %d\n", best_coor.y, best_coor.x);
}

void	place(t_filler *filler)
{
	t_queue	*queue_a;
	t_queue	*queue_b;

	f = fopen("test", "w");
	queue_a = q_init();
	queue_b = q_init();
	visited_map(filler);
	save_tar_coor(filler, queue_a);
	heat_map(filler, queue_a, queue_b, 1);
	free(queue_a);
	free(queue_b);
	whatsthebest(filler);
}
