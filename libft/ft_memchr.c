/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:43:17 by gacalaza          #+#    #+#             */
/*   Updated: 2022/11/09 23:23:07 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	size_t			count;
	size_t			size;
	unsigned char	*point_str;

	size = len -1;
	count = 0;
	point_str = (unsigned char *)str;
	if (len <= 0)
	{
		return (NULL);
	}
	while (count < size)
	{
		if (point_str[count] == (unsigned char)c)
		{
			return ((unsigned char *)point_str + count);
		}		
		count++;
	}
	if (point_str[count] == (unsigned char)c)
	{
		return ((unsigned char *)point_str + count);
	}
	return (NULL);
}
