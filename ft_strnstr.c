/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 18:40:00 by nmartins      #+#    #+#                 */
/*   Updated: 2019/03/20 18:40:40 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	char *is;
	char *js;
	char *lookback;

	is = (char*)haystack;
	while (*is)
	{
		lookback = is;
		js = (char*)needle;
		while (*is && *js && *is == *js)
		{
			is++;
			js++;
		}
		if (!*js)
			return (lookback);
		is = lookback + 1;
	}
	return (0);
}
