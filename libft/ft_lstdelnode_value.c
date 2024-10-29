/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:44:39 by rroussel          #+#    #+#             */
/*   Updated: 2023/04/06 10:45:06 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelnode_by_value(
	t_list **head, void *content, void (*del)(void *))
{
	t_list	*current;
	t_list	*previous;

	if (!head || !*head)
		return ;
	current = *head;
	if (current->content == content)
	{
		*head = current->next;
		ft_lstdelone(current, del);
		return ;
	}
	previous = current;
	current = current->next;
	while (current != NULL)
	{
		if (current->content == content)
		{
			previous->next = current->next;
			ft_lstdelone(current, del);
			return ;
		}
		previous = current;
		current = current->next;
	}
}
