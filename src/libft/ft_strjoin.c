/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:07:55 by hurabe            #+#    #+#             */
/*   Updated: 2024/09/24 20:10:00 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;

	if (!s1 || !s2)
		return (NULL);
	str1 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str1)
		return (NULL);
	str2 = str1;
	while (*s1)
		*str2++ = *s1++;
	while (*s2)
		*str2++ = *s2++;
	*str2 = '\0';
	return (str1);
}
