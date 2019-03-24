#include "libft.h"

#include <stdlib.h>

void ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *tmp;

	lst = *alst;
	while (lst)
	{
		del(lst->content, lst->content_size);
		tmp = lst->next;
		free(tmp);
		lst = tmp;
	}
	free(*alst);
	*alst = 0;
}
