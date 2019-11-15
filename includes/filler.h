/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:17:03 by hmiyake           #+#    #+#             */
/*   Updated: 2019/11/14 23:28:14 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct	s_filler
{
	char	player;
	char	enermy;
	int		height;
	int		width;
	int		t_height;
	int		t_width;
	char	**map;
	char	**token;
}				t_filler;

char		*gnl(int fd);

void		save_map(t_filler *filler);
void		save_token(t_filler *filler);

#endif