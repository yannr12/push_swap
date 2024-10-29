/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:12:57 by yrio              #+#    #+#             */
/*   Updated: 2024/01/10 15:47:32 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;

	if (!stack || !(*stack)->next)
		return ;
	tmp = ft_lstlast(*stack);
	tmp2 = *stack;
	tmp3 = ft_before_lstlast(stack);
	tmp -> next = tmp2;
	*stack = tmp;
	tmp3 -> next = NULL;
}

void	ft_rra(t_list **stack)
{
	ft_rrotate(stack);
	ft_printf("%s", "rra\n");
}

void	ft_rrb(t_list **stack)
{
	ft_rrotate(stack);
	ft_printf("%s", "rrb\n");
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
	ft_printf("%s", "rrr\n");
}
