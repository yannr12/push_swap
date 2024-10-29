/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:14:24 by yrio              #+#    #+#             */
/*   Updated: 2024/01/10 15:47:59 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_compute_cout_rr(t_list *elem)
{
		elem->couta = elem->position;
		elem->coutb = elem->target;
}

void	ft_compute_cout_rrr(t_list *elem, t_list **stack_b)
{
	if (ft_number_upper(ft_lstlast(elem)->position - elem->position + 1, \
		ft_lstlast(*stack_b)->position - elem->target + 1) < \
		ft_number_upper(elem->couta, elem->coutb))
	{
			elem->couta = ft_lstlast(elem)->position - elem->position + 1;
			elem->coutb = ft_lstlast(*stack_b)->position - elem->target + 1;
	}
}

void	ft_compute_cout_rarrb(t_list *elem, t_list **stack_b, int cout_tmp)
{
	if ((elem->position + ft_lstlast(*stack_b)->position - elem->target + 1) \
		< cout_tmp)
	{
		elem->couta = elem->position;
		elem->coutb = ft_lstlast(*stack_b)->position - elem->target + 1;
	}
}

void	ft_compute_cout_rrarb(t_list *elem, int cout_tmp)
{
	if (ft_lstlast(elem)->position - elem->position + 1 + elem->target \
		< cout_tmp)
	{
		elem->couta = (ft_lstlast(elem)->position - elem->position) + 1;
		elem->coutb = elem->target;
	}
}
