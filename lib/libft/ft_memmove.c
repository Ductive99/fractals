/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:06:54 by esouhail          #+#    #+#             */
/*   Updated: 2025/06/13 15:12:06 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;

	p_dest = dst;
	p_src = (unsigned char *)src;
	if (dst == src)
		return (dst);
	else if (dst < src)
		return (ft_memcpy(dst, src, len));
	while (len--)
		p_dest[len] = p_src[len];
	return (dst);
}
