#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t	slen1;
	size_t	slen2;
	char	*out;

	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	out = (char*)ft_strnew(slen1 + slen2 + 1);
	ft_memcpy(out, s1, slen1);
	ft_memcpy(&out[slen1], s2, slen2 + 1);
	return (out);
}
