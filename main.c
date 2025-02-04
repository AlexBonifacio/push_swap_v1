/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:32:19 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/04 11:51:21 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

static int check_params(int a)
{
	if (a == 1)
	{
		ft_printf("Use it as follow: ./push_swap int int\n");
		return (0);
	}
	return (1);
}

int str_nonly_dig(char *v[])
{
	size_t	i;
	size_t	y;

	i = 1;
	y = 0;
	ft_printf("Checking args\n");
	while (v[i])
	{
		y = 0;
		if (v[i][y] == '-')
			y++;
		while (v[i][y])
		{
			// ft_printf("v[%u][%u] %c || ", i, y, v[i][y]);
			if (!ft_isdigit(v[i][y]))
			{
				ft_printf("Error no alpha tolerated\n");
				return (1);
			}
			y++;
		}
		i++;
	}
	ft_printf("Args are ok\n");
	return (0);
}

int	is_long(char *v[])
{
	size_t	i;

	i = 1;
	while (v[i])
	{
		if (ft_strlen(v[i]) > 11)
		{
			ft_printf("Error bigger than int\n");
			return (1);
		}
		if (ft_atol(v[i]) > 2147483647 || ft_atol(v[i]) < -2147483648)
		{
			ft_printf("Error bigger than int\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int *store(int a, char *v[])
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

int has_duplicates(int *arr, int size) 
{
    int	i; 
	int	j;

	i = 0;
    while (i < size) {
        j = i + 1;
        while (j < size) {
            if (arr[i] == arr[j]) 
			{
				ft_printf("Error duplicate number found\n");
                return (1); // duplicate found 
            }
            j++;
        }
        i++;
    }
    return (0); // no duplicate found
}

int	ft_is_sorted(node **list, int a)
{
	node *ptr;
	int	count;
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
    // Cas 1 : [2, 1, 3] => a > b et a < c
    // Cas 2 : [3, 2, 1] => a > b et b > c
    // Cas 3 : [3, 1, 2] => a > c et b < c
    // Cas 4 : [1, 3, 2] => a < b, a < c et b > c
    // Cas 5 : [2, 3, 1] => a < b et a > c

void sort_three(node **head_a)
{
    int a, b, c;

    if (!(*head_a) || !((*head_a)->next) || !((*head_a)->next->next))
        return ; // 3 elements mini
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

node *find_min_node(node *list)
{
    node *min_node;

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
	int pos;
	
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

void	sort_two_reverse(node **list)
{
	int	a;
	int	b;
	
	a = (*list)->nb;
	b = (*list)->next->nb;

	if (a < b)
		return (sb(list));
}

void	sort_five(node **list_a, node **list_b)
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
	sort_three(list_a);
	pa(list_a, list_b);
	pa(list_a, list_b);
	return ;
}




int	find_max_index(node *list)
{
	int max;

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

void	radix_sort(node **list_a, node **list_b, int size)
{
	int max;
	int max_bits;
	int i;
	int j;
	int num;

	// On part du principe que ta pile A contient des indices allant de 0 à size - 1
	max = find_max_index(*list_a);
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++; // # Résultat attendu : nombre de bits nécessaire pour représenter max

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		// Pour chaque passe, on parcourt tous les éléments de la pile A
		while (j < size)
		{
			// Récupération de la valeur (l'indice) en tête de pile A
			num = (*list_a)->nb;
			// Vérifie le bit i de num : s'il est 0, on le pousse dans B, sinon on fait une rotation sur A
			if (((num >> i) & 1) == 0)
				pb(list_a, list_b); // # Résultat attendu : l'élément est déplacé dans la pile B
			else
				ra(list_a); // # Résultat attendu : la pile A est tournée
			j++;
		}
		// Récupère tous les éléments de la pile B dans A
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
	else if (a > 3 && a <= 5)
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
	int *tab = store(a, v);
	if (!tab)
		return (3);
	if (has_duplicates(tab, a - 1))
		return (2);
	int i = 0;
	
    node *list_a = NULL;
	node *list_b = NULL;
	
	while (i < a - 1)
	{
		printf("tab[%i] %i\n", i, tab[i]);
		ft_appnode(tab[i], &list_a);
		i++;
	}
	free(tab);
	
	print_list(list_a);
	ft_select_algo(&list_a, &list_b, a - 1);
	
	ft_printf("list a : ");
	print_list(list_a);
	ft_printf("list b : ");

	print_list(list_b);
	
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
	
	// ft_lstclear(&list_b);
	// ft_lstclear(&list_a);	
	return (0);
}
