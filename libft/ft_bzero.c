/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:42:15 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/21 18:44:54 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void	*str, size_t len)
{
	size_t			count;
	unsigned char	*strup;

	count = 0;
	strup = (unsigned char *)str;
	while (count < len)
	{
		strup[count] = '\0';
		count++;
	}
}
