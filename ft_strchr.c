/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 17:59:01 by nmartins      #+#    #+#                 */
/*   Updated: 2019/03/20 18:07:17 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *haystack, int needle)
{
	char *walker;

	if (!haystack)
		return (0);
	walker = (char*)haystack;
	while (*walker)
	{
		if (*walker == needle)
			return (walker);
		walker++;
	}
	return (0);
}
