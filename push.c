/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:24:05 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/04 19:23:10 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
	if the pile is empty do nothing
	points head_b to the next value of pile b
*/
void	pa(node **head_a, node **head_b)
{
	node	*first_b;

	if (*head_b == NULL)
		return ;
	first_b = *head_b;
	*head_b = (*head_b)->next;
	first_b->next = *head_a;
	*head_a = first_b;
	ft_printf("pa\n");
}

void	pb(node **head_a, node **head_b)
{
	node	*first_a;

	if (*head_a == NULL)
		return ;
	first_a = *head_a;
	*head_a = (*head_a)->next;
	first_a->next = (*head_b);
	*head_b = first_a;
	ft_printf("pb\n");
}
