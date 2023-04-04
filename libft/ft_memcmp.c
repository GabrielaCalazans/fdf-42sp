/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:00:08 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/19 19:43:56 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	size_t			i;
	unsigned char	*pstr1;
	unsigned char	*pstr2;

	i = 0;
	pstr1 = (unsigned char *)str1;
	pstr2 = (unsigned char *)str2;
	while (len > i)
	{
		if ((pstr1[i] != pstr2[i]) || (i + 1) == len)
		{
			return (pstr1[i] - pstr2[i]);
		}
		i++;
	}
	return (0);
}
