/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:57:46 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/04 18:34:24 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*3 elements mini
case 1 : [2, 1, 3] => c > a & a > b
case 2 : [3, 2, 1] => a > b & b > c
case 3 : [3, 1, 2] => a > c & c > b
case 4 : [1, 3, 2] => b > c & c > a
case 5 : [2, 3, 1] => b > a & a > c*/

void	sort_three(node **head_a)
{
	int	a;
	int	b;
	int	c;

	if (!(*head_a) || !((*head_a)->next) || !((*head_a)->next->next))
		return ;
	a = (*head_a)->nb;
	b = (*head_a)->next->nb;
	c = (*head_a)->next->next->nb;
	if (a > b && c > a)
		return (sa(head_a));
	else if (a > b && b > c)
		return (sa(head_a), rra(head_a));
	else if (a > c && c > b)
		return (ra(head_a));
	else if (b > c && c > a)
		return (sa(head_a), ra(head_a));
	else if (b > a && a > c)
		return (rra(head_a));
}

static void	helper_sort_five(node **list_a, node **list_b)
{
	node	*min;
	int		count;

	min = find_min_node((*list_a));
	while (ft_nodelsize((*list_a)) > 3)
	{
		count = ft_node_index((*list_a), min);
		if (count > 3)
		{
			while ((*list_a) != min)
				rra(list_a);
			pb(list_a, list_b);
			min = find_min_node((*list_a));
		}
		else
		{
			while ((*list_a) != min)
				ra(list_a);
			pb(list_a, list_b);
			min = find_min_node((*list_a));
		}
	}
}

void	sort_five(node **list_a, node **list_b)
{
	helper_sort_five(list_a, list_b);
	sort_three(list_a);
	pa(list_a, list_b);
	pa(list_a, list_b);
	return ;
}

int	ft_is_sorted(node **list, int a)
{
	node	*ptr;
	int		count;

	count = 0;
	ptr = *list;
	while (ptr->next != NULL)
	{
		if (ptr->nb < ptr->next->nb)
			count++;
		if (count == a - 1)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
