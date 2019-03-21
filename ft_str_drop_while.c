#include "libft.h"

char	*ft_str_drop_while(char *source, int (*f)(int))
{
	size_t	i;

	if (!source)
		return (0);
	i = 0;
	while (source[i] && f(source[i]))
		i++;
	return (ft_strdup(&source[i]));
}
