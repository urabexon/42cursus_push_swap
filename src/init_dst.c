/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:52:16 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/22 22:06:41 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_dst(t_dst **a, t_dst **b, char **argv, t_config *conf)
{
	int		i;
	int		argv_count;
	long	*arr;

	argv_count = 0;
	while (argv[argv_count])
		argv++;
	argv_count--;
	i = 0;
	arr = coordinate_press(argv, argv_count);
	conf->len = argv_count;
	conf->max_num = argv_count - 1;
	*a = NULL;
	*b = NULL;
	while (i < argv_count)
	{
		ft_lstadd_back(a, ft_lstnew(arr[i]));
		i++;
	}
	free(arr);
}

int	is_ascending(t_dst **a)
{
	t_dst	*stock;
	long	judge;

	stock = *a;
	judge = stock->value;
	while (stock->next)
	{
		stock = stock->next;
		if (judge > stock->value)
			return (0);
		judge = stock->value;
	}
	return (1);
}

int	is_descending(t_dst **b)
{
	t_dst	*stock;
	long	judge;

	stock = *b;
	judge = stock->value;
	while (stock->next)
	{
		stock = stock->next;
		if (judge < stock->value)
			return (0);
		judge = stock->value;
	}
	return (1);
}
