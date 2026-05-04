/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:14:47 by esouhail          #+#    #+#             */
/*   Updated: 2026/05/03 17:33:31 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits(int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = count_digits(n);
	if (n < 0)
		len++;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	while (n != 0 && --len >= 0)
	{
		if (n % 10 < 0)
			str[len] = - (n % 10) + '0';
		else
			str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

int	count_digits(int n)
{
	int	digits;

	if (n == 0)
		return (1);
	digits = 0;
	while (++digits && n != 0)
		n /= 10;
	return (digits - 1);
}

/*
int	main(int ac, char **av)
{
	char *str = ft_itoa(ft_atoi(av[ac-1]));
	printf("%d\n", count_digits(ft_atoi(av[ac-1])));
	printf(">%s<\n", str);
	free(str);
}
*/
