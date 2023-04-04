/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:09:40 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/25 02:33:07 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	subcount;

	subcount = 0;
	if (ft_strlen(s) < start)
	{
		substr = (char *)malloc(sizeof(*s));
		substr[0] = '\0';
		return (substr);
	}
	else if (ft_strlen(s) < len)
		substr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	else if (len == ft_strlen(s))
		substr = (char *)malloc(sizeof(char) * ft_strlen(s) - start + 1);
	else
		substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	while (s[start] != '\0' && subcount < len)
			substr[subcount++] = s[start++];
	substr[subcount] = '\0';
	return (substr);
}
