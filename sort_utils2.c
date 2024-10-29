/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:11:42 by yrio              #+#    #+#             */
/*   Updated: 2024/01/10 15:47:27 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_inverse_stack_rotate(t_list *best_elem, t_list **stack_a, \
		t_list **stack_b, void (f)(t_list **), \
		void (g)(t_list **))
{
	while (best_elem->couta > 0)
	{
		f(stack_a);
		best_elem->couta = best_elem->couta - 1;
	}
	while (best_elem->coutb > 0)
	{
		g(stack_b);
		best_elem->coutb = best_elem->coutb - 1;
	}
}

void	ft_apply_rr(t_list *best_elem, t_list **stack_a, t_list **stack_b)
{
	while (best_elem->couta > 0 || best_elem->coutb > 0)
	{
		if (best_elem->couta > 0 && best_elem->coutb > 0)
		{
			ft_rr(stack_a, stack_b);
			best_elem->couta = best_elem->couta - 1;
			best_elem->coutb = best_elem->coutb - 1;
		}
		else if (best_elem->coutb == 0)
		{
			ft_ra(stack_a);
			best_elem->couta = best_elem->couta - 1;
		}
		else if (best_elem->couta == 0)
		{
			ft_rb(stack_b);
			best_elem->coutb = best_elem->coutb - 1;
		}
	}
}

void	ft_apply_rrr(t_list *best_elem, t_list **stack_a, t_list **stack_b)
{
	while (best_elem->couta > 0 || best_elem->coutb > 0)
	{
		if (best_elem->couta > 0 && best_elem->coutb > 0)
		{
			ft_rrr(stack_a, stack_b);
			best_elem->couta = best_elem->couta - 1;
			best_elem->coutb = best_elem->coutb - 1;
		}
		else if (best_elem->coutb == 0)
		{
			ft_rra(stack_a);
			best_elem->couta = best_elem->couta - 1;
		}
		else if (best_elem->couta == 0)
		{
			ft_rrb(stack_b);
			best_elem->coutb = best_elem->coutb - 1;
		}
	}
}

void	ft_apply_best_rotate(t_list *best_elem, t_list **stack_dest, \
		t_list **stack_src)
{
	if (best_elem->best_direction == 1)
		ft_apply_rr(best_elem, stack_dest, stack_src);
	if (best_elem->best_direction == 2)
		ft_apply_rrr(best_elem, stack_dest, stack_src);
	if (best_elem->best_direction == 3)
		ft_inverse_stack_rotate(best_elem, stack_dest, stack_src, \
		ft_ra, ft_rrb);
	if (best_elem->best_direction == 4)
		ft_inverse_stack_rotate(best_elem, stack_dest, stack_src, \
		ft_rra, ft_rb);
}

void	ft_min_top(t_list **stack)
{
	ft_compute_position(stack);
	if (ft_getmin(*stack)->position != 0)
	{
		if (ft_getmin(*stack)->position > ft_lstsize(*stack) / 2)
		{
			while (ft_getmin(*stack)->position != 0)
			{
				ft_rra(stack);
				ft_compute_position(stack);
			}
		}
		else if (ft_getmin(*stack)->position <= ft_lstsize(*stack) / 2)
		{
			while (ft_getmin(*stack)->position != 0)
			{
				ft_ra(stack);
				ft_compute_position(stack);
			}
		}
	}
}
