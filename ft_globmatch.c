#include "libft.h"

/*
** ft_globmatch()
** Checks if pattern can be found in file using * and %
**
** % => 1 of any character
** * => 0 or more of any character
** ? => 0 or 1 of any character
** ^ => 0 or more spaces
**
** "Hello,^*!"
**    |   |\ \
**    |   | \ \
**    |   |  \ \
**    |   |  |  \
**    v   v  v  v
** "Hello, world!"   => 1
** "Hello,world!!!" => 1
** "Hello, world..." => 0
** "Hi world"        => 0
*/
int			ft_globmatch(const char *orig, const char *pat)
{
	if (!*orig && !*pat)
		return (1);
	if (*orig && *pat && *orig == *pat)
		return (ft_globmatch(orig + 1, pat + 1));
	if (*orig && *pat && *pat == '^')
		return (ft_iswhite(*orig)
				? ft_globmatch(orig + 1, pat)
				: ft_globmatch(orig, pat + 1));
	if (*orig && *pat && *pat == '?')
		return (ft_globmatch(orig + 1, pat + 1) || ft_globmatch(orig, pat + 1));
	if (*orig && *pat && *pat == '*')
		return (ft_globmatch(orig, pat + 1) || ft_globmatch(orig + 1, pat));
	if (*orig && *pat && *pat == '%')
		return (ft_globmatch(orig + 1, pat + 1));
	if (!*orig && ft_strchr("*?^", *pat) != NULL)
		return (ft_globmatch(orig, pat + 1));
	return (0);
}

