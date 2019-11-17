/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 21:06:39 by hmiyake           #+#    #+#             */
/*   Updated: 2019/11/17 02:29:37 by hmiyake          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_queue	*q_init(void)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

int		is_empty(t_queue *queue)
{
	if (queue->first == NULL)
		return (1);
	return (0);
}

void	enqueue(t_queue *queue, int y, int x)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->coor.x = x;
	node->coor.y = y;
	node->next = NULL;

	if (is_empty(queue))
		queue->first = node;
	else
		queue->last->next = node;
	queue->last = node;
}

t_coor	dequeue(t_queue *queue)
{
	t_node	*temp;
	t_coor	xy;

	xy.x = 0;
	xy.y = 0;
	if (!is_empty(queue))
	{
		temp = queue->first;
		queue->first = queue->first->next;
		xy.x = temp->coor.x;
		xy.y = temp->coor.y;
		free (temp);
		if (queue->first == NULL)
			queue->last = NULL;	
	}
	return (xy);
}
