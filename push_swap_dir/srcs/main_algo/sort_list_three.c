/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 23:38:08 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/03 23:58:38 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	fill_small_seq(t_env *env, int *size, int *bigger)
{
	if (get_bigger_than(env->list_a, *bigger) == *bigger)
		return (*size);
	else
	{
		*bigger = get_bigger_than(env->list_a, *bigger);
		++(*size);
	}
	return (-42);
}

static int	fill_actual_seq_base(t_env *env, int big, int bool, int index)
{
	int size;

	size = 1;
	while (1)
	{
		if (fill_small_seq(env, &size, &big) != -42)
			return (fill_small_seq(env, &size, &big));
		if (get_index(env->list_a, big) < get_index(env->list_a, env->tmp)
			&& bool == 0)
		{
			bool = 1;
			index = get_index(env->list_a, big);
		}
		else if ((get_index(env->list_a, big)
			> get_index(env->list_a, env->tmp)
			|| get_index(env->list_a, big) < index) && bool == 1)
			return (size - 1);
		else if (get_index(env->list_a, big) < get_index(env->list_a, env->tmp)
			&& get_index(env->list_a, big) > index && bool == 1)
			index = get_index(env->list_a, big);
		else if (get_index(env->list_a, big) > index && bool == 0)
			index = get_index(env->list_a, big);
		else if (get_index(env->list_a, big) < index && bool == 0)
			return (size - 1);
	}
}

int			actual_sequence_base(t_env *env, int index)
{
	int		bigger;
	int		base;
	t_list	*curr;
	int		bool;

	curr = env->list_a;
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
	return (fill_actual_seq_base(env, bigger, bool, index));
}

static void	fill_longest_seq_base(t_env *env, int index, int best_sequence)
{
	t_list	*curr;
	int		i;

	curr = env->list_a;
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
		env->three_max = get_bigger_than(env->list_a, env->three_max);
		--best_sequence;
	}
}

void		longest_sequence_base(t_env *env)
{
	int		index;
	int		best_sequence;
	t_list	*curr;
	int		i;

	i = 1;
	curr = env->list_a;
	index = 1;
	best_sequence = 0;
	while (curr)
	{
		if (actual_sequence_base(env, i) > best_sequence)
		{
			best_sequence = actual_sequence_base(env, i);
			index = i;
		}
		env->tmp = 0;
		curr = curr->next;
		++i;
	}
	fill_longest_seq_base(env, index, best_sequence);
}
