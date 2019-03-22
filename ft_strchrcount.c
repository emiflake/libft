#include "libft.h"

size_t			ft_strchrcount(const char *str, char search)
{
	size_t count;

	count = 0;
	while (*str)
		count += (*(str++) == search);
	return (count);
}
