/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/26 15:29:41 by nmartins      #+#    #+#                 */
/*   Updated: 2019/03/22 16:17:21 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

/*
** Section libc
*/

void			*ft_memset(void *source, int constant, size_t size);
void			ft_bzero(void *ptr, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n); // TODO
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(char *str);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
size_t			ft_strlcat(
					char *dst,
					const char *src,
					size_t size); // TODO: wtf
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *haystack, int needle);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
** Section extra
*/

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(
					char const *s,
					char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(
					char const *s,
					unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** Section lists
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size); // TODO
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t)); // TODO
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t)); // TODO
void			ft_lstadd(t_list **alst, t_list *new); // TODO
void			ft_listiter(t_list *lst, void (*f)(t_list *elem)); // TODO
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem)); // TODO

/*
** Section stack
*/

typedef struct	s_stack
{
	void			*content;
	struct s_stack	*next;
}				t_stack;

void			ft_push(t_stack **stack, void const *content); // TODO
void			*ft_pop(t_stack **stack); // TODO

/*
** (Optional) Section hashmaps
*/

// TODO

/*
** Section personal
*/

char			*ft_strtoup(char *str);
char			*ft_strtolo(char *str);
char			*ft_str_take_while(const char *source, int (*f)(int));
char			*ft_str_drop_while(const char *source, int (*f)(int));
int				ft_iswhite(int c);
void			ft_print_memory(void *addr, size_t size); // TODO
int				ft_atoi_base_i(char *str, int base); // TODO
int				ft_atoi_base_s(char *str, char *base); // TODO
char			*ft_itoa_base_i(int n, int base); // TODO
char			*ft_itoa_base_s(int n, char *base); // TODO
size_t			ft_strchrcount(const char *str, char search);
char			*ft_strrev(char *str);
void			*ft_realloc(
					void *mem,
					size_t s_len,
					size_t n_len);


void			*ft_foldr1(
					t_list *lst,
					void *(*reductor(void *, size_t, void*))); // TODO
#endif
