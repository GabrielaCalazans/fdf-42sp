/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:17:45 by gacalaza          #+#    #+#             */
/*   Updated: 2023/03/04 01:36:21 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_line(int fd, char *static_var)
{
	ssize_t	n_bytes;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	n_bytes = 1;
	while (!(ft_strchr(static_var, '\n')))
	{
		n_bytes = read(fd, buff, BUFFER_SIZE);
		if (n_bytes <= 0)
			break ;
		buff[n_bytes] = '\0';
		static_var = ft_strjoin_gnl(static_var, buff);
	}
	free (buff);
	if (n_bytes == -1)
		return (NULL);
	return (static_var);
}

static char	*get_line(char *static_var)
{
	char	*line;
	int		i;

	i = 0;
	if (!static_var)
		return (NULL);
	while (static_var[i] && static_var[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (static_var[i] && static_var[i] != '\n')
	{
		line[i] = static_var[i];
		i++;
	}
	if (static_var[i] == '\n')
	{
		line[i] = static_var[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*rem_static_var(char *static_var)
{
	int		i;
	int		j;
	char	*rem;

	i = 0;
	if (!static_var)
		return (NULL);
	while (static_var[i] && static_var[i] != '\n')
		i++;
	if ((static_var[i] == '\n' && static_var[i + 1] == '\0') || !static_var[i])
	{
		free (static_var);
		return (NULL);
	}
	rem = malloc(sizeof(char) * (ft_strlen(static_var) - i) + 1);
	if (!rem)
		return (NULL);
	i++;
	j = 0;
	while (static_var[i])
		rem[j++] = static_var[i++];
	rem[j] = '\0';
	free (static_var);
	return (rem);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_var[1024];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	static_var[fd] = read_line(fd, static_var[fd]);
	line = get_line(static_var[fd]);
	static_var[fd] = rem_static_var(static_var[fd]);
	return (line);
}
