#include "libft.h"

#define HEX(i) (i <= 9 ? '0' + i : 'a' - 10 + i)

static void puthex(unsigned char c)
{
	char fst;
	char snd;

	fst = HEX(c / 16);
	snd = HEX(c % 16);
	ft_putchar(fst);
	ft_putchar(snd);
}

static void putchars(char *chars, size_t starting_at, size_t len)
{
	size_t i;

	i = 0;
	while (starting_at + i < len && i < 16)
	{
		if (ft_isprint(chars[i + starting_at]))
			ft_putchar(chars[i + starting_at]);
		else	
			ft_putchar('.');
		i++;
	}
}

void ft_print_memory(void *addr, size_t len)
{
	char	*bytes;
	size_t	line;
	size_t	byte_i;

	bytes = addr;
	line = 0;
	while (line <= (len) / 16)
	{
		byte_i = 0;
		while (byte_i < 16)
		{
			if (byte_i < len - (line * 16))
				puthex(bytes[byte_i + line * 16]);
			else
				ft_putstr("  ");
			if (byte_i % 4 == 3)
				ft_putchar(' ');
			byte_i++;
		}
		putchars(bytes, line * 16, len);
		ft_putchar('\n');
		line++;
	}
}
