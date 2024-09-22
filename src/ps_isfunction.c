/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_isfunction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:46:07 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/22 18:37:12 by hurabe           ###   ########.fr       */
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
	bottom = ft_atol(argv[2]);
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


/*
return (0); no swap
return (1); swap a
return (2); swap b
return (3); swap a and b
*/

int	is_swap(t_dst **a, t_dst **b)
{
	int		a_flg;
	int		b_flg;
	t_dst	*a_ptr;
	t_dst	*b_ptr;

	a_flg = 0;
	b_flg = 0;
	a_ptr = *a;
	b_ptr = *b;
	if (a_ptr->value > a_ptr->next->value && a_ptr != NULL \
		&& a_ptr->next != NULL)
		a_flg = 1;
	if (!(!(b_ptr->next)))
		if (b_ptr->value < b_ptr->next->value && b_ptr != NULL \
		&& b_ptr->next != NULL)
		b_flg = 1;
	if (a_flg && b_flg)
		return (3);
	else if (a_flg)
		return (1);
	else if (b_flg)
		return (2);
	else
		return (0);
}

/*
return (0); no rotate
return (1); rotate a
return (2); rotate b
return (3); rotate a and b
*/

int	is_rotate(t_dst **a, t_dst **b)
{
	int	a_flg;
	int	b_flg;

	a_flg = 0;
	b_flg = 0;
	if (!is_ascending(a))
		a_flg = 1;
	if (!is_descending(b))
		b_flg = 1;
	if (a_flg && b_flg)
		return (3);
	else if (a_flg)
		return (1);
	else if (b_flg)
		return (2);
	else
		return (0);
}

void	let_go(t_dst **a, t_dst **b, int is_swap, int is_rotate)
{
	int	is_sort_a;
	int	is_sort_b;

	if (is_swap == 1)
		sa(a);
	else if (is_swap == 2)
		sb(b);
	else if (is_swap == 3)
		ss(a, b);
	is_sort_a = is_ascending(a);
	is_sort_b = is_descending(b);
	if (is_rotate == 1 && !is_sort_a)
		rra(a);
	else if (is_rotate == 2 && !is_sort_b)
		rrb(b);
	else if (is_rotate == 3 && !is_sort_a && !is_sort_b)
		rrr(a, b);
}

int	alg_1(t_dst **a, t_dst **b)
{
	while (1)
	{
		let_go(a, b, is_swap(a, b), is_rotate(a, b));
		if (is_ascending(a) && is_descending(b))
			break ;
	}
	return (1);
}
