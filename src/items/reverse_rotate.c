/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:21:15 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/17 21:46:17 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_dst **dst)
{
	t_dst	*front;
	t_dst	*bottom_most;

	front = *dst;
	bottom_most = ft_lstlast(*dst);
	front->prev = bottom_most;
	bottom_most->next = front;
	bottom_most->prev->next = NULL;
	bottom_most->prev = NULL;
	*dst = bottom_most;
}

// スタック a のすべての要素を 1 だけシフトダウンする。
// 最後の要素が最初の要素になる。
void	rra(t_dst **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

// スタック b のすべての要素を 1 だけシフトダウンする。
// 最後の要素が最初の要素になる。
void	rrb(t_dst **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

// rra と rrb を同時に行う。
void	rrr(t_dst **a, t_dst **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
