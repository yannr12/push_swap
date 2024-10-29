/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:41:20 by yrio              #+#    #+#             */
/*   Updated: 2024/01/10 15:47:24 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_inverse_stack_rotate2(t_list *best_elem, t_list **stack_a, \
		t_list **stack_b, void (f)(t_list **), void (g)(t_list **))
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

void	ft_apply_rr2(t_list *best_elem, t_list **stack_a, t_list **stack_b)
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
			ft_rb(stack_a);
			best_elem->couta = best_elem->couta - 1;
		}
		else if (best_elem->couta == 0)
		{
			ft_ra(stack_b);
			best_elem->coutb = best_elem->coutb - 1;
		}
	}
}

void	ft_apply_rrr2(t_list *best_elem, t_list **stack_a, t_list **stack_b)
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
			ft_rrb(stack_a);
			best_elem->couta = best_elem->couta - 1;
		}
		else if (best_elem->couta == 0)
		{
			ft_rra(stack_b);
			best_elem->coutb = best_elem->coutb - 1;
		}
	}
}

void	ft_apply_best_rotate2(t_list *best_elem, t_list **stack_dest, \
		t_list **stack_src)
{
	if (best_elem->best_direction == 1)
		ft_apply_rr2(best_elem, stack_dest, stack_src);
	if (best_elem->best_direction == 2)
		ft_apply_rrr2(best_elem, stack_dest, stack_src);
	if (best_elem->best_direction == 3)
		ft_inverse_stack_rotate(best_elem, stack_dest, stack_src, \
		ft_rb, ft_rra);
	if (best_elem->best_direction == 4)
		ft_inverse_stack_rotate(best_elem, stack_dest, stack_src, \
		ft_rrb, ft_ra);
}
