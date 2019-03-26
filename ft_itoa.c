/* ************************************************************************** */
/*                                                                            */
/*                                                              ::::::::      */
/*   ft_itoa.c                                                :+:    :+:      */
/*                                                           +:+              */
/*   By: nmartins <nmartins@student.codam.nl>               +#+               */
/*                                                         +#+                */
/*   Created: 2019/03/25 16:57:48 by nmartins            #+#    #+#           */
/*   Updated: 2019/03/25 17:31:18 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <limits.h>

static int	number_size(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n / 10)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	long	long_n;
	char	*out;
	int		size;
	int		i;

	if (!(long_n = (long)n))
		return (ft_strdup("0"));
	size = number_size(long_n);
	out = (char*)malloc(sizeof(char) * (size + 1));
	if (!out)
		return (0);
	i = 0;
	if (long_n < 0)
	{
		out[i++] = '-';
		long_n = -long_n;
	}
	while (long_n > 0)
	{
		out[i++] = '0' + long_n % 10;
		long_n /= 10;
	}
	out[i] = '\0';
	ft_strrev(out[0] == '-' ? out + 1 : out);
	return (out);
}
