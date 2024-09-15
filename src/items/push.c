/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:21:09 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/15 22:36:14 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_dst **send, t_dst **recieve)
{
	
}

void	pa(t_dst **a, t_dst **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_dst **a, t_dst **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
