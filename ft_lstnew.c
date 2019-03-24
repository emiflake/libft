#include "libft.h"

#include <stdlib.h>

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_list;
	
	new_list = (t_list*)malloc(sizeof(t_list));
	if (!new_list)
		return (0);
	if (!content)
	{
		new_list->content = 0;
		new_list->content_size = 0;
	}
	else
	{
		new_list->content = malloc(content_size);
		ft_memcpy(new_list->content, content, content_size);
		new_list->content_size = content_size;
	}
	return (new_list);
}
