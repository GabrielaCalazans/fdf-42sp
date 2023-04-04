/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:42:34 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/13 20:19:25 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int argument)
{
	if (argument >= 'a' && argument <= 'z')
		return (1);
	if (argument >= 'A' && argument <= 'Z')
		return (2);
	else
		return (0);
}
