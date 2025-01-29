/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonifac <abonifac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:32:19 by abonifac          #+#    #+#             */
/*   Updated: 2025/01/29 23:45:00 by abonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libft.h"
#include <stdio.h>


static int check_params(int a)
{
	if (a == 1)
	{
		ft_printf("Use it as follow: ./push_swap int int\n");
		return (1);
	}
	return (0);
}

int str_nonly_dig(char *v[])
{
	size_t	i;
	size_t	y;

	i = 1;
	y = 0;
	while (v[i])
	{
		y = 0;
		while (v[i][y])
		{
			printf("v[i][y] %c\n", v[i][y]);
			if (v[i][y] == '-')
				y++;
			if (!ft_isdigit(v[i][y]))
			{
				ft_printf("Error no alpha tolerated\n");
				return (1);
			}
			y++;
		}
		i++;
	}
	return (0);
}

int bigger_int(char *v[])
{
	size_t	i;
	size_t	y;

	i = 1;
	y = 0;
	while (v[i])
	{
		y = 0;
		while (v[i][y])
		{
			if (ft_strlen(v[i]) > 11)
			{
				ft_printf("Error bigger than int\n");
				return (1);
			}
			if (ft_atol(v[i]) > 2147483647 || ft_atol(v[i]) < -2147483648)
			{
				ft_printf("Error bigger than int\n");
				return (1);
			}
			y++;
		}
		i++;
	}
	return (0);
}
int	main(int a, char *v[])
{

	long r = ft_atol("922337203685477580");
	printf("atol %li\n", r);
	if (str_nonly_dig(v) || bigger_int(v)) // check if the string has something else than digits
		return (1);
	check_params(a);
	return (0);
}
