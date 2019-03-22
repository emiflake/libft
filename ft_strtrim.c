#include "libft.h"

char			*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*out;

	if (!s)
		return (0);
	start = 0;
	end = ft_strlen(s) - 1;
	while (ft_iswhite(s[start]))
		start++;
	while (ft_iswhite(s[end]))
		end--;
	end++;
	if (end < start)
		return (ft_strnew(1));
	out = ft_strnew(end - start + 1);
	ft_memcpy(out, &s[start], end - start);
	out[end - start] = '\0';
	return (out);
}
