/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode_addr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:42:44 by rroussel          #+#    #+#             */
/*   Updated: 2023/04/06 10:42:47 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelnode_by_address(
	t_list **head, t_list *to_delete, void (*del)(void *))
{
	t_list	*current;
	t_list	*previous;

	if (!head || !*head)
		return ;
	current = *head;
	if (current == to_delete)
	{
		*head = current->next;
		ft_lstdelone(current, del);
		return ;
	}
	previous = current;
	current = current->next;
	while (current != NULL)
	{
		if (current == to_delete)
		{
			previous->next = current->next;
			ft_lstdelone(current, del);
			return ;
		}
		previous = current;
		current = current->next;
	}
}
