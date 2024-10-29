/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:27:39 by yrio              #+#    #+#             */
/*   Updated: 2024/01/10 15:47:53 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(char *str)
{
	size_t	i;
	size_t	neg;
	size_t	result;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
				neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	if (neg)
		return (result *= neg);
	return ((long int)result);
}

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 45)
		i++;
	if (str[i] == 48 && str[i + 1] != 0)
		return (0);
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}

int	ft_number_upper(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

/*
int main(void)
{
	char	*str = "-3873";
	
	printf("%d", ft_isdigit(str));
	return (0);
}
*/
