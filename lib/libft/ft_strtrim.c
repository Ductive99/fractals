/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:19:14 by esouhail          #+#    #+#             */
/*   Updated: 2025/06/01 16:17:54 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_match(char c, char const *set)
{
	int	i;

	i = -1;
	if (c == 0)
		return (1);
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	len;
	size_t	i;

	if (!s1)
		return (NULL);
	while (*s1 && ft_match(*s1, set))
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && ft_match(s1[len - 1], set))
		len--;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (*s1 && i < len)
		new[i++] = *s1++;
	new[len] = '\0';
	return (new);
}
/*
int	main(int ac, char **av)
{
	char	s1[] = "  lorem \n ipsum \t dolor \n sit \t amet";
	char	*res;

	printf("%s\n", ft_strtrim(s1, " "));
	res = ft_strtrim(av[1], av[ac - 1]);
	printf(">%s<", res);
}
*/