/* ************************************************************************** */
/*                                                                            */
/*                                                              ::::::::      */
/*   ft_lstmap.c                                              :+:    :+:      */
/*                                                           +:+              */
/*   By: nmartins <nmartins@student.codam.nl>               +#+               */
/*                                                         +#+                */
/*   Created: 2019/03/25 13:16:37 by nmartins            #+#    #+#           */
/*   Updated: 2019/03/25 13:16:38 by nmartins            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

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
