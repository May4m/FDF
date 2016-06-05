/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 09:45:31 by smamba            #+#    #+#             */
/*   Updated: 2016/06/05 14:23:34 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**get_cmap(char *filename, t_env *m)
{
	int		fd;
	char	*line;
	char	**map;
	int		ok;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_on_err("IOError: Could not open file\n");
	ok = 0;
	while (get_next_line(fd, &line))
		ok++;
	m->rows = ok;
	close(fd);
	map = (char**)malloc(sizeof(*map) * (ok + 1));
	fd = open(filename, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		map[i] = line;
		i++;
	}
	map[i] = 0;
	return (map);
}

int		**get_int_map(char **cmap, t_env *m)
{
	int		i;
	int		j;
	int		**map;
	char	**temp_map;

	i = 0;
	map = (int**)malloc(sizeof(int*) * m->rows);
	temp_map = ft_strsplit(cmap[0], ' ');
	m->columns = get_map_cols(temp_map);
	while (cmap[i])
	{
		map[i] = (int*)malloc(sizeof(int) * m->columns);
		temp_map = ft_strsplit(cmap[i], ' ');
		j = 0;
		while (temp_map[j])
		{
			map[i][j] = ft_atoi(temp_map[j]);
			j++;
		}
		free(temp_map);
		if (j != m->columns)
			exit_on_err("IOError: Not a rectangular map\n");
		i++;
	}
	return (map);
}

void	validate_cmap_line(char *str)
{
	int	i;
	int	ok;

	i = 0;
	ok = 0;
	while (str[i])
	{
		if (str[i] == '-')
			ok++;
		i++;
	}
}

void	validate_char_map(char **cmap)
{
	int		i;
	int		j;
	int		k;
	char	**tmp;

	i = 0;
	while (cmap[i] && !(j = 0))
	{
		validate_cmap_line(cmap[i]);
		tmp = ft_strsplit(cmap[i], ' ');
		while (tmp[j])
		{
			k = 0;
			while (tmp[j][k] && ft_filter(tmp[j]))
			{
				if (ft_isdigit(tmp[j][k]) || tmp[j][k] == '-')
					k++;
				else
					exit_on_err("IOError: Not a valid map\n");
			}
			j++;
		}
		free(tmp);
		i++;
	}
}

void	init_env(t_env *m, int argc, char **argv)
{
	char **cmap;

	if (argc != 2)
		exit_on_err("Usage: ./fdf filename\n");
	else
	{
		m->file = argv[1];
		if (!(m->mlx = mlx_init()))
			exit_on_err("AppError: Could not initialize mlx\n");
		if (!(m->win = mlx_new_window(m->mlx, WIDTH, HEIGHT, m->file)))
			exit_on_err("AppError: Could not create window\n");
		cmap = get_cmap(m->file, m);
		validate_char_map(cmap);
		m->map = get_int_map(cmap, m);
		m->map2 = initial_coordinates(m);
	}
}
