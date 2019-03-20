/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/26 15:29:41 by nmartins      #+#    #+#                 */
/*   Updated: 2019/02/26 17:43:11 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *out;

	out = malloc(size);
	ft_bzero(out, size);
	return (out);
}
