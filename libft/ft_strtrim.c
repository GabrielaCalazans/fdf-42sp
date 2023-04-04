/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 02:17:11 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/27 18:02:53 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size_s;
	size_t	start;
	char	*newstr;

	start = 0;
	size_s = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[size_s - 1] && ft_strchr(set, s1[size_s - 1]) && size_s > start)
		size_s--;
	newstr = (char *)malloc(sizeof(char) * (size_s - start + 1));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, &s1[start], size_s - start + 1);
	return (newstr);
}
