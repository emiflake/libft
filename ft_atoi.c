/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 19:02:14 by nmartins      #+#    #+#                 */
/*   Updated: 2019/03/23 16:32:46 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h>

int		ft_atoi(const char *str)
{
	long long result;
	int mag;

	result = 0;
	mag = 1;
	while (ft_iswhite(*str) || *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		mag = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (result > INT_MAX || result < INT_MIN)
			return (-1);
		result = result * 10 + (*str - '0');
		str++;
		steps++;
	}
	return (mag * result);
}
