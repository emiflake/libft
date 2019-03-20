/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/26 15:29:41 by nmartins      #+#    #+#                 */
/*   Updated: 2019/03/20 19:26:46 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

/*
** Section libc
*/

void	*ft_memset(void *source, int constant, size_t size);
void	ft_bzero(void *ptr, size_t n);
void	ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *str);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len); // TODO
char	*ft_strcat(char *s1, const char *s2); // TODO
char	*ft_strlcat(char *dst, const char *src, size_t size); // TODO
char	*ft_strncat(char *s1, const char *s2, size_t n); // TODO
char	*ft_strchr(const char *haystack, int needle);
char	*ft_strrchr(const char *s, int c); // TODO
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str); // TODO
int		ft_isalpha(int c); // TODO
int		ft_isdigit(int c); // TODO
int		ft_isalnum(int c); // TODO
int		ft_isascii(int c); // TODO
int		ft_isprint(int c); // TODO
int		ft_toupper(int c); // TODO
int		ft_tolower(int c); // TODO

/*
** Section extra
*/

void	*ft_memalloc(size_t size);
void	*ft_memdel(void **ap); // TODO
char	*ft_strnew(size_t size);
void	ft_strdel(char **as); // TODO
void	ft_strclr(char *s); // TODO
void	ft_striter(char *s, void (*f)(char *)); // TODO
void	ft_striteri(char *s, void (*f)(unsigned int, char *)); // TODO
char	*ft_strmap(char const *s, char (*f)(char)); // TODO
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char)); // TODO
int		ft_strequ(char const *s1, char const *s2); // TODO
int		ft_strnequ(char const *s1, char const *s2, size_t n); // TODO
char	*ft_strub(char const *s, unsigned int start, size_t len); // TODO
char	*ft_strjoin(char const *s1, char const *s2); // TODO
char	*ft_strtrim(char const *s); // TODO
char	**ft_strsplit(char const *s, char c); // TODO
char	*ft_itoa(int n); // TODO
void	ft_putchar(char c); // TODO
void	ft_putstr(char const *s); // TODO
void	ft_putendl(char const *s); // TODO
void	ft_putnbr(int n); // TODO
void	ft_putchar_fd(char c, int fd); // TODO
void	ft_putstr_fd(char const *s, int fd); // TODO
void	ft_putendl_fd(char const *s, int fd); // TODO
void	ft_putnbr_fd(int n, int fd); // TODO

/*
** Section lists
*/
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** Section personal
*/
void	*ft_take_while(void *source, int (*f)(void*)); // TODO
void	*ft_drop_while(void *source, int (*f)(void*)); // TODO
#endif
