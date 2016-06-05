/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 09:28:53 by smamba            #+#    #+#             */
/*   Updated: 2016/06/05 14:24:59 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

void	adjust_height(t_env *m, int control)
{
	int i;
	int j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->columns)
		{
			if (m->map2[i][j].z != 0 && control == 1)
				m->map2[i][j].z *= 2;
			if (m->map2[i][j].z != 0 && control == -1)
				m->map2[i][j].z /= 2;
			j++;
		}
		i++;
	}
}

int		on_key_hook(int keycode, t_env *m)
{
	static float	angle = ROT_ANGLE;
	static int		space = SPACING;
	static int		color = 0x77ffaa;

	if (keycode == ESC)
	{
		free(m);
		exit(0);
	}
	if (keycode == PAGE_UP)
	{
		adjust_height(m, 1);
		expose_hook(m, angle, space, color);
	}
	if (keycode == PAGE_DOWN)
	{
		adjust_height(m, -1);
		expose_hook(m, angle, space, color);
	}
	if (keycode == RIGHT)
		expose_hook(m, angle, (space += 2), color);
	if (keycode == LEFT)
		expose_hook(m, angle, (space -= 2), color);
	return (0);
}

int		expose_hook(t_env *m, float angle, int space, int color)
{
	int		i;
	int		j;
	t_point	**matrix;

	matrix = isometric_projection(m, angle, space);
	mlx_clear_window(m->mlx, m->win);
	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->columns)
		{
			mlx_pixel_put(m->mlx, m->win, matrix[i][j].x,
					matrix[i][j].y, color);
			j++;
		}
		i++;
	}
	draw_edges(matrix, m, color);
	mlx_string_put(m->mlx, m->win, 10, 10, 0xffffff, "Author: Sizwe");
	mlx_string_put(m->mlx, m->win, 10, 30, 0xffffff,
			ft_strjoin("Filename: ", m->file));
	return (0);
}

int		on_render(t_env *env)
{
	expose_hook(env, ROT_ANGLE, SPACING, 0x77ffaa);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env *m;

	m = new_environment(argc, argv);
	transform_around_center(m);
	mlx_expose_hook(m->win, on_render, m);
	mlx_hook(m->win, 2, 1, on_key_hook, m);
	mlx_loop(m->mlx);
	return (0);
}
