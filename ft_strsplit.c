/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:26:13 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/04 14:11:04 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static int		word_count(const char *s, char c)
{
	if (s[0] == '\0')
		return (0);
	if (s[0] != c && (s[1] == c || s[1] == '\0'))
		return (word_count(s + 1, c) + 1);
	return (word_count(s + 1, c));
}

static int		char_index(const char *s, char c)
{
	char *char_ptr;

	char_ptr = ft_strchr(s, c);
	if (char_ptr == NULL)
		char_ptr = (char *)s + ft_strlen(s);
	return (char_ptr - s);
}

static void		ft_strsplit_c(char **words, const char *s, char c)
{
	int		section_len;

	if (*s == '\0')
		return ;
	if (*s == c)
		return (ft_strsplit_c(words, s + 1, c));
	section_len = char_index(s, c);
	*words = ft_strsub(s, 0, section_len);
	ft_strsplit_c(words + 1, s + section_len, c);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**words;

	words = (char **)ft_memalloc(sizeof(*words) * (word_count(s, c) + 1));
	if (words == NULL)
		return (NULL);
	ft_strsplit_c(words, s, c);
	return (words);
}
