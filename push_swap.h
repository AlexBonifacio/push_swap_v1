/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:32:47 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/03 11:51:56 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
typedef struct node
{
	int nb;
	struct node *next;
} node;

void	print_list(node *list);
void	ft_appnode(int n, node **list);
void	ft_lstclear(node **lst);
void	ft_lstdelone(node *lst, void (*del)(void *));

void	sa(node **head_a);
void	sb(node **head_b);
void	pa(node **head_a, node **head_b);
void	pb(node **head_a, node **head_b);


#endif