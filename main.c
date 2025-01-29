#include "libft.h"
#include <stdio.h>

int check_params(int a)
{
	if (a == 1)
	{
		ft_printf("Use it as follow: ./push_swap int int\n");
		return (1);
	}
	return (0);
}

int str_nodigit(char *string)
{
	size_t	i;
	
	i = 0;
	while (string[i])
	{
		if (ft_isdigit(string[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int a, char **v)
{

	v++;
	while (*v)
	{
		printf("%s", *v);
		if (str_nodigit(*v))
		{
			ft_printf("Only digits");
			return (1);
		}
		v++;
	}
	check_params(a);
	return (0);
}
