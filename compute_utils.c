/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:02:00 by yrio              #+#    #+#             */
/*   Updated: 2024/01/10 15:48:02 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_compute_position(t_list **stack_a)
{
	int		set_position;
	t_list	*tmp;

	set_position = 0;
	tmp = *stack_a;
	while (tmp)
	{
		tmp -> position = set_position;
		set_position++;
		tmp = tmp -> next;
	}
}

void	ft_compute_target_stackb(t_list **stack_dest, t_list *src)
{
	t_list	*tmp;

	tmp = *stack_dest;
	if (src->content < ft_lstlast(tmp)->content \
		&& src->content > tmp->content)
		src -> target = 0;
	else if (src->content > ft_getmax(tmp)->content)
		src -> target = ft_getmax(tmp)->position;
	else if (src->content < ft_getmin(tmp)->content)
		src -> target = ft_getmax(tmp)->position;
	else
	{
		while (!(src->content < tmp->content \
			&& src->content > tmp->next->content) \
			&& tmp->next)
			tmp = tmp->next;
		if (tmp)
			src -> target = tmp->next->position;
	}
}

void	ft_compute_target_stacka(t_list **stack_dest, t_list *src)
{
	t_list	*tmp;

	tmp = *stack_dest;
	if (src->content > ft_lstlast(tmp)->content \
		&& src->content < tmp->content)
		src -> target = 0;
	else if (src->content > ft_getmax(tmp)->content)
		src -> target = ft_getmin(tmp)->position;
	else if (src->content < ft_getmin(tmp)->content)
		src -> target = ft_getmin(tmp)->position;
	else
	{
		while (!(src->content > tmp->content \
			&& src->content < tmp->next->content) \
			&& tmp->next)
			tmp = tmp->next;
		if (tmp)
			src -> target = tmp->next->position;
	}
}

void	ft_compute_cout(t_list *elem, t_list **stack_b)
{
	int		cout_tmp;

	cout_tmp = INT_MAX;
	ft_compute_cout_rr(elem);
	if (ft_number_upper(elem->couta, elem->coutb) < cout_tmp)
	{
		elem->best_direction = 1;
		cout_tmp = ft_number_upper(elem->couta, elem->coutb);
	}
	ft_compute_cout_rrr(elem, stack_b);
	if (ft_number_upper(elem->couta, elem->coutb) < cout_tmp)
	{
		elem->best_direction = 2;
		cout_tmp = ft_number_upper(elem->couta, elem->coutb);
	}
	ft_compute_cout_rarrb(elem, stack_b, cout_tmp);
	if (elem->couta + elem->coutb < cout_tmp)
	{
		elem->best_direction = 3;
		cout_tmp = elem->couta + elem->coutb;
	}
	ft_compute_cout_rrarb(elem, cout_tmp);
	if (elem->couta + elem->coutb < cout_tmp)
		elem->best_direction = 4;
}
