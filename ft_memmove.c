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
	void *tmp;
	void *res;

	tmp = malloc(n);
	ft_memcpy(tmp, src, n);
	res = ft_memcpy(dest, tmp, n);
	free(tmp);
	return (res);
}
