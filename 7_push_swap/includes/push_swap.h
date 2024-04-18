/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:50:58 by sum               #+#    #+#             */
/*   Updated: 2023/04/21 17:57:21 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct s_node{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack{
	int			size;
	t_node		*top;
	t_node		*bottom;
}	t_stack;

typedef struct s_var{	
	t_stack	*a;
	t_stack	*b;
	int		*arr;
	int		size;
}	t_var;

typedef struct s_cmd{	
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	pivot_l;
	int	pivot_s;
	int	size;
}	t_cmd;

void		init_stack(t_var *var);
t_cmd		*init_size(int size);
t_node		*init_node(int data);

void		check_dupe(t_var *var);
int			check_size(char **av);
int			check_valid(char *str, t_var *var);

void		a_to_b(t_var *var, int size);
void		b_to_a(t_var *var, int size);

int			is_sorted(t_stack *stack, int size);
int			sorted_b(t_var *var, int size);
int			small_sorted(t_var *var, int size);

int			pivot(t_stack *stack, int count, char c);
int			pivot_mid(t_var *var, int size);
void		rotate_back(t_var *var, t_cmd *cmd);

void		push(t_stack *stack, int data);
void		push_back(t_stack *stack, int data);
t_node		*pop(t_stack *stack);
t_node		*pop_back(t_stack *stack);

void		sa(t_stack *stack_a);
void		sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);

void		ra(t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);

void		rra(t_stack *stack_a);
void		rrb(t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);

void		error_free(t_var *var);
size_t		ft_wordcnt(const char *s, char d);
void		show(t_stack *stack);

#endif
