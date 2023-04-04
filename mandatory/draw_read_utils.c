/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_read_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 01:20:40 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/01 16:15:59 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_htod(char *hex)
{
	int	len;
	int	base;
	int	dec;

	len = ft_strlen(hex) - 1;
	base = 1;
	dec = 0;
	while (len >= 0)
	{
		if (hex[len] >= '0' && hex[len] <= '9')
			dec += (hex[len] - 48) * base;
		else if (hex[len] >= 'A' && hex[len] <= 'F')
			dec += (hex[len] - 55) * base;
		else if (hex[len] >= 'a' && hex[len] <= 'f')
			dec += (hex[len] - 87) * base;
		if (hex[len] != '\n')
			base *= 16;
		len--;
	}
	return (dec);
}

// ** Gets the number values in each line from the fdf file.

int	count_values_lucas_mark(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] != '\n' && line[i] != '\0')
			len++;
		while (line[i] != ' ' && line[i] != '\n' && line[i] != '\0')
			i++;
	}
	return (len);
}

// adding 150 to each color chanel to garantee a visible color
// with fmin limit the min val of each color chanel to 255
// to avoid int overfload

void	set_colors(t_fdf *fdf, int x, int y)
{
	int	color;

	color = fdf->map.color_map[y][x];
	fdf->color.red = color & 0xFF;
	fdf->color.green = (color >> 8) & 0xFF;
	fdf->color.blue = (color >> 16) & 0xFF;
	if (!fdf->color.red && !fdf->color.blue && !fdf->color.green)
	{
		fdf->color.red += 150;
		fdf->color.green += 150;
		fdf->color.blue += 150;
	}
	if (fdf->color.red > 200 || fdf->color.blue > 200 || fdf->color.green > 200)
	{
		fdf->color.red = fmin(fdf->color.red, 255);
		fdf->color.green = fmin(fdf->color.green, 255);
		fdf->color.blue = fmin(fdf->color.blue, 255);
	}
}

// ** Put a pixel in a specific position defined by the draw_lines() function.
// ** If there's an area, make those colors lighter.

void	put_pixel(t_fdf *fdf, int x, int y)
{
	int	pos;

	if ((x > 0 && y > 0) && (x < WIN_WIDTH && y < WIN_HEIGHT))
	{
		pos = (x * 4) + (y * WIN_WIDTH * 4);
		fdf->image.data[pos] = fdf->color.red;
		fdf->image.data[pos + 1] = fdf->color.green;
		fdf->image.data[pos + 2] = fdf->color.blue;
	}
}
