/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:40:31 by yrio              #+#    #+#             */
/*   Updated: 2024/01/10 15:47:41 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_make(t_list **stack, char **argv, int index)
{
	int			i;
	long int	value;
	char		**split_argv;
	t_list		*elem;

	split_argv = ft_split(argv[index], ' ');
	i = 0;
	while (split_argv[i])
	{
		if (ft_isdigit(split_argv[i]) == 1)
		{
			value = ft_atoi(split_argv[i]);
			if (value > INT_MAX || value < INT_MIN)
				return (ft_free(split_argv));
			elem = ft_lstnew((int)value);
			if (!elem)
				return (ft_free(split_argv));
			ft_lstadd_back(stack, elem);
		}
		else
			return (ft_free(split_argv));
		i++;
	}
	ft_free(split_argv);
	return (1);
}

int	parsing(int argc, char **argv, t_list **stack)
{
	int		index;
	int		value;

	index = 1;
	while (index < argc)
	{
		value = lst_make(stack, argv, index);
		if (value == 0)
			return (0);
		index++;
	}
	if (ft_lstsize(*stack) < 1 || ft_check_duplicate(stack) == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack;

	stack = NULL;
	if (argc > 1)
	{
		if (parsing(argc, argv, &stack) == 1)
			ft_optimal_sort(&stack);
		else
		{
			ft_lstclear(&stack);
			write(2, &"Error\n", 6);
			return (0);
		}
		ft_lstclear(&stack);
	}
	return (0);
}
