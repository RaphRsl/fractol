/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:45:55 by rroussel          #+#    #+#             */
/*   Updated: 2023/04/06 10:46:11 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstadd_sorted(
		t_list **lst, t_list *new, int (comp)(void *, void *))
{
	t_list	*current;

	if (!lst || !new || !comp)
		return ;
	if (*lst == NULL || comp((*lst)->content, new->content) > 0)
	{
		new->next = *lst;
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next && comp(current->next->content, new->content) < 0)
		current = current->next;
	new->next = current->next;
	current->next = new;
}

t_list	*ft_lstsort(
		t_list *lst, int (comp)(void *, void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*current;
	t_list	*new_node;

	if (!comp || !del)
		return (NULL);
	new_lst = NULL;
	current = lst;
	while (current != NULL)
	{
		new_node = ft_lstnew(current->content);
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_sorted(&new_lst, new_node, comp);
		current = current->next;
	}
	return (new_lst);
}
