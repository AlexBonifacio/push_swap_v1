/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:26:06 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/04 18:33:19 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_max_index(node *list)
{
	int	max;

	if (!list)
		return (0);
	max = list->nb;
	while (list)
	{
		if (list->nb > max)
			max = list->nb;
		list = list->next;
	}
	return (max);
}

node	*find_min_node(node *list)
{
	node	*min_node;

	if (!list)
		return (NULL);
	min_node = list;
	while (list)
	{
		if (list->nb < min_node->nb)
			min_node = list;
		list = list->next;
	}
	return (min_node);
}

int	ft_node_index(node *list, node *lf_node)
{
	int	pos;

	pos = 1;
	if (!list || !lf_node)
		return (0);
	while (list != lf_node)
	{
		list = list->next;
		pos++;
	}
	return (pos);
}

int	*ft_store_intab(int a, char *v[])
{
	size_t	i;
	size_t	y;
	int		*tab;

	i = 1;
	y = 0;
	tab = malloc(sizeof(int) * (a - 1));
	if (!tab)
		return (NULL);
	while (v[i])
	{
		tab[y] = ft_atoi(v[i]);
		y++;
		i++;
	}
	return (tab);
}
