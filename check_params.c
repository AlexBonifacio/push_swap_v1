/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:35:38 by abonifac          #+#    #+#             */
/*   Updated: 2025/02/04 19:16:53 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_params(int a)
{
	if (a == 1)
	{
		return (0);
	}
	return (1);
}

int	is_long(char *v[])
{
	size_t	i;

	i = 1;
	while (v[i])
	{
		if (ft_strlen(v[i]) > 11)
		{
			ft_printf("Error\n");
			return (1);
		}
		if (ft_atol(v[i]) > 2147483647 || ft_atol(v[i]) < -2147483648)
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	str_nonly_dig(char *v[])
{
	size_t	i;
	size_t	y;

	i = 1;
	y = 0;
	while (v[i])
	{
		y = 0;
		if (v[i][y] == '-')
			y++;
		while (v[i][y])
		{
			if (!ft_isdigit(v[i][y]))
			{
				ft_printf("Error\n");
				return (1);
			}
			y++;
		}
		i++;
	}
	return (0);
}

int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				ft_printf("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
