/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:32:04 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/04 18:40:39 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ft_appnode(int n, node **list)
{
	node	*new_node;
	node	*ptr;

	new_node = malloc(sizeof(node));
	if (!new_node)
		return ;
	new_node->nb = n;
	new_node->next = NULL;
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	ptr = *list;
	while (ptr != NULL)
	{
		if (ptr->next == NULL)
		{
			ptr->next = new_node;
			break ;
		}
		ptr = ptr->next;
	}
}
