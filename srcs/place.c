/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:58:20 by hmiyake           #+#    #+#             */
/*   Updated: 2019/11/15 00:15:30 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		place_heat(t_filler *filler, char heat, int i, int j)
{
	int	nothing;

	nothing = 0;
	if (i > 0)
	{
		if (j > 0 && filler->map[i - 1][j - 1] == '.')
		{
			filler->map[i - 1][j - 1] = heat;
			nothing = 1;
		}
		if (filler->map[i - 1][j] == '.')
		{
			filler->map[i - 1][j] = heat;
			nothing = 1;
		}
		if (j + 1 < filler->width && filler->map[i - 1][j + 1] == '.')
		{
			filler->map[i - 1][j + 1] = heat;
			nothing = 1;
		}
	}
	if (j > 0 && filler->map[i][j - 1] == '.')
	{
		filler->map[i][j - 1] = heat;
		nothing = 1;
	}
	if (j + 1 < filler->width && filler->map[i][j + 1] == '.')
	{
		filler->map[i][j + 1] = heat;
		nothing = 1;
	}
	if (i + 1 < filler->height)
	{
		if (j > 0 && filler->map[i + 1][j - 1] == '.')
		{
			filler->map[i + 1][j - 1] = heat;
			nothing = 1;
		}
		if (filler->map[i + 1][j] == '.')
		{
			filler->map[i + 1][j] = heat;
			nothing = 1;
		}
		if (j + 1 < filler->width && filler->map[i + 1][j + 1] == '.')
		{
			filler->map[i + 1][j + 1] = heat;
			nothing = 1;
		}
	}
	if (nothing == 0)
		return (1);
}

void	heat_map(t_filler *filler)
{
	int		i;
	int		j;
	char	heat;
	char	obj;

	i = 0;
	heat = '1';
	obj = filler->enermy;
	while (i < filler->height)
	{
		j = 0;
		while (j < filler->width)
		{
			if (filler->map[i][j] == filler->enermy)
				if (place_heat(filler, heat, i, j))
				{
					heat++;
					i = 0;
					continue;
				}
			j++;
		}
		i++;
	}
}

int		validate(t_filler *filler)
{
	
	return (0);
}

void	place(t_filler *filler)
{	
	int	best[2];
	int	i;
	int	j;

	best[0] = 0;
	best[1] = 0;
	i = 0;
	j = 0;
	while (i < filler->height)
	{
		j = 0;
		while (j <filler->width)
		{
			if (validate(filler) && filler->map[i][j] <= filler->map[best[0]][best[1]])
			{
				best[0] = i;
				best[1] = j;
				if (filler->player == 'o' && filler->map[best[0]][best[1]] == '1')
					break;
			}
			j++;
		}
		i++;
	}
	ft_printf("%d %d\n", best[0], best[1]);
}