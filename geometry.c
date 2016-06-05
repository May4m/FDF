/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 10:32:37 by smamba            #+#    #+#             */
/*   Updated: 2016/06/05 14:32:44 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**isometric_projection(t_env *m, float angle, int space)
{
	t_point	**matrix;
	int		i;
	int		j;
	float	theta;

	i = 0;
	matrix = (t_point**)malloc(sizeof(*matrix) * m->rows);
	theta = (float)TO_RADIANS(angle);
	while (i < m->rows)
	{
		matrix[i] = (t_point*)malloc(sizeof(t_point) * m->columns);
		j = 0;
		while (j < m->columns)
		{
			matrix[i][j].x = WIDTH / 2 + m->map2[i][j].x *
				space * cos(theta) - m->map2[i][j].y * space * cos(theta);
			matrix[i][j].y = HEIGHT / 2 + m->map2[i][j].x * space *
				sin(theta) + m->map2[i][j].y * space *
				sin(theta) - m->map2[i][j].z * space;
			j++;
		}
		i++;
	}
	return (matrix);
}

void	draw_edges(t_point **matrix, t_env *m, int color)
{
	int i;
	int j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->columns)
		{
			if (j < m->columns - 1)
				draw_line(matrix[i][j], matrix[i][j + 1], m, color);
			if (i < m->rows - 1)
				draw_line(matrix[i][j], matrix[i + 1][j], m, color);
			j++;
		}
		i++;
	}
}

t_point	**initial_coordinates(t_env *m)
{
	t_point	**temp;
	int		i;
	int		j;

	temp = (t_point**)malloc(sizeof(*temp) * (m->rows));
	i = 0;
	while (i < m->rows)
	{
		j = 0;
		temp[i] = (t_point*)malloc(sizeof(t_point) * m->columns);
		while (j < m->columns)
		{
			temp[i][j].x = j;
			temp[i][j].y = i;
			temp[i][j].z = m->map[i][j];
			j++;
		}
		i++;
	}
	return (temp);
}

void	transform_around_center(t_env *m)
{
	int	i;
	int j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (j < m->columns)
		{
			(m->map2)[i][j].x -= (m->columns / 2);
			(m->map2)[i][j].y -= (m->rows / 2);
			j++;
		}
		i++;
	}
}

void	draw_line(t_point v1, t_point v2, t_env *m, int color)
{
	float	step;
	float	t;
	float	dx;
	float	dy;
	t_point	sum;

	t = 0;
	dx = ft_fabs(v1.x - v2.x);
	dy = ft_fabs(v1.y - v2.y);
	step = (float)(1 / (ft_fmax(dx, dy) * 2));
	while (t <= 1)
	{
		sum.x = v1.x + t * (v2.x - v1.x);
		sum.y = v1.y + t * (v2.y - v1.y);
		mlx_pixel_put(m->mlx, m->win, sum.x, sum.y, color);
		t = t + step;
	}
}
