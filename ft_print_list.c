/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:28:38 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/02 23:28:50 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	print_list(node *list)
{
    while (list)
    {
        ft_printf("%d -> ", list->nb);
        list = list->next;
    }
    ft_printf("NULL\n");
}