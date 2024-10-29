/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:24:08 by yrio              #+#    #+#             */
/*   Updated: 2024/01/10 15:47:30 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_list **stack)
{
	int		top;
	int		middle;
	int		bottom;

	top = (*stack)-> content;
	middle = (*stack)-> next -> content;
	bottom = (*stack)-> next -> next -> content;
	if (top > middle && middle < bottom && top < bottom)
		ft_sa(stack);
	else if (top > middle && middle > bottom && top > bottom)
	{
		ft_sa(stack);
		ft_rra(stack);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ft_ra(stack);
	else if (top < middle && middle > bottom && top < bottom)
	{
		ft_sa(stack);
		ft_ra(stack);
	}
	else if (top < middle && middle > bottom && top > bottom)
		ft_rra(stack);
}

void	ft_push_best_stackb(t_list **stack_src, t_list **stack_dest)
{
	t_list	*tmp;
	t_list	*best_elem;

	tmp = *stack_src;
	best_elem = tmp;
	ft_compute_position(stack_src);
	ft_compute_position(stack_dest);
	while (tmp)
	{
		ft_compute_target_stackb(stack_dest, tmp);
		ft_compute_cout(tmp, stack_dest);
		if (tmp->best_direction == 1 || tmp->best_direction == 2)
			if (ft_number_upper(tmp->couta, tmp->coutb) < \
				ft_number_upper(best_elem->couta, best_elem->coutb))
				best_elem = tmp;
		if (tmp->best_direction == 3 || tmp->best_direction == 4)
			if (tmp->couta + tmp->coutb < best_elem->couta + best_elem->coutb)
				best_elem = tmp;
		tmp = tmp -> next;
	}
	ft_apply_best_rotate(best_elem, stack_src, stack_dest);
	ft_pb(stack_dest, stack_src);
}

void	ft_push_best_stacka(t_list **stack_src, t_list **stack_dest)
{
	t_list	*tmp;
	t_list	*best_elem;

	tmp = *stack_src;
	best_elem = tmp;
	ft_compute_position(stack_src);
	ft_compute_position(stack_dest);
	while (tmp)
	{	
		ft_compute_target_stacka(stack_dest, tmp);
		ft_compute_cout(tmp, stack_dest);
		if (tmp->best_direction == 1 || tmp->best_direction == 2)
			if (ft_number_upper(tmp->couta, tmp->coutb) < \
				ft_number_upper(best_elem->couta, best_elem->coutb))
				best_elem = tmp;
		if (tmp->best_direction == 3 || tmp->best_direction == 4)
			if (tmp->couta + tmp->coutb < best_elem->couta + best_elem->coutb)
				best_elem = tmp;
		tmp = tmp -> next;
	}
	ft_apply_best_rotate2(best_elem, stack_src, stack_dest);
	ft_pa(stack_dest, stack_src);
}

void	ft_sort(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	ft_pb(&stack_b, stack_a);
	if (ft_lstsize(*stack_a) > 3)
		ft_pb(&stack_b, stack_a);
	while (ft_lstsize(*stack_a) > 3)
		ft_push_best_stackb(stack_a, &stack_b);
	ft_sort_three(stack_a);
	while (ft_lstsize(stack_b) > 0)
		ft_push_best_stacka(&stack_b, stack_a);
	ft_min_top(stack_a);
	ft_lstclear(&stack_b);
}

void	ft_optimal_sort(t_list **stack)
{
	if (check_sorted(*stack) == 1)
		return ;
	if (ft_lstsize(*stack) == 2)
		ft_printf("%s", "sa\n");
	else if (ft_lstsize(*stack) == 3)
		ft_sort_three(stack);
	else
		ft_sort(stack);
}
