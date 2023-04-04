/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:45:08 by gacalaza          #+#    #+#             */
/*   Updated: 2022/10/11 21:29:24 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	size_t	c_l;
	size_t	c_b;
	int		match;

	count = -1;
	if (0 == ft_strlen(little))
		return ((char *)big);
	while (*(big + ++count) && count < len)
	{
		if (*(big + count) == *(little + 0))
		{
			c_b = count;
			c_l = 0;
			match = 1;
			while (*(big + c_b) && *(little + c_l) && c_b < len && c_l < len)
			{
				if (*(big + c_b++) != *(little + c_l++))
					match = 0;
				if (match == 1 && !*(little + c_l))
					return ((char *)big + count);
			}
		}
	}
	return (NULL);
}
