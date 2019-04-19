#include "libft.h"

const char	*ft_globsearch(const char *orig, const char *pat)
{
	while (*orig)
	{
		if (ft_globmatch(orig, pat))
			return ((char*)orig);
		orig++;
	}
	return (NULL);
}
