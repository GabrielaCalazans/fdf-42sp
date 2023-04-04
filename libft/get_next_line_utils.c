/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:17:41 by gacalaza          #+#    #+#             */
/*   Updated: 2023/02/23 17:21:38 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*strnew;
	size_t	len_s1;
	size_t	len_s2;
	int		i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	strnew = (char *) malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!strnew)
		return (NULL);
	i = -1;
	if (s1)
	{
		while (s1[++i] && s1)
			strnew[i] = s1[i];
	}
	i = -1;
	while (s2[++i] && s2)
	{
		strnew[len_s1] = s2[i];
		len_s1++;
	}
	strnew[len_s1] = '\0';
	free (s1);
	return (strnew);
}
