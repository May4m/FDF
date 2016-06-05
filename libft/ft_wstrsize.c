/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 16:16:50 by smamba            #+#    #+#             */
/*   Updated: 2016/06/03 16:16:53 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrsize(wchar_t *wstr)
{
	int size;
	int i;

	i = 0;
	size = 0;
	while (wstr[i])
	{
		if (wstr[i] <= 127)
			size += 1;
		else if (wstr[i] <= 2047)
			size += 2;
		else if (wstr[i] <= 65535)
			size += 3;
		else if (wstr[i] <= 1114111)
			size += 4;
		i++;
	}
	return (size);
}
