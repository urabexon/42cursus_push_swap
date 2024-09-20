/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 19:36:08 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/20 17:30:10 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	int	partition(long *arr, int low, int high)
{
	long	pivot;
	long	temp;
	int		i;
	int		j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

static void	quicksort(long *arr, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high);
		quicksort(arr, low, pivot_index - 1);
		quicksort(arr, pivot_index + 1, high);
	}
}

static long	*sort(char **argv, int len)
{
	int		i;
	long	*arr;

	arr = (long *)malloc(len * sizeof(long));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = ft_atol(argv[i]);
		i++;
	}
	quicksort(arr, 0, len - 1);
	return (arr);
}

long	*coordinate_press(char **argv, int len)
{
	long	*ret;
	long	*arr;
	int		i;
	int		j;

	argv++;
	arr = sort(argv, len);
	ret = (long *)malloc(len * sizeof(long));
	if (!ret || !arr)
		exit(0);
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (ft_atol(argv[i]) == arr[j])
			{
				ret[i] = j;
				break ;
			}
		}
	}
	free(arr);
	return (ret);
}
