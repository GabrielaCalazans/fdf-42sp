/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:13:05 by gacalaza          #+#    #+#             */
/*   Updated: 2022/10/04 19:31:44 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ncount(long int i)
{
	int	count;

	count = 0;
	if (i == 0)
		count++;
	if (i < 0)
	{
		i *= -1;
		count++;
	}
	while (i > 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

static int	checksign(int n, char *str)
{
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_ncount(n);
	str = malloc(i * sizeof(char) + 1);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	n = checksign(n, str);
	str[i] = '\0';
	i -= 1;
	while (n > 0)
	{
		str[i--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
