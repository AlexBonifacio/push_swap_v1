/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:48:53 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/03 00:17:35 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <malloc.h>

void	del(void *ptr)
{
	free(ptr);
}

void ft_lstdelone(node *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	free(lst);
}