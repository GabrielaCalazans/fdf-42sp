/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:55:01 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/26 19:06:24 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len_s1;
	size_t	len_s2;
	int		i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	strjoin = (char *) malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!strjoin)
		return (NULL);
	i = -1;
	while (s1[++i])
		strjoin[i] = s1[i];
	i = -1;
	while (s2[++i])
	{
		strjoin[len_s1] = s2[i];
		len_s1++;
	}
	strjoin[len_s1] = '\0';
	return (strjoin);
}
