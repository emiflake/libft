#include "libft.h"

#include <stdlib.h>

static char		*ft_str_take_while_neq(const char *source, char c)
{
	size_t	i;
	char	*out;

	i = 0;
	while (source[i] && c != source[i])
		i++;
	out = (char *)malloc(i + 1);
	ft_memcpy(out, source, i);
	return (out);
}

static size_t	ft_count_sections(char const *s, char c)
{
	size_t count;
	size_t i;

	count = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
		count++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**words;
	size_t	word_count;
	size_t	i;
	size_t	words_used;

	word_count = ft_count_sections(s, c);
	words = (char**)malloc(sizeof(char*) * (word_count + 1));
	i = 0;
	words_used = 0;
	while (words_used <= word_count)
	{
			while (s[i] == c && s[i])
				i++;
			words[words_used] = ft_str_take_while_neq(&s[i], c);
			words_used++;
			while (s[i] != c && s[i])
				i++;
			while (s[i] == c && s[i])
				i++;
	}
	words[words_used - 1] = 0;
	return (words);
}
