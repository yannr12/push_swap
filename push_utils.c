/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:16:51 by yrio              #+#    #+#             */
/*   Updated: 2024/01/10 15:47:38 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **stack_dest, t_list **stack_src)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*stack_src == NULL)
		return ;
	tmp = *stack_src;
	*stack_src = tmp -> next;
	tmp2 = *stack_dest;
	tmp -> next = tmp2;
	*stack_dest = tmp;
}

void	ft_pa(t_list **stack_dest, t_list **stack_src)
{
	ft_push(stack_dest, stack_src);
	ft_printf("%s", "pa\n");
}

void	ft_pb(t_list **stack_dest, t_list **stack_src)
{
	ft_push(stack_dest, stack_src);
	ft_printf("%s", "pb\n");
}
