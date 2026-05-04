/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:16:58 by esouhail          #+#    #+#             */
/*   Updated: 2025/06/13 14:32:15 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num[10];
	int		i;
	int		temp;

	i = 0;
	if (n < 0)
		ft_putchar_fd('-', fd);
	else if (n == 0)
		ft_putchar_fd('0', fd);
	while (n != 0)
	{
		temp = n % 10;
		if (temp < 0)
			temp = -temp;
		num[i] = '0' + temp;
		n /= 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar_fd(num[i], fd);
}

/*
int	main(int ac, char **av)
{
	ft_putnbr_fd(ft_atoi(av[ac-1]), 1);
}
*/
