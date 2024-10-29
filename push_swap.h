/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:33:48 by yrio              #+#    #+#             */
/*   Updated: 2024/01/10 16:44:28 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <bsd/string.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>

int			ft_isdigit(char *str);
long int	ft_atoi(char *str);
int			ft_number_upper(int a, int b);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *str);
int			ft_putunsignednbr(unsigned int n);
int			ft_print_ptr(void *ptr, char c);
int			ft_print_hexa(void *ptr, char c);
int			ft_printf(const char *format, ...);
int			ft_putstr(char const *s);
int			ft_putchar(char c);
int			ft_putnbr(int n);
int			ft_free(char **char_tab);
void		delelem(void *del);
void		ft_bzero(void *s, size_t n);

typedef struct frame
{
	int				content;
	int				position;
	int				target;
	int				couta;
	int				coutb;
	int				best_direction;
	struct frame	*next;	
}					t_list;

t_list		*ft_lstnew(int content);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_before_lstlast(t_list **stack);
int			ft_lstsize(t_list *lst);
int			ft_check_duplicate(t_list **stack);
void		ft_sort_three(t_list **stack);
void		ft_lstclear(t_list **lst);
void		ft_optimal_sort(t_list **stack);
int			check_sorted(t_list *stack);
t_list		*ft_getmax(t_list *lst);
t_list		*ft_getmin(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_showlst(t_list *lst);

void		ft_sa(t_list **stack);
void		ft_sb(t_list **stack);
void		ft_ss(t_list **stack_a, t_list **stack_b);
void		ft_pa(t_list **stack_dest, t_list **stack_src);
void		ft_pb(t_list **stack_dest, t_list **stack_src);
void		ft_ra(t_list **stack);
void		ft_rb(t_list **stack);
void		ft_rr(t_list **stack_a, t_list **stack_b);
void		ft_rra(t_list **stack);
void		ft_rrb(t_list **stack);
void		ft_rrr(t_list **stack_a, t_list **stack_b);

void		ft_inverse_stack_rotate(t_list *best_elem, t_list **stack_a, \
			t_list **stack_b, void (f)(t_list **), void (g)(t_list **));
void		ft_apply_rr(t_list *best_elem, t_list **stack_a, t_list **stack_b);
void		ft_apply_rrr(t_list *best_elem, t_list **stack_a, t_list **stack_b);
void		ft_apply_best_rotate(t_list *best_elem, t_list **stack_dest, \
			t_list **stack_src);
void		ft_apply_best_rotate2(t_list *best_elem, t_list **stack_dest, \
			t_list **stack_src);
void		ft_min_top(t_list **stack);

void		ft_compute_final_index(t_list **stack);
void		ft_push_best(t_list **stack_a, t_list **stack_b);
void		ft_compute_position(t_list **stack_a);
void		ft_compute_target_stackb(t_list **stack_dest, t_list *src);
void		ft_compute_target_stacka(t_list **stack_dest, t_list *src);
void		ft_compute_cout(t_list *elem, t_list **stack_b);
void		ft_compute_cout_rr(t_list *elem);
void		ft_compute_cout_rrr(t_list *elem, t_list **stack_b);
void		ft_compute_cout_rarrb(t_list *elem, t_list **stack_b, int cout_tmp);
void		ft_compute_cout_rrarb(t_list *elem, int cout_tmp);

#endif