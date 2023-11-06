/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:43:12 by rroussel          #+#    #+#             */
/*   Updated: 2022/11/10 14:50:06 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*adrr_tmp;

	if (*lst)
	{
		adrr_tmp = ft_lstlast(*lst);
		adrr_tmp->next = new;
	}
	else
		*lst = new;
}
