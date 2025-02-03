/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:32:19 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/03 12:25:58 by abonifac         ###   ########.fr       */
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
			ft_printf("v[%u][%u] %c || ", i, y, v[i][y]);
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
	
	sa(&list_a);
	print_list(list_a);
	
	pb(&list_a, &list_b);
	pb(&list_a, &list_b);
	pb(&list_a, &list_b);
	
	print_list(list_a);
	print_list(list_b);
	
	ft_lstclear(&list_a);	
	return (0);
}
