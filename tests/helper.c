/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 18:37:27 by nmartins      #+#    #+#                 */
/*   Updated: 2019/03/21 19:12:02 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_ptr(char *chr_ptr)
{
	ft_putchar(*chr_ptr);
}

void ft_make_upper(char *c)
{
	*c = ft_toupper(*c);
}

void ft_sponge(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = ft_toupper(*c);
	else
		*c = ft_tolower(*c);
}
