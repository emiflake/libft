#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	while (lst)
	{
		ft_lstadd(&new, f(lst));
		lst = lst->next;
	}
	return (new);
}
