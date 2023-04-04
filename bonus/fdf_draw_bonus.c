/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 23:44:08 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/01 16:53:05 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

// ** Connect the values with lines, and draw each line pixel by pixel.
// ** Calculates the unit vector between the difference of each point (x and y),
// ** to get the correct length when the z_val increases or decreases.

static void	draw_lines(t_fdf *fdf)
{
	double	x;
	double	y;
	double	delta_x;
	double	delta_y;
	double	uvector;

	x = fdf->map.x0;
	y = fdf->map.y0;
	delta_x = fdf->map.x1 - fdf->map.x0;
	delta_y = fdf->map.y1 - fdf->map.y0;
	uvector = sqrt((pow(delta_x, 2)) + (pow(delta_y, 2)));
	delta_x /= uvector;
	delta_y /= uvector;
	while (uvector > 0)
	{
		put_pixel(fdf, x, y);
		x += delta_x;
		y += delta_y;
		uvector -= 1;
	}
}

// ** Draw the map, depending on the angles, the zoom level,
// ** the position (defined)
// ** by the average value of the window size, and if the
// ** user has moved the map and the z value.
// ** Will draw horizontal lines (x axis).

static void	draw_horizontal(t_fdf *fdf, int x, int y)
{
	int	xt;
	int	yt;

	xt = x - fdf->map.width / 2;
	yt = y - fdf->map.height / 2;
	fdf->map.x0 = fdf->map.angle_x * (xt - yt) * fdf->map.zoom;
	fdf->map.y0 = fdf->map.angle_y * (xt + yt) * fdf->map.zoom;
	fdf->map.y0 -= fdf->map.values[y][x] * fdf->map.z_value;
	fdf->map.x1 = fdf->map.angle_x * ((xt + 1) - yt) * fdf->map.zoom;
	fdf->map.y1 = fdf->map.angle_y * ((xt + 1) + yt) * fdf->map.zoom;
	fdf->map.y1 -= fdf->map.values[y][x + 1] * fdf->map.z_value;
	fdf->map.x0 += (WIN_WIDTH / 2) + fdf->map.coordinate_x;
	fdf->map.x1 += (WIN_WIDTH / 2) + fdf->map.coordinate_x;
	fdf->map.y0 += (WIN_HEIGHT / 2) + fdf->map.coordinate_y;
	fdf->map.y1 += (WIN_HEIGHT / 2) + fdf->map.coordinate_y;
	draw_lines(fdf);
}

// ** Draw the map, depending on the angles, the zoom level, 
// ** the position (defined)
// ** by the average value of the window size, and if the user 
// ** has moved the map and the z value.
// ** Will draw vertical lines (y axis).

static void	draw_vertical(t_fdf *fdf, int x, int y)
{
	int	xt;
	int	yt;

	xt = x - fdf->map.width / 2;
	yt = y - fdf->map.height / 2;
	fdf->map.x0 = fdf->map.angle_x * (xt - yt) * fdf->map.zoom;
	fdf->map.y0 = fdf->map.angle_y * (xt + yt) * fdf->map.zoom;
	fdf->map.y0 -= fdf->map.values[y][x] * fdf->map.z_value;
	fdf->map.x1 = fdf->map.angle_x * (xt - (yt + 1)) * fdf->map.zoom;
	fdf->map.y1 = fdf->map.angle_y * (xt + (yt + 1)) * fdf->map.zoom;
	fdf->map.y1 -= fdf->map.values[y + 1][x] * fdf->map.z_value;
	fdf->map.x0 += (WIN_WIDTH / 2) + fdf->map.coordinate_x;
	fdf->map.x1 += (WIN_WIDTH / 2) + fdf->map.coordinate_x;
	fdf->map.y0 += (WIN_HEIGHT / 2) + fdf->map.coordinate_y;
	fdf->map.y1 += (WIN_HEIGHT / 2) + fdf->map.coordinate_y;
	draw_lines(fdf);
}

// ** Draw the map by image.
// ** The characters in the draw_map() function stands for:
// ** x -> horizontal
// ** y -> vertical

static int	fdf_draw(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (fdf->map.height > y)
	{
		x = 0;
		while (fdf->map.width > x)
		{
			fdf->map.x0 = x;
			fdf->map.y0 = y;
			set_colors(fdf, x, y);
			if (fdf->map.width > x + 1)
				draw_horizontal(fdf, x, y);
			if (fdf->map.height > y + 1)
				draw_vertical(fdf, x, y);
			x += 1;
		}
		y += 1;
	}
	return (0);
}

int	render_fdf_draw(t_fdf *fdf)
{
	if (fdf->mlx.win == NULL)
		return (1);
	fdf_draw(fdf);
	mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
	mlx_put_image_to_window(fdf->mlx.init, fdf->mlx.win, fdf->mlx.img, 0, 0);
	return (0);
}
