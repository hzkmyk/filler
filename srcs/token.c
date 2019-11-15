/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:32:14 by hmiyake           #+#    #+#             */
/*   Updated: 2019/11/15 00:24:33 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	token_size(t_filler *filler)
{
	char	*input;
	char	**token_size;

	input = gnl(0);
	token_size = ft_strsplit(input, ' ', ':');
	filler->t_height = ft_atoi(token_size[1]);
	filler->t_width = ft_atoi(token_size[2]);
	ft_free(token_size);
}

void	init_token(t_filler *filler)
{
	int		i;

	i = 0;
	filler->token = (char **)malloc(sizeof(char *) * filler->t_height);
	while (i < filler->t_height)
	{
		filler->token[i] = (char *)malloc(sizeof(char) * filler->t_width);
		i++;
	}
}

void	update_token(t_filler *filler)
{
	int		i;
	char	*temp;

	i = 0;
	while (i < filler->t_height)
	{
		temp = gnl(0);
		filler->token[i] = ft_strdup(temp);
		i++;
	}
}

void	save_token(t_filler *filler)
{	
	token_size(filler);
	init_token(filler);
	update_token(filler);
}