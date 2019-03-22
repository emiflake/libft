/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/26 15:29:41 by nmartins      #+#    #+#                 */
/*   Updated: 2019/03/19 18:15:18 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		counter;
	const char	*s;
	char		*d;

	s = src;
	d = dest;
	counter = 0;
	if (!dest || !src)
		return (NULL);
	while (counter < n - 1 && s[counter] != c)
	{
		d[counter] = s[counter];
		counter++;
	}
	d[counter] = s[counter];
	if (d[counter] == c)
		return (dest + counter + 1);
	else
		return (0);
}
