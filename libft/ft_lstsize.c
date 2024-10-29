/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:42:33 by rroussel          #+#    #+#             */
/*   Updated: 2022/11/09 19:58:28 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		nb_nodes;
	t_list	*curr_addr;

	nb_nodes = 0;
	curr_addr = lst;
	while (curr_addr)
	{
		curr_addr = curr_addr->next;
		nb_nodes++;
	}
	return (nb_nodes);
}
