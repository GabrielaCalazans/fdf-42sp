/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:43:10 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/20 20:04:58 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	if (size == 0 || nitems == 0)
		return (NULL);
	if ((nitems * size) / size != nitems)
		return (NULL);
	ptr = malloc (nitems * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size * nitems);
	return (ptr);
}
