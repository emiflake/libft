/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 13:28:47 by nmartins      #+#    #+#                 */
/*   Updated: 2019/03/21 13:35:17 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

# include <stdio.h>

char	*ft_strcat(char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i])
		i++;
	while (s2[i])
	{
		printf("#%d => %c\n", i, s2[i]);
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}
