/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_three_special.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 23:59:04 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/04 00:05:05 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	fill_small_seq_special(t_env *env, int *size, int *bigger)
{
	if (get_lower_than(env->list_b, *bigger) == *bigger)
		return (*size);
	else
	{
		*bigger = get_lower_than(env->list_b, *bigger);
		++(*size);
	}
	return (-42);
}

static int	fill_actual_seq_special(t_env *env, int big, int bool, int index)
{
	int size;

	size = 1;
	while (1)
	{
		if (fill_small_seq_special(env, &size, &big) != -42)
			return (fill_small_seq_special(env, &size, &big));
		if (get_index(env->list_b, big) < get_index(env->list_b, env->tmp)
			&& bool == 0)
		{
			bool = 1;
			index = get_index(env->list_b, big);
		}
		else if ((get_index(env->list_b, big)
			> get_index(env->list_b, env->tmp)
			|| get_index(env->list_b, big) < index) && bool == 1)
			return (size - 1);
		else if (get_index(env->list_b, big) < get_index(env->list_b, env->tmp)
			&& get_index(env->list_b, big) > index && bool == 1)
			index = get_index(env->list_b, big);
		else if (get_index(env->list_b, big) > index && bool == 0)
			index = get_index(env->list_b, big);
		else if (get_index(env->list_b, big) < index && bool == 0)
			return (size - 1);
	}
}

int			actual_sequence_special(t_env *env, int index)
{
	int		bigger;
	int		base;
	t_list	*curr;
	int		size;
	int		bool;

	size = 1;
	curr = env->list_b;
	bool = index;
	while (index > 1)
	{
		curr = curr->next;
		--index;
	}
	index = bool;
	bool = 0;
	base = *(int*)curr->content;
	bigger = base;
	env->tmp = base;
	return (fill_actual_seq_special(env, bigger, bool, index));
}

static void	fill_longest_seq_special(t_env *env, int index, int best_sequence)
{
	t_list	*curr;
	int		i;

	curr = env->list_b;
	i = index;
	while (i > 1)
	{
		curr = curr->next;
		--i;
	}
	env->three_max = *(int*)curr->content;
	env->three_min = *(int*)curr->content;
	i = *(int*)curr->content;
	while (best_sequence > 1)
	{
		env->three_min = get_lower_than(env->list_b, env->three_min);
		--best_sequence;
	}
}

void		longest_sequence_special(t_env *env)
{
	int		index;
	int		best_sequence;
	t_list	*curr;
	int		i;

	i = 1;
	curr = env->list_b;
	index = 1;
	best_sequence = 0;
	while (curr)
	{
		if (actual_sequence_special(env, i) > best_sequence)
		{
			best_sequence = actual_sequence_special(env, i);
			index = i;
		}
		env->tmp = 0;
		curr = curr->next;
		++i;
	}
	fill_longest_seq_special(env, index, best_sequence);
}
