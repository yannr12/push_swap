/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:21:10 by yrio              #+#    #+#             */
/*   Updated: 2024/01/10 15:47:47 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = new;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

t_list	*ft_getmax(t_list *lst)
{
	t_list	*tmp;
	t_list	*max;

	max = NULL;
	tmp = lst;
	if (lst == NULL)
		return (NULL);
	while (tmp)
	{
		if (max == NULL)
			max = tmp;
		else
			if (tmp -> content > max -> content)
				max = tmp;
		tmp = tmp -> next;
	}
	return (max);
}

t_list	*ft_getmin(t_list *lst)
{
	t_list	*tmp;
	t_list	*min;

	min = NULL;
	tmp = lst;
	if (lst == NULL)
		return (NULL);
	while (tmp)
	{
		if (min == NULL)
			min = tmp;
		else
			if (tmp -> content < min -> content)
				min = tmp;
		tmp = tmp -> next;
	}
	return (min);
}

/*
int 	main(void)
{
	t_list *list;
	t_list *list2;
	t_list *list3;
	t_list *list4;

	list = ft_lstnew(1);
	list2 = ft_lstnew(5);
	list3 = ft_lstnew(3);
	list4 = ft_lstnew(4);
	ft_lstadd_back(&list, list2);
	ft_lstadd_back(&list, list3);
	ft_lstadd_back(&list, list4);
	ft_printf("%d", ft_getmax(list) -> content);
	return (0);
}
*/
