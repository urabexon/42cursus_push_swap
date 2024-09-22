/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:37:49 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/22 17:04:17 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	get_pivot_n(char **argv)
{
	int	argv_count;

	argv_count = count_argv(argv);
	argv_count -= 1;
	return (argv_count / 2);
}

void	sep_pivot(char **argv, t_dst **a, t_dst **b, long pivot_num)
{
	t_dst	*a_ptr;
	int		max;
	int		i;

	a_ptr = *a;
	i = 0;
	max = count_argv(argv) - 1;
	while (a_ptr->next && i < max)
	{
		if (a_ptr->value < pivot_num)
		{
			pb(a, b);
			a_ptr = *a;
			i++;
		}
		if (a_ptr->value >= pivot_num && i != max)
		{
			ra(a);
			a_ptr = *a;
			i++;
		}
	}
	return ;
}
