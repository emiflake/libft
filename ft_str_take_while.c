#include "libft.h"

#include <stdlib.h>

char	*ft_str_take_while(char *source, int (*f)(int))
{
	size_t	i;
	char	*out;

	i = 0;
	while (source[i] && f(source[i]))
		i++;
	out = (char *)malloc(i + 1);
	ft_memcpy(out, source, i);
	return (out);
}
