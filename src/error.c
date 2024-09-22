/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:39:39 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/22 18:35:20 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	int	is_int(char	*s)
{
	int	i;
	int	max;
	int	zero_count;

	i = 0;
	zero_count = 0;
	max = ft_strlen(s);
	if (max == 1 && !ft_isdigit(s[i]))
		return (0);
	while (s[zero_count] == '0')
		zero_count++;
	while (i < max)
	{
		if (s[0] != '-' && !ft_isdigit(s[i]))
			return (0);
		if (i != 0 && !ft_isdigit(s[i]))
			return (0);
		if (s[0] == '-' && s[1] == '0')
			return (0);
		i++;
	}
	if (ft_atol(s) < INT_MIN || INT_MAX < ft_atol(s))
		return (0);
	if (zero_count > 1)
		return (0);
	return (1);
}

int	output_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

void	error_component(char **stk, char **argv, int i)
{
	int	j;

	j = 1;
	while (stk[j])
	{
		if (ft_strcmp(argv[i], stk[j]) == 0)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		j++;
	}
	stk[i] = argv[i];
}

int	is_argv_error(char **argv)
{
	int		i;
	char	**stock;

	i = 1;
	stock = (char **)malloc(sizeof(char *) * count_argv(argv));
	if (!stock || count_argv(argv) == 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	while (i < count_argv(argv))
	{
		stock[i] = NULL;
		if (!is_int(argv[i]))
		{
			write(1, "Error\n,", 6);
			exit(0);
		}
		error_component(stock, argv, i);
		i++;
	}
	free(stock);
	return (0);
}
