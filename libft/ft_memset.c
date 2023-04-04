/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:43:54 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/12 19:43:56 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int charc, size_t len)
{
	size_t			count;
	unsigned char	*strup;

	count = 0;
	strup = (unsigned char *)str;
	while (count < len)
	{
		strup[count] = charc;
		count++;
	}
	return (str);
}
