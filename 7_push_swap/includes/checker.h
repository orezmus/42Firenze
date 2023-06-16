/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <sum@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:50:58 by sum               #+#    #+#             */
/*   Updated: 2023/04/21 19:11:19 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

void		init_stack(t_var *var);
t_node		*init_node(int data);

void		check_dupe(t_var *var);
int			check_size(char **av);
int			check_valid(char *str, t_var *var);

int			is_sorted(t_stack *stack, int size);
void		cmd_input(t_var *var, char *line);

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

void		error_free(t_var *var, char *line);
size_t		ft_wordcnt(const char *s, char d);
void		show(t_stack *stack);

#endif
