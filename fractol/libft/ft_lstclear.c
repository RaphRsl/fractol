/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:43:54 by rroussel          #+#    #+#             */
/*   Updated: 2022/11/10 14:35:06 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*addr;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		addr = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = addr;
	}
}
