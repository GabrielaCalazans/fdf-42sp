/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 01:00:36 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/01 15:43:26 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

// ** Count and returns the number of lines (rows) that the file has.
// ** This value is used to allocate the correct memory size
// ** for the two dimensional array.
// ** If the total values from every line is not equal to the other lines,
// ** there is an error with the fdf file...

static void	count_lines_davi(int fd, int *cols, int *rows)
{
	int		len;
	char	*line;

	len = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*line == '\0')
			break ;
		len = count_values_lucas_mark(line);
		if (len > *cols)
			*cols = len;
		if (*cols == len)
			*rows += 1;
		else
			ft_puterror("Not a valid file! o_o", 4);
		free(line);
		line = get_next_line(fd);
	}
}

static int	count_lines(t_fdf *fdf, char *argv)
{
	int		fd;
	int		rows;
	int		cols;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		free (fdf);
		ft_puterror("Error opening file! :(", 1);
	}
	rows = 0;
	cols = 0;
	count_lines_davi(fd, &cols, &rows);
	if (close(fd) < 0)
		ft_puterror("Error closing file! WTF?! ~_~", 2);
	fdf->map.width = cols;
	if (!(fdf->map.width == cols))
		ft_puterror("Not a valid file! o_o", 4);
	return (rows);
}

// ** Gets and store the values and hexdecimal color 
// ** from the file into a two dimensional array,
// ** by atoi/h-ing every little f (converting from ascii to ints).

static void	get_values(t_fdf *fdf, int x, int y, char *line)
{
	int		i;
	int		j;
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		ft_puterror("Not a valid file! o_o", 4);
	i = 0;
	while (split[i] && (x != fdf->map.width))
	{
		fdf->map.values[y][x] = ft_atoi(split[i]);
		j = 0;
		while (split[i][j] != ',' && split[i][j])
			j++;
		if (split[i][j++] == ',')
			fdf->map.color_map[y][x] = ft_htod(&split[i][j]);
		else
			fdf->map.color_map[y][x] = 0;
		i++;
		x++;
	}
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

// ** Read the fdf file, allocates in memory the correct size
// ** of the height and width of the map.

void	read_lines(t_fdf *fdf, int fd)
{
	int		x;
	int		y;
	char	*line;

	x = 0;
	y = 0;
	line = get_next_line(fd);
	while (line != NULL && y != fdf->map.height)
	{
		fdf->map.values[y] = (int *)malloc(sizeof(int) * fdf->map.width);
		fdf->map.color_map[y] = (int *)malloc(sizeof(int) * fdf->map.width);
		if (!(fdf->map.values[y] || fdf->map.color_map[y]))
			ft_puterror("Memory Allocation failed!", 3);
		get_values(fdf, x, y, line);
		x = 0;
		y += 1;
		free(line);
		line = get_next_line(fd);
	}
}

void	fdf_read(char *argv, t_fdf *fdf)
{
	int	fd;

	fdf->map.height = count_lines(fdf, argv);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		free (fdf);
		ft_puterror("Error opening file! :(", 1);
	}
	fdf->map.values = (int **)malloc(sizeof(int *) * fdf->map.height);
	fdf->map.color_map = (int **)malloc(sizeof(int *) * fdf->map.height);
	if (!(fdf->map.values || fdf->map.color_map))
		ft_puterror("Memory Allocation failed! :O", 3);
	read_lines(fdf, fd);
	if (close(fd) < 0)
		ft_puterror("Error closing file! :|", 2);
}
