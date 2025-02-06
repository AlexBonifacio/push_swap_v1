/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:32:04 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/06 19:25:41 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	add_node(int a, node **list_a, int *tab)
{
	int	i;
	int	y;

	y = a - 2;
	i = -1;
	while (++i < a - 1)
	{
		ft_appnode(tab[y], list_a, tab);
		y--;
	}
}

void	ft_appnode(int n, node **list, int *tab)
{
	node	*new_node;
	

	new_node = malloc(sizeof(node));
	if (!new_node || !list)
	{
		free(tab);
		ft_lstclear(list);
		exit(EXIT_FAILURE);
	}
	new_node->nb = n;
	new_node->next = *list;
	*list = new_node;

}

// void	ft_appnode(int n, node **list, int *tab)
// {
// 	node	*new_node;
// 	int		i;
// 	int		size;
	
// 	n = 0;
// 	size = sizeof(*tab) / sizeof(int);
// 	i = -1;
// 	while (++i < size)
// 	{
// 		new_node = malloc(sizeof(node));
// 		if (!new_node || !list)
// 		{
// 			free(tab);
// 			ft_lstclear(list);
// 			exit(EXIT_FAILURE);
// 		}
// 		new_node->nb = tab[size];
// 		new_node->next = *list;
// 		*list = new_node;
// 		size--;
// 	}

// }