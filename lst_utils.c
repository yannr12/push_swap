/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:32:05 by yrio              #+#    #+#             */
/*   Updated: 2024/01/10 15:47:51 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	new -> content = content;
	new -> position = -1;
	new -> target = -1;
	new -> couta = -1;
	new -> coutb = -1;
	new -> best_direction = -1;
	new -> next = NULL;
	return (new);
}

t_list	*ft_before_lstlast(t_list **stack)
{
	t_list	*tmp;

	if (stack == NULL)
		return (NULL);
	tmp = *stack;
	while (tmp -> next -> next != NULL)
		tmp = tmp -> next;
	return (tmp);
}

int	ft_check_duplicate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (stack == NULL)
		return (0);
	tmp = *stack;
	while (tmp -> next != NULL)
	{
		tmp2 = tmp -> next;
		while (tmp2)
		{
			if (tmp -> content == tmp2 -> content)
				return (0);
			tmp2 = tmp2 -> next;
		}
		tmp = tmp -> next;
	}
	return (1);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if (lst == NULL)
		return ;
	first = *lst;
	while (first != NULL)
	{
		second = first;
		first = first->next;
		free(second);
	}
	*lst = NULL;
}

int	check_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack -> next != NULL)
	{
		if (stack -> content > stack -> next -> content)
			return (0);
		stack = stack -> next;
	}
	return (1);
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
	printf("%d", check_sorted(list));
	return (0);
}
*/

/*
int 	main(void)
{
	t_list *list;
	t_list *list2;
	t_list *list3;
	t_list *list4;

	list = ft_lstnew(1);
	list2 = ft_lstnew(2);
	list3 = ft_lstnew(3);
	list4 = ft_lstnew(1);
	ft_lstadd_back(&list, list2);
	ft_lstadd_back(&list, list3);
	ft_lstadd_back(&list, list4);
	printf("%d", ft_check_duplicate(&list));
	return (0);
}
*/
