#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= ((1 << 7) - 1));
}
