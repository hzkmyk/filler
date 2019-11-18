/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 22:03:15 by hmiyake           #+#    #+#             */
/*   Updated: 2019/11/18 00:45:22 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
FILE	*f;

void	visited_map(t_filler *filler)
{
	int	i;

	i = 0;
	filler->visited = (char **)malloc(sizeof(char *) * filler->height);
	while (i < filler->height)
	{
		filler->visited[i] = (char *)malloc(sizeof(char) * filler->width);
		ft_bzero(filler->visited[i], filler->width);
		i++;
	}
}

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

void printMap(char **map, int height, int width, int heat)
{
	fprintf(f, "----:   on heat: %d\n", heat);
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
	printMap(filler->map, filler->height, filler->width, heat);
	fprintf(f, "----Visited\n");
	printMap(filler->visited, filler->height, filler->width, heat);

	if (is_empty(b))
		return ;
	heat_map(filler, b, a, heat + 1);		
}

int		validate(t_filler *filler, int y, int x)
{
	int	i;
	int	j;
	int	once;

	i = y;
	j = x;
	once = 0;
	if ((j + filler->t_width > filler->width) || (i + filler->height > filler->height))
		return (0);
	while (y < filler->t_height + i)
	{
		j = x;
		while (x < filler->t_width + j)
		{
			if (filler->map[i][j] == 0)
				return (0);
			else if (filler->map[i][j] == filler->player)
			{
				once++;
				if (once > 1)
					return (0);
			}
			x++;
		}
		y++;
	}
	if (once != 1)
		return (0);
	return (1);
}

void	whatsthebest(t_filler *filler)
{
	int	lowest;
	int	y;
	int	x;
	int	yy;
	int	xx;

	lowest = 2147483647;
	y = 0;
	yy = 0;
	while (y < filler->height)
	{
		x = 0;
		while (x < filler->width)
		{
			if (validate(filler, y, x))
			{
				while (yy < filler->t_height)
				{
					xx = 0;
					while (xx < filler->t_width)
					{
						
					}
				}
			}
		}
	}
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
	
}
