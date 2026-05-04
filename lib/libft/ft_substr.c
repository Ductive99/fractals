/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:18:29 by esouhail          #+#    #+#             */
/*   Updated: 2025/06/13 15:02:28 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	size_t			size;
	unsigned int	i;

	i = 0;
	size = ft_strlen(s);
	if (start >= size)
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	while (start + i < size && i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

/*
int	main(int ac, char **av)
{
	char *str = ft_substr(av[1], atoi(av[2]), atoi(av[ac-1])); 
	printf("%s", str);
}
*/
