/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:21:09 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/17 18:45:42 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_dst **send, t_dst **recieve)
{
	t_dst	*send_to_recieve;
	t_dst	*next_send_top;
	t_dst	*recieve_ptr;

	send_to_recieve = *send;
	next_send_top = send_to_recieve->next;
	
}

// bの先頭の要素を取ってaの先頭に置く。
// bが空の場合は何もしない。
void	pa(t_dst **a, t_dst **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

// aの先頭の要素を取り、bの先頭に置く。
// aが空の場合は何もしない。
void	pb(t_dst **a, t_dst **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
