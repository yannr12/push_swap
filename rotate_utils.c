/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:59:48 by yrio              #+#    #+#             */
/*   Updated: 2024/01/10 15:47:35 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!stack || !(*stack)->next)
		return ;
	tmp = *stack;
	tmp2 = ft_lstlast(*stack);
	tmp2 -> next = tmp;
	*stack = tmp -> next;
	tmp -> next = NULL;
}

void	ft_ra(t_list **stack)
{
	ft_rotate(stack);
	ft_printf("%s", "ra\n");
}

void	ft_rb(t_list **stack)
{
	ft_rotate(stack);
	ft_printf("%s", "rb\n");
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("%s", "rr\n");
}
