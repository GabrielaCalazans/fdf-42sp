/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:46:22 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/01 12:14:37 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	zoom_change(t_fdf *fdf)
{
	int	result;

	if (fdf->map.width > fdf->map.height)
		result = (WIN_WIDTH / fdf->map.width) + SPECIAL_ZOOM;
	else
		result = (WIN_HEIGHT / fdf->map.height) + SPECIAL_ZOOM;
	return (result);
}

// ** Reset the map to the initial values.

void	set_map(t_fdf *fdf)
{
	fdf->map.angle_x = cos(M_PI / 3);
	fdf->map.angle_y = fdf->map.angle_x * sin(M_PI / 6);
	fdf->map.zoom = zoom_change(fdf);
	fdf->color.red = 0x4F;
	fdf->color.green = 0x4F;
	fdf->color.blue = 0x4F;
}

// ** Assign a key code (macros defined in "includes/fdf.h")
// ** to a specific task, as close the program

int	key_events(int key, t_fdf *fdf)
{
	if (key == KEY_ESCAPE)
		close_win(fdf);
	return (0);
}
