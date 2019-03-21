/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 19:02:14 by nmartins      #+#    #+#                 */
/*   Updated: 2019/03/21 11:31:26 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int result;
	int mag;

	result = 0;
	mag = 1;
	while (ft_iswhite(*str))
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
		result = result * 10 + (*str - '0');
		str++;
	}
	return (mag * result);
}
