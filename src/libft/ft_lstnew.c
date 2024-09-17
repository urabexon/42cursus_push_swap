/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:31:11 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/17 21:06:20 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_dst	*ft_lstnew(long value)
{
	t_dst	*new;

	new = (t_dst *)malloc(sizeof(t_dst));
	if (!new)
		return (NULL);
	new->value = value;
	new->press_val = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
