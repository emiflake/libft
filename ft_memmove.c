/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/26 15:29:41 by nmartins      #+#    #+#                 */
/*   Updated: 2019/02/26 17:43:11 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*tmp;
	const char	*s;
	char		*d;
	size_t		count;

	s = src;
	d = dest;
	tmp = malloc(n);
	count = 0;
	while (count < n)
	{
		tmp[count] = s[count];
		count++;
	}
	count = 0;
	while (count < n)
	{
		d[count] = tmp[count];
		count++;
	}
	return (dest);
}
