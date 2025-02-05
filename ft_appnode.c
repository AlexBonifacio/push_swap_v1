/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:32:04 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/05 19:07:42 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ft_appnode(int n, node **list)
{
	node	*new_node;
	// node	*ptr;

	new_node = malloc(sizeof(node));
	if (!new_node || !list)
		return ;
	new_node->nb = n;
	new_node->next = *list;
	*list = new_node;
	// ptr = *list;
	// while (ptr != NULL)
	// {
	// 	if (ptr->next == NULL)
	// 	{
	// 		ptr->next = new_node;
	// 		break ;
	// 	}
	// 	ptr = ptr->next;
	// }

	// if (!new || !lst)
	// 	return ;
	// else
	// {
	// 	new->next = *lst;
	// 	*lst = new;
	// }
}
