/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 23:40:21 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/01 12:08:36 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

// ** My defined header files.

# include "../libft/libft.h"

// ** Macros for the escape key
// ** plus projection size SPECIAL_ZOOM
// ** the window size (width and height),

# define KEY_ESCAPE		0xff1b
# define WIN_WIDTH		1280
# define WIN_HEIGHT		720
# define SPECIAL_ZOOM	1

// ** FDF Structures
// ** t_mlx	: required minilibx arguments.
// ** t_image	: variables to be used for creation of the image (map).
// **		data -> information about the image, allowing to be modified.
// **		size -> move from one line to another in the image.
// **		endian -> how the pixel color in the image needs to be stored.
// **		bpp -> filled with the number of bits to represent a pixel color.
// ** t_map	: values used to manipulate the fdf map.
// ** t_color	: define the color, rgb value (24-bits).
// ** t_fdf	: nested structure that calls all of the other structures.

typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct s_image
{
	char	*data;
	int		size;
	int		endian;
	int		bpp;
}				t_image;

typedef struct s_map
{
	int		**values;
	int		**color_map;
	int		width;
	int		height;
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	int		zoom;
	double	z_value;
	double	angle_x;
	double	angle_y;
}				t_map;

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef struct s_fdf
{
	t_mlx	mlx;
	t_map	map;
	t_image	image;
	t_color	color;
}				t_fdf;

// ** Prototypes.

void	fdf_read(char *argv, t_fdf *fdf);
int		render_fdf_draw(t_fdf *fdf);
int		key_events(int key, t_fdf *fdf);
void	set_map(t_fdf *fdf);
void	ft_puterror(char *msg, int ret);
int		ft_htod(char *hex);
void	set_colors(t_fdf *fdf, int x, int y);
void	put_pixel(t_fdf *fdf, int x, int y);
int		close_win(t_fdf *fdf);
int		count_values_lucas_mark(char *line);

#endif