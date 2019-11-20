/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 23:41:58 by hmiyake           #+#    #+#             */
/*   Updated: 2019/11/19 23:42:31 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

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
