/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:32:19 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/05 19:39:52 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

		// pile a is used with indexes
		// we look for the maximum of bits to reprensent the biggest number
		// we through all a for each bit
		// we check the value pointed by head
		// we check if the bit is 0 (it means even number) and we push it to b
		// or we rotate a
		// once we checked the all list we push b in a
		
void	radix_sort(node **list_a, node **list_b, int size)
{
	int max;
	int max_bits;
	int i;
	int j;
	int num;

	max = find_max_index(*list_a);
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++; 

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = (*list_a)->nb;
			if (((num >> i) & 1) == 0)
				pb(list_a, list_b); 
			else
				ra(list_a); 
			j++;
		}
		while (*list_b != NULL)
			pa(list_a, list_b);
		i++;
	}
}


int	ft_select_algo(node **list_a, node **list_b, int a)
{
	if (ft_is_sorted(list_a, a))
		return (ft_printf("Already sorted\n"));
	else if (a == 3)
	{
		sort_three(list_a);
	}
	else if (a > 3 && a <= 6)
	{
		sort_five(list_a, list_b);
	}
	else
		radix_sort(list_a, list_b, a);
	return (0);
}



int	main(int a, char *v[])
{
	if (!check_params(a))
		return (1);
	if (str_nonly_dig(v) || is_long(v)) // check if the string has something else than digits
		return (1);
	int *tab = ft_store_intab(a, v);
	if (!tab)
		return (3);
	if (has_duplicates(tab, a - 1))
		return (2);
	int i = 0;
	
    node *list_a = NULL;
	node *list_b = NULL;
	
	int y = a - 2;
	while (i < a - 1)
	{
		// printf("tab[%i] %i\n", y, tab[y]);
		ft_appnode(tab[y], &list_a);
		i++;
		y--;
	}
	// ft_printf("list a : ");
	// print_list(list_a);


	node *tmp = list_a;
	ft_bubblesort(tab, a - 1);
	i = 0;
	while (tmp)
    {
        i = 0;
        while (i < a - 1) // look in the array for the position of tmp->nb
        {
            if (tmp->nb == tab[i])
                break;
            i++;
        }
        tmp->nb = i; // we change the value for the index
        tmp = tmp->next;
    }
	i = 0;
	
	// print_list(list_a);
	ft_select_algo(&list_a, &list_b, a - 1);
	tmp = list_a;
	while (tmp)
	{
		i = 0;
		while (i < a - 1)
		{
			if (tmp->nb == i)
				break;
			i++;
		}
		tmp->nb = tab[i];
		tmp = tmp->next;
		
	}
	free(tab);
	
	// ft_printf("list a : ");
	// print_list(list_a);
	
	// ft_printf("list b : ");
	// print_list(list_b);
	
	
	// sa(&list_a);
	// print_list(list_a);

	// sa(&list_a);
	// rra(&list_a);
	// print_list(list_a);
	
	// ft_printf("push a to be 3 times\n");
	// pb(&list_a, &list_b);
	// pb(&list_a, &list_b);
	// pb(&list_a, &list_b);
	
	// print_list(list_a);
	// print_list(list_b);

	// ft_printf("rotate list b\n");
	// rb(&list_b);
	// print_list(list_b);
	
	// ft_printf("reverse rotate list b\n");
	// rrb(&list_b);
	// print_list(list_b);
	
	ft_lstclear(&list_b);
	ft_lstclear(&list_a);	
	return (0);
}
