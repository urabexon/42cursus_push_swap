/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:21:15 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/15 19:09:53 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_dst **dst)
{
	
}

void	rra(t_dst **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_dst **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_dst **a, t_dst **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
