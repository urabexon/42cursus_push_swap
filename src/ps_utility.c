/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:52:16 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/21 21:01:22 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	three_arg(char **argv, t_dst **a, t_dst **b)
{
	long	top;
	long	middle;
	long	bottom;

	top = ft_atol(argv[0]);
	middle = ft_atol(argv[1]);
	bottom - ft_atol(argv[2]);
	if (top < middle && middle > bottom && top < bottom)
	{
		pb(a, b);
		sa(a);
		pa(a, b);
	}
	else if (top > middle && middle < bottom && top < bottom)
		sa(a);
	else if (top < middle && middle > bottom && top > bottom)
		rra(a);
	else if (top > middle && middle < bottom && top > bottom)
		ra(a);
	else if (top > middle && middle > bottom && top > bottom)
	{
		sa(a);
		rra(a);
	}
	return ;
}
