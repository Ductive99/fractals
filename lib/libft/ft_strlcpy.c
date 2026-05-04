/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:33:35 by esouhail          #+#    #+#             */
/*   Updated: 2025/04/30 16:12:52 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	srclen;
	size_t	i;

	srclen = 0;
	i = 0;
	while (src[srclen])
		srclen++;
	if (dsize == 0)
		return (srclen);
	while (src[i] && i < dsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

/*
int	main(int ac, char **av)
{
	char dst1[15]; 
	int res1= strlcpy(dst1, av[ac-1], ft_atoi(av[1]));
	char dst2[15];
	int res2= ft_strlcpy(dst2, av[ac-1], ft_atoi(av[1]));

	printf("%d -> %s\n", res1, dst1);
	printf("%d -> %s\n", res2, dst2);
}
*/
