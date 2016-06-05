/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:03:52 by smamba            #+#    #+#             */
/*   Updated: 2016/05/21 15:03:54 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *new;

	if (!(new = (char*)malloc(sizeof(*new) * (size + 1))))
		return (NULL);
	new = (char*)ft_memset(new, 0, size + 1);
	return (new);
}
