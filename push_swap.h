/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:32:47 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/04 19:15:04 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

void	print_list(node *list);
void	ft_appnode(int n, node **list);
void	ft_lstclear(node **lst);
void	ft_lstdelone(node *lst, void (*del)(void *));

void	sa(node **head_a);
void	sb(node **head_b);
void	pa(node **head_a, node **head_b);
void	pb(node **head_a, node **head_b);
void	ra(node **head_a);
void	rb(node **head_b);
void	rra(node **head_a);
void	rrb(node **head_b);

void	ft_bubblesort(int *tab, int tab_size);
int		find_max_index(node *list);
node	*find_min_node(node *list);
int		ft_node_index(node *list, node *lf_node);
int		*ft_store_intab(int a, char *v[]);

void	sort_three(node **head_a);
void	sort_five(node **list_a, node **list_b);
int		ft_is_sorted(node **list, int a);
int		has_duplicates(int *arr, int size);
int		is_long(char *v[]);
int		str_nonly_dig(char *v[]);
int		check_params(int a);


#endif