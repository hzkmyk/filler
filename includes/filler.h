/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:17:03 by hmiyake           #+#    #+#             */
/*   Updated: 2019/11/17 17:51:35 by hmiyake          ###   ########.fr       */
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
	char	**visited;
}				t_filler;

typedef struct s_coor
{
	int				y;
	int				x;
}				t_coor;

typedef	struct	s_node
{
	t_coor			coor;
	struct s_node	*next;
}				t_node;

typedef struct	s_queue
{
	t_node			*first;
	t_node			*last;
}				t_queue;

char			*gnl(int fd);

void			save_map(t_filler *filler);
void			save_token(t_filler *filler);

void			place(t_filler *filler);

t_queue			*q_init(void);
void			enqueue(t_queue *queue, int x, int y);
t_coor			dequeue(t_queue *queue);
int		is_empty(t_queue *queue);
#endif
