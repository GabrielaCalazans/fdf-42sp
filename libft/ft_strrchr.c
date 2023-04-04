/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 00:31:25 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/13 20:20:24 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	size;

	size = ft_strlen(str);
	while (*str && size >= 0)
	{
		if (str[size] == (unsigned char)c)
		{
			return ((char *)str + size);
		}
		size--;
	}
	if (*str == (unsigned char)c)
	{
		return ((char *)str);
	}
	if (!ft_isprint(c))
	{
		return ((char *)str + 0);
	}
	return (NULL);
}
