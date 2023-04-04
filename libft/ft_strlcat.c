/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:18:13 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/25 02:33:51 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	dlen;
	size_t	slen;

	count = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dest);
	if (size == 0)
		return (slen);
	if (size < dlen)
		return (slen += size);
	else
		slen += dlen;
	while (src[count] != '\0' && dlen < size - 1 && dest != src)
	{
		dest[dlen] = src[count];
		dlen++;
		count++;
	}
	dest[dlen] = '\0';
	return (slen);
}
