/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:11:58 by sum               #+#    #+#             */
/*   Updated: 2023/03/13 15:11:59 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_malloc_clear(t_alloc **lst)
{
	t_alloc	*tmp;

	if (*lst)
	{
		while (*lst != NULL)
		{
			tmp = (*lst)->next;
			if ((*lst)->ptr)
				free((*lst)->ptr);
			free(*lst);
			*lst = tmp;
		}
	}
}

void	malloc_add(t_alloc **alst, t_alloc *new)
{
	t_alloc	*tmp;

	tmp = *alst;
	if (tmp == NULL)
	{
		*alst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

t_alloc	*malloc_new(void *content)
{
	t_alloc	*li;

	li = malloc(sizeof(*li));
	if (!li)
		return (NULL);
	li->ptr = content;
	li->next = NULL;
	return (li);
}

void	*ft_malloc(int size, t_alloc	**lst)
{
	void	*alloc;

	alloc = malloc(size);
	if (!alloc)
		return (NULL);
	malloc_add(lst, malloc_new(alloc));
	return (alloc);
}
