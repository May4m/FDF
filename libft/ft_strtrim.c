/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 14:51:39 by smamba            #+#    #+#             */
/*   Updated: 2016/05/21 14:51:40 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*dst;

	if (s)
	{
		i = 0;
		j = (int)ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (!(dst = (char*)malloc(sizeof(*dst) * (j - i + 1))))
			return (NULL);
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		k = 0;
		while (i <= j)
		{
			dst[k++] = s[i];
			i++;
		}
		dst[k] = '\0';
		return (dst);
	}
	return (NULL);
}
