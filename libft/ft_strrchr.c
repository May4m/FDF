/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:02:54 by smamba            #+#    #+#             */
/*   Updated: 2016/05/21 15:02:55 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*t;

	i = 0;
	t = NULL;
	while (s[i])
	{
		if (s[i] == c)
			t = s + i;
		i++;
	}
	if (s[i] == c)
		return ((char*)(s + i));
	return ((char*)t);
}
