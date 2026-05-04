/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:12:49 by esouhail          #+#    #+#             */
/*   Updated: 2026/05/04 13:10:44 by esouhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f');
}

static void	parse_sign(const char **s, double *sign)
{
	*sign = 1.0;
	if (**s == '+' || **s == '-')
	{
		if (**s == '-')
			*sign = -1.0;
		++(*s);
	}
}

static int	parse_integer(const char **s, double *value)
{
	int		has_digit;

	has_digit = 0;
	while (ft_isdigit(**s))
	{
		*value = *value * 10.0 + (double)(**s - '0');
		++(*s);
		has_digit = 1;
	}
	return (has_digit);
}

static int	parse_fraction(const char **s, double *frac, double *divisor)
{
	int		has_digit;

	has_digit = 0;
	if (**s != '.')
		return (0);
	++(*s);
	while (ft_isdigit(**s))
	{
		*frac = *frac * 10.0 + (double)(**s - '0');
		*divisor *= 10.0;
		++(*s);
		has_digit = 1;
	}
	return (has_digit);
}

int	ft_atod(const char *s, double *out)
{
	double	value;
	double	frac;
	double	divisor;
	double	sign;
	int		has_digit;

	if (!s || !out)
		return (0);
	while (ft_isspace(*s))
		++s;
	value = 0.0;
	frac = 0.0;
	divisor = 1.0;
	has_digit = 0;
	parse_sign(&s, &sign);
	has_digit = parse_integer(&s, &value);
	if (parse_fraction(&s, &frac, &divisor))
		has_digit = 1;
	while (ft_isspace(*s))
		++s;
	if (*s != '\0' || !has_digit)
		return (0);
	*out = sign * (value + frac / divisor);
	return (1);
}
