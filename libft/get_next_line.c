/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 17:32:52 by smamba            #+#    #+#             */
/*   Updated: 2016/05/21 15:47:23 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*renew(char const *s1, char const *s2)
{
	char	*new;

	new = ft_strjoin(s1, s2);
	free((void *)s1);
	return (new);
}

static int	read_to_buffer(int const fd, char **stock)
{
	char	*buff;
	int		ret;

	if (!(buff = (char *)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	ret = read(fd, buff, BUFF_SIZE);
	if (ret > 0)
	{
		buff[ret] = '\0';
		*stock = renew(*stock, buff);
	}
	free(buff);
	return (ret);
}

int			get_next_line(int const fd, char **line)
{
	static char	*store = NULL;
	char		*cache;
	int			ret;

	if ((!store && !(store = (char *)malloc(sizeof(*store)))) || !line
			|| fd < 0 || BUFF_SIZE < 0)
		return (-1);
	cache = ft_strchr(store, '\n');
	while (!cache)
	{
		ret = read_to_buffer(fd, &store);
		if (ret == 0)
		{
			if (ft_strlen(store) == 0)
				return (0);
			store = renew(store, "\n");
		}
		if (ret < 0)
			return (-1);
		else
			cache = ft_strchr(store, '\n');
	}
	*line = ft_strsub(store, 0, ft_strlen(store) - ft_strlen(cache));
	store = ft_strdup(cache + 1);
	return (1);
}
