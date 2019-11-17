/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 22:03:15 by hmiyake           #+#    #+#             */
/*   Updated: 2019/11/17 02:32:08 by hmiyake          ###   ########.fr       */
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

int		all_visited(t_filler *filler)
{
	int	i;
	int	j;

	i = 0;
	while (i < filler->height)
	{
		j = 0;
		while (j < filler->width)
		{
			if (filler->visited[i][j] != 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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


void	place_heat(t_filler *filler, char heat, t_coor coor, t_queue *queue)
{
	int	nothing;
	int i = coor.y;
	int j = coor.x;

	nothing = 0;
	if (i > 0)
	{
		if (j > 0 && filler->map[i - 1][j - 1] == '.' && !filler->visited[i - 1][j - 1])
		{

			filler->map[i - 1][j - 1] = heat;
			enqueue(queue, i - 1, j - 1);
			filler->visited[i - 1][j - 1] = 1;
		}
		if (filler->map[i - 1][j] == '.' && !filler->visited[i - 1][j])
		{

			filler->map[i - 1][j] = heat;
			enqueue(queue, i - 1, j);
			filler->visited[i - 1][j] = 1;
		}
		if (j + 1 < filler->width && filler->map[i - 1][j + 1] == '.' && !filler->visited[i - 1][j + 1])
		{

			filler->map[i - 1][j + 1] = heat;
			enqueue(queue, i - 1, j + 1);
			filler->visited[i - 1][j + 1] = 1;
		}
	}
	if (j > 0 && filler->map[i][j - 1] == '.' && !filler->visited[i][j - 1])
	{
			
		filler->map[i][j - 1] = heat;
		enqueue(queue, i, j - 1);
		filler->visited[i][j - 1] = 1;
	}
	if (j + 1 < filler->width && filler->map[i][j + 1] == '.' && !filler->visited[i][j + 1])
	{
	
		filler->map[i][j + 1] = heat;
		enqueue(queue, i, j + 1);
		filler->visited[i][j + 1] = 1;
	}
	if (i + 1 < filler->height)
	{
		if (j > 0 && filler->map[i + 1][j - 1] == '.' && !filler->visited[i + 1][j - 1])
		{
	
			filler->map[i + 1][j - 1] = heat;
			enqueue(queue, i + 1, j - 1);
			filler->visited[i + 1][j - 1] = 1;
		}
		if (filler->map[i + 1][j] == '.' && !filler->visited[i + 1][j])
		{

			filler->map[i + 1][j] = heat;
			enqueue(queue, i + 1, j);
			filler->visited[i + 1][j] = 1;
		}
		if (j + 1 < filler->width && filler->map[i + 1][j + 1] == '.' && !filler->visited[i + 1][j + 1])
		{

			filler->map[i + 1][j + 1] = heat;
			enqueue(queue, i + 1, j + 1);
			filler->visited[i + 1][j + 1] = 1;
		}
	}
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
