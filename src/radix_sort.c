/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:41:37 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/18 21:41:42 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long	get_top(t_dst *dst)
{
	return (dst->value);
}

void	radix_sort(t_dst **a, t_dst **b, t_config *conf)
{
	int		max_bits;
	int		i;
	int		j;
	long	num;

	max_bits = 0;
	while ((conf->max_num >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits && !is_sorted_ascending(a))
	{
		j = 0;
		while (j < conf->len)
		{
			num = get_top(*a);
			if (num & (1 << i))
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
