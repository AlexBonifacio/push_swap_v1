/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:35:21 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/03 18:24:37 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static node	*ft_lflast(node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

static	node *ft_ntlast(node *lst, node *last)
{
	if (!lst)
		return (NULL);
	while (lst->next !=  last)
	{
		lst = lst->next;
	}
	return (lst);
}

void	rra(node **head_a)
{
	node	*last;
	node	*ntlast;
	
	if (*head_a == NULL || ((*head_a)->next) == NULL)
		return ;
	last = ft_lflast(*head_a);
	ntlast = ft_ntlast(*head_a, last);
	last->next = (*head_a);
	(*head_a) = last;
	ntlast->next = NULL;
	ft_printf("rra\n");
}

void	rrb(node **head_b)
{
	node	*last;
	node	*ntlast;
	
	if (*head_b == NULL || ((*head_b)->next) == NULL)
		return ;
	last = ft_lflast(*head_b);
	ntlast = ft_ntlast(*head_b, last);
	last->next = (*head_b);
	(*head_b) = last;
	ntlast->next = NULL;
	ft_printf("rrb\n");

}

void	rrr(node **head_a, node **head_b)
{
	rra(head_a);
	rrb(head_b);
	ft_printf("rrr\n");

}