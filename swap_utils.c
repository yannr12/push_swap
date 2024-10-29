/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:11:44 by yrio              #+#    #+#             */
/*   Updated: 2024/01/10 15:47:19 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (*stack == NULL)
		return ;
	first = *stack;
	if (first -> next == NULL)
		return ;
	second = first -> next;
	first -> next = second -> next;
	second -> next = first;
	*stack = second;
}

void	ft_double_swap(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}

void	ft_sa(t_list **stack)
{
	ft_swap(stack);
	ft_printf("%s", "sa\n");
}

void	ft_sb(t_list **stack)
{
	ft_swap(stack);
	ft_printf("%s", "sb\n");
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_double_swap(stack_a, stack_b);
	ft_printf("%s", "ss\n");
}

/*
int 	main(void)
{
	t_list *list;
	t_list *list2;
	t_list *list3;

	list = ft_lstnew(1);
	list2 = ft_lstnew(2);
	list3 = ft_lstnew(3);
	ft_lstadd_back(&list, list2);
	ft_lstadd_back(&list, list3);
	printf("%d\n", list -> content);
	printf("%d\n", list -> next -> content);
	printf("%d\n", list -> next -> next -> content);

	t_list *elem;
	t_list *elem2;
	t_list *elem3;

	elem = ft_lstnew(4);
	elem2 = ft_lstnew(5);
	elem3 = ft_lstnew(6);
	ft_lstadd_back(&elem, elem2);
	ft_lstadd_back(&elem, elem3);
	printf("\n%d\n", elem -> content);
	printf("%d\n", elem -> next -> content);
	printf("%d\n", elem -> next -> next -> content);

	ft_double_swap(&list, &elem);
	printf("\n%d\n", list -> content);
	printf("%d\n", list -> next -> content);
	printf("%d\n", list -> next -> next -> content);
	
	printf("\n%d\n", elem -> content);
	printf("%d\n", elem -> next -> content);
	return (0);
}
*/

/*int 	main(void)
{
	t_list *list;
	t_list *list2;
	t_list *list3;
	t_list *list4;

	list = ft_lstnew(1);
	list2 = ft_lstnew(2);
	list3 = ft_lstnew(3);
	list4 = ft_lstnew(4);
	ft_lstadd_back(&list, list2);
	ft_lstadd_back(&list, list3);
	ft_lstadd_back(&list, list4);
	printf("%d\n", list -> content);
	printf("%d\n", list -> next -> content);
	printf("%d\n", list -> next -> next -> content);
	printf("%d\n", list -> next -> next -> next -> content);

	ft_swap(&list, "sa\n");
	
	printf("\n%d\n", list -> content);
	printf("%d\n", list -> next -> content);
	printf("%d\n", list -> next -> next -> content);
	printf("%d\n", list -> next -> next -> next-> content);
	return (0);
}
*/