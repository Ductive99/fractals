/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:09:42 by esouhail          #+#    #+#             */
/*   Updated: 2025/04/30 23:55:14 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	i;

	slen = 0;
	dlen = 0;
	i = 0;
	while (src[slen])
		slen++;
	while (dst[dlen])
		dlen++;
	if (dsize <= dlen)
		return (slen + dsize);
	while (src[i] && i < dsize - dlen - 1)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (slen + dlen);
}

/*
int	main(int ac, char **av)
{
	char dst1[15] = "Hello"; 
	int res1= strlcat(dst1, av[ac-1], ft_atoi(av[1]));
	char dst2[15] = "Hello";
	int res2= ft_strlcat(dst2, av[ac-1], ft_atoi(av[1]));

	printf("std: %d -> >%s<\n", res1, dst1);
	printf(" ft: %d -> >%s<\n", res2, dst2);
}
*/
