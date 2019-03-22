#include "libft.h"

char			*ft_strsub(
					char const *s,
					unsigned int start, size_t len)
{
	char *new;
	
	new = ft_strnew(len + 1);
	if (!new)
		return (0);
	ft_memcpy(new, &s[start], len);
	return (new);
}
