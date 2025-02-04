/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:54:07 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/04 19:26:56 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	sa(node **head_a)
{
	node	*first;
	node	*second;

	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	first = *head_a;
	second = (*head_a)->next;
	first->next = second->next;
	second->next = *head_a;
	*head_a = second;
	ft_printf("sa\n");
}

void	sb(node **head_b)
{
	node	*first;
	node	*second;

	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	first = *head_b;
	second = (*head_b)->next;
	first->next = second->next;
	second->next = *head_b;
	*head_b = second;
	ft_printf("sb\n");
}

void	ss(node **head_a, node **head_b)
{
	sa(head_a);
	sb(head_b);
	ft_printf("ss\n");
}
