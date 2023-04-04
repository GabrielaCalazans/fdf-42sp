/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:37:55 by gacalaza          #+#    #+#             */
/*   Updated: 2022/10/08 21:52:48 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countwords(char const *s, char c)
{
	size_t	words;
	int		count;

	words = 0;
	count = 0;
	if (!*s)
		return (0);
	while (s[count] != '\0')
	{
		if ((s[count] != c && s[count + 1] == c)
			|| (s[count] != c && s[count + 1] == '\0'))
			words++;
		count++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	substr_len;
	int		i;

	array = (char **)malloc(sizeof(char *) * (countwords(s, c) + 1));
	if (!array || !s)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				substr_len = ft_strlen(s);
			else
				substr_len = ft_strchr(s, c) - s;
			array[i++] = ft_substr(s, 0, substr_len);
			s += substr_len;
		}
	}
	array[i] = NULL;
	return (array);
}
