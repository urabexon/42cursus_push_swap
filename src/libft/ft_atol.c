/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 23:17:29 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/20 16:30:16 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	ft_handle_overflow(long long now, long long past)
{
	if (now <= 0 && past != 0)
		return (1);
	else
		return (0);
}

static	long	longmax(int minus)
{
	if (minus == 1)
		return (LONG_MAX);
	else
		return (LONG_MIN);
}

static	void	init(int *i, int *minus, long long *ans, long long *ans_stock)
{
	*i = 0;
	*minus = 1;
	*ans = 0;
	*ans_stock = 0;
}

long	ft_atol(char *str)
{
	int			i;
	int			minus;
	long long	ans;
	long long	ans_stock;

	init(&i, &minus, &ans, &ans_stock);
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		ans = (ans * 10) + (str[i] - '0');
		i++;
		if (ft_handle_overflow(ans, ans_stock))
			return (longmax(minus));
		ans_stock = ans;
	}
	return (minus * ans);
}
