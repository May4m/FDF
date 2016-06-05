/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:03:26 by smamba            #+#    #+#             */
/*   Updated: 2016/05/21 15:03:28 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (*(unsigned char*)(s1 + i) != *(unsigned char*)(s2 + i))
			return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i));
		i++;
	}
	return (0);
}
