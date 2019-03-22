#include "libft.h"

#include <stdlib.h>

void			*ft_realloc(
					void *mem,
					size_t s_len,
					size_t n_len)
{
	void *out;

	if (!n_len)
		return (0);
	out = malloc(n_len);
	if (!out)
		return (0);
	ft_memcpy(out, mem, s_len > n_len ? n_len : s_len);
	free(mem);
	return (out);
}
