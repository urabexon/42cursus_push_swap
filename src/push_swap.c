/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:06:14 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/17 21:08:12 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_argv(char **argv)
{
	int	argv_count;

	argv_count = 0;
	while (argv[argv_count])
		argv_count++;
	return (argv_count);
}

void	many_pb(t_dst **a, t_dst **b)
{
	int	b_count;
	int	i;

	b_count = ft_lstsize(*b);
	i = 0;
	while (i < b_count)
	{
		pa(a, b);
		i++;
	}
	return ;
}

//under five argv check
int	argv_checker(t_dst **a, t_dst **b, char **argv, t_config *conf)
{
	if (conf->len == 2)
	{
		sa(a);
		return (1);
	}
	if (conf->len == 3)
	{
		three_arg(argv, a, b);
		return (1);
	}
	if (conf->len > 6)
	{
		radix_sort(a, b, conf);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_dst		**a;
	t_dst		**b;
	t_config	*conf;

	if (argc <= 1)
		exit(0);
	if (argc == 2)
		return (output_error());
	if (is_argv_error(argv))
		return (output_error());
	a = (t_dst **)malloc(sizeof(t_dst *));
	b = (t_dst **)malloc(sizeof(t_dst *));
	conf = (t_config *)malloc(sizeof(t_config));
	if (!a || !b || !conf)
		exit(0);
	init_dst(a, b, argv, conf);
	if (is_sorted_ascending(a))
		exit(0);
	if (under_five_argv_checker(a, b, argv, conf))
		exit(0);
	separated_by_pivot(argv, a, b, get_pivot_num(argv));
	alg_1(a, b);
	many_pb(a, b);
	exit(0);
	return (0);
}
