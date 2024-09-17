/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:30:55 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/17 21:07:16 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// リストの最後に新しいノードを追加する関数
// ft_lstlast関数を使ってリストの最後のノードを見つけ、その次に新しいノードを追加する。

void	ft_lstadd_back(t_dst **dst, t_dst *new)
{
	t_dst	*stock;

	if (!(*dst) || !dst)
	{
		*dst = new;
		return ;
	}
	stock = *dst;
	while (stock->next)
		stock = stock->next;
	new->prev = stock;
	stock->next = new;
}
