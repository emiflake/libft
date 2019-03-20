#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'z')
		return (c + 32);
	else
		return (c - 32);
}
