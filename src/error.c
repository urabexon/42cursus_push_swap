/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:39:39 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/17 21:08:10 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
