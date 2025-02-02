/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:32:47 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/03 00:17:47 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct node
{
	int nb;
	struct node *next;
} node;

void	print_list(node *list);
void	ft_appnode(int n, node **list);
void	ft_lstclear(node **lst);
void	ft_lstdelone(node *lst, void (*del)(void *));



#endif