/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:46:17 by hmiyake           #+#    #+#             */
/*   Updated: 2019/11/14 21:12:28 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	map_size(t_filler *filler)
{
	char	*input;
	char	**map_size;

	input = gnl(0);
	map_size = ft_strsplit(input, ' ', ':');
	filler->height = ft_atoi(map_size[1]);
	filler->width = ft_atoi(map_size[2]);
	ft_free(map_size);
}

void	init_map(t_filler *filler)
{
	int		i;

	i = 0;
	filler->map = (char **)malloc(sizeof(char *) * filler->height);
	while (i < filler->height)
	{
		filler->map[i] = (char *)malloc(sizeof(char) * filler->width);
		i++;
	}
}

void	update_map(t_filler *filler)
{
	int		i;
	char	*temp;

	i = 0;
	gnl(0);
	while (i < filler->height)
	{
		temp = gnl(0);
		filler->map[i] = ft_strdup(temp + 4);
		i++;
	}
}

void	save_map(t_filler *filler)
{
	map_size(filler);
	init_map(filler);
	update_map(filler);
}