/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:44:41 by gacalaza          #+#    #+#             */
/*   Updated: 2022/11/09 23:23:25 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		src_size;
	char	*str_dest;

	src_size = ft_strlen(s);
	str_dest = (char *) malloc(sizeof(char) * (src_size + 1));
	ft_strlcpy(str_dest, s, src_size + 1);
	return (str_dest);
}
