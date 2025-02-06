/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:32:19 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/06 19:21:23 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
/*
	pile a is used with indexes
	we look for the maximum of bits to reprensent the biggest number
	we through all a for each bit
	we check the value pointed by head
	we check if the bit is 0 (it means even number) and we push it to b
	or we rotate a
	once we checked the all list we push b in a
*/
void	radix_sort(node **list_a, node **list_b, int size)
{
	int	max;
	int	max_bits;
	int	i;
	int	j;
	int	num;

	max = find_max_index(*list_a);
	max_bits = 0;
	i = -1;
	while ((max >> max_bits) != 0)
		max_bits++;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			num = (*list_a)->nb;
			if (((num >> i) & 1) == 0)
				pb(list_a, list_b);
			else
				ra(list_a);
		}
		while (*list_b != NULL)
			pa(list_a, list_b);
	}
}

int	ft_select_algo(node **list_a, node **list_b, int a)
{
	if (ft_is_sorted(list_a, a))
		return (ft_printf("Already sorted\n"));
	else if (a == 2)
	{
		sort_two(list_a);
	}
	else if (a == 3)
	{
		sort_three(list_a);
	}
	else if (a > 3 && a <= 32)
	{
		sort_five(list_a, list_b);
	}
	else
		radix_sort(list_a, list_b, a);
	return (0);
}

/*
	Used to work with indexes to handle negative values
*/
void	index_tab(node **list_a, int a, int *tab)
{
	node	*tmp;
	int		i;

	i = 0;
	tmp = (*list_a);
	ft_bubblesort(tab, a - 1);
	while (tmp)
	{
		i = 0;
		while (i < a - 1)
		{
			if (tmp->nb == tab[i])
				break ;
			i++;
		}
		tmp->nb = i;
		tmp = tmp->next;
	}
}

int	main(int a, char *v[])
{
	int		*tab;
	node	*list_a;
	node	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (!check_params(a) || str_nonly_dig(v) || is_long(v))
		return (1);
	tab = ft_store_intab(a, v);
	if (!tab)
		return (2);
	if (has_duplicates(tab, a - 1))
		return (3);
	add_node(a, &list_a, tab);
	index_tab(&list_a, a, tab);
	ft_select_algo(&list_a, &list_b, a - 1);
	free(tab);
	ft_lstclear(&list_b);
	ft_lstclear(&list_a);
	return (0);
}

	// while (++i < a - 1)
	// {
	// 	ft_appnode(tab[y], &list_a, tab);
	// 	y--;
	// }