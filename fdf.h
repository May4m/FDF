/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 15:29:01 by smamba            #+#    #+#             */
/*   Updated: 2016/06/05 14:30:10 by smamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include "keys.h"
# define WIDTH 1200
# define HEIGHT 800
# define SPACING 20
# define ROT_ANGLE 30
# define TO_RADIANS(degree) (degree * M_PI) / 180
# define TO_DEGREES(radian) (radian * 180) / M_PI

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
}				t_point;

typedef struct	s_env
{
	void			*win;
	void			*mlx;
	char			*file;
	int				**map;
	t_point			**map2;
	int				columns;
	int				rows;
}				t_env;

char			*ft_filter(char *st);
t_env			*new_environment(int ac, char **av);
void			draw_line(t_point p1, t_point p2, t_env *env, int color);
void			exit_on_err(const char *msg);
char			**get_cmap(char *filename, t_env *m);
int				**get_int_map(char **cmap, t_env *m);
void			validate_cmap_line(char *str);
void			validate_char_map(char **cmap);
void			init_env(t_env *m, int argc, char **argv);
void			transform_around_center(t_env *m);
t_point			**initial_coordinates(t_env *m);
int				expose_hook(t_env *m, float angle, int space,
		int color);
float			ft_fmax(float a, float b);
float			ft_fabs(float a);
int				get_map_cols(char **seq);
void			transform_around_center(t_env *m);
t_point			**initial_coordinates(t_env *m);
void			draw_edges(t_point **matrix, t_env *m, int color);
t_point			**isometric_projection(t_env *m, float angle, int space);
void			ft_sleep(int n);
#endif
