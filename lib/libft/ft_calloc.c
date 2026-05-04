/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:21:49 by esouhail          #+#    #+#             */
/*   Updated: 2025/05/12 11:46:26 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*space;
	size_t			i;

	i = 0;
	if (nmemb != 0 && size > 2147483647 / nmemb)
		return (NULL);
	space = malloc(nmemb * size);
	if (!space)
		return (NULL);
	while (i < nmemb * size)
		space[i++] = 0;
	return (space);
}
