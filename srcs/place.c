/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:58:20 by hmiyake           #+#    #+#             */
/*   Updated: 2019/11/15 22:38:46 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

FILE	*f;

void	print_map(t_filler *filler, FILE *f)
{
	for (int k = 0; k < filler->height; k++)
		fprintf(f, "%s\n", filler->map[k]);
}

int		place_heat(t_filler *filler, char heat, int i, int j)
{
	int	nothing;

	nothing = 0;
	if (i > 0)
	{
		if (j > 0 && filler->map[i - 1][j - 1] == '.')
		{
			filler->map[i - 1][j - 1] = heat;
			nothing++;
		}
		if (filler->map[i - 1][j] == '.')
		{
			filler->map[i - 1][j] = heat;
			nothing++;
		}
		if (j + 1 < filler->width && filler->map[i - 1][j + 1] == '.')
		{
			filler->map[i - 1][j + 1] = heat;
			nothing ++;
		}
	}
	if (j > 0 && filler->map[i][j - 1] == '.')
	{
		filler->map[i][j - 1] = heat;
		nothing++;
	}
	if (j + 1 < filler->width && filler->map[i][j + 1] == '.')
	{
		filler->map[i][j + 1] = heat;
		nothing++;
	}
	if (i + 1 < filler->height)
	{
		if (j > 0 && filler->map[i + 1][j - 1] == '.')
		{
			filler->map[i + 1][j - 1] = heat;
			nothing++;
		}
		if (filler->map[i + 1][j] == '.')
		{
			filler->map[i + 1][j] = heat;
			nothing++;
		}
		if (j + 1 < filler->width && filler->map[i + 1][j + 1] == '.')
		{
			filler->map[i + 1][j + 1] = heat;
			nothing++;
		}
	}
	print_map(filler, f);
	fprintf(f, "\ni is %d j is %d\n", i, j);
	if (nothing == 0)
		return (1);
	return(0);
}

void	heat_map(t_filler *filler)
{
	int		i;
	int		j;
	char	heat;
	char	obj;

	f = fopen("test3", "w");
	i = 0;
	heat = '1';
	obj = filler->enermy;
	while (i < filler->height)
	{
		j = 0;
		while (j < filler->width)
		{
			if (ft_tolower(filler->map[i][j]) == obj)
			{
				if (place_heat(filler, heat, i, j))
				{
					obj = heat;
					heat++;
					i = 0;
					continue;
				}
			}
			j++;
		}
		i++;
	}
}

// int		validate(t_filler *filler, int i, int j)
// {
// 	int	taken;
// 	int	ii;
// 	int	jj;

// 	taken = 0;
// 	ii = i;
// 	jj = j;
// 	if (j + (filler->t_width) > filler->width)
// 		return (0);	
// 	if (j + (filler->t_height) > filler->height)
// 		return (0);
// 	while (i < filler->t_height + ii)
// 	{
// 		j = jj;
// 		while (j < filler->t_width + jj)
// 		{
// 			if (filler->map[i][j] == filler->enermy)
// 				return (0);
// 			else if (filler->map[i][j] == filler->player)
// 			{
// 				taken++;
// 				if (taken > 1)
// 					return (0);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (taken != 1)
// 		return (0);
// 	return (1);
// }

void	place(t_filler *filler)
{	
	int	best[2];
	int	i;
	int	j;

	best[0] = 0;
	best[1] = 0;
	i = 0;
	j = 0;
	heat_map(filler);
	// for (int ii = 0; ii < filler->height; ii++)
	// 	fprintf(f, "%s\n", filler->map[ii]);
	// while (i < filler->height)
	// {
	// 	j = 0;
	// 	while (j < filler->width)
	// 	{
	// 		if (validate(filler, i, j) && filler->map[i][j] <= filler->map[best[0]][best[1]])
	// 		{
	// 			best[0] = i;
	// 			best[1] = j;
	// 			if (filler->player == 'o' && filler->map[best[0]][best[1]] == '1')
	// 				break;
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }
	// ft_printf("%d %d\n", best[0], best[1]);
}