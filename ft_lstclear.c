/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:59:19 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/04 19:20:29 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <malloc.h>

void	ft_lstclear(node **lst)
{
	node	*ptr;

	if (!*lst || !lst)
		return ;
	while (*lst != NULL)
	{
		ptr = *lst;
		*lst = (*lst)->next;
		free(ptr);
	}
	return ;
}
