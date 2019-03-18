/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/26 15:29:41 by nmartins      #+#    #+#                 */
/*   Updated: 2019/02/26 17:43:11 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *source, int constant, size_t size)
{
	long unsigned int	counter;
	char				*src;
	
	src = source;
	counter = 0;
	if (!src)
		return (NULL);
	while (counter < size)
	{
		src[counter] = constant;
		counter++;
	}
	return (source);
}
