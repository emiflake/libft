/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/26 15:29:41 by nmartins      #+#    #+#                 */
/*   Updated: 2019/03/23 21:15:20 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

/*
** Same as ft_memcpy, but guarantees overlap protection
** through some simple checking for copy order.
** Use only if necessary.
*/

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
		return (ft_memrcpy(dest, src, n));
	else
		return (ft_memcpy(dest, src, n));
}
