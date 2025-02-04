/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:28:43 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/04 19:24:24 by abonifac         ###   ########.fr       */
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

void	ra(node **head_a)
{
	node	*tmp;
	node	*last;

	if (*head_a == NULL || ((*head_a)->next) == NULL)
		return ;
	last = *head_a;
	last = ft_lflast(last);
	last->next = (*head_a);
	tmp = (*head_a);
	(*head_a) = (*head_a)->next;
	tmp->next = NULL;
	ft_printf("ra\n");
}

void	rb(node **head_b)
{
	node	*tmp;
	node	*last;

	if (*head_b == NULL || ((*head_b)->next) == NULL)
		return ;
	last = *head_b;
	last = ft_lflast(last);
	last->next = (*head_b);
	tmp = (*head_b);
	(*head_b) = (*head_b)->next;
	tmp->next = NULL;
	ft_printf("rb\n");
}

void	rr(node **head_a, node **head_b)
{
	ra(head_a);
	rb(head_b);
	ft_printf("rr\n");
}
