/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 00:33:01 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/04 00:33:54 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			get_lower(t_list *lst)
{
	int		lowest;
	t_list	*start;

	start = lst;
	lowest = *(int*)lst->content;
	while (lst)
	{
		if (*(int*)lst->content < lowest)
			lowest = *(int*)lst->content;
		lst = lst->next;
	}
	lst = start;
	return (lowest);
}

int			get_bigger(t_list *lst)
{
	int		bigger;
	t_list	*start;

	start = lst;
	bigger = *(int*)lst->content;
	while (lst)
	{
		if (*(int*)lst->content > bigger)
			bigger = *(int*)lst->content;
		lst = lst->next;
	}
	lst = start;
	return (bigger);
}

int			get_lower_than(t_list *lst, int i)
{
	int		lower;
	t_list	*start;

	start = lst;
	lower = get_lower(lst);
	while (lst)
	{
		if (*(int*)lst->content > lower && *(int*)lst->content < i)
			lower = *(int*)lst->content;
		lst = lst->next;
	}
	lst = start;
	return (lower);
}

int			get_bigger_than(t_list *lst, int i)
{
	int		bigger;
	t_list	*start;

	start = lst;
	bigger = get_bigger(lst);
	lst = start;
	while (lst)
	{
		if (*(int*)lst->content < bigger && *(int*)lst->content > i)
			bigger = *(int*)lst->content;
		lst = lst->next;
	}
	lst = start;
	return (bigger);
}

int			get_index(t_list *lst, int elem)
{
	int		index;
	t_list	*start;

	index = 1;
	start = lst;
	while (lst)
	{
		if (*(int*)lst->content == elem)
			break ;
		lst = lst->next;
		index++;
	}
	lst = start;
	return (index);
}
