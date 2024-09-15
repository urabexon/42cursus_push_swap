/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:21:17 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/15 19:07:38 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_dst **dst)
{
	
}

void	ra(t_dst **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_dst **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_dst **a, t_dst **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
