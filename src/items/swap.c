/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:21:19 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/15 19:05:07 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_dst **dst)
{
	
}

void	sa(t_dst **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_dst **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_dst **a, t_dst **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
