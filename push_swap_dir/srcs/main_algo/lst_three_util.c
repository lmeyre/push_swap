/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_three_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 23:18:49 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/03 23:20:20 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		scan_list(t_env *env)
{
	t_list *curr;

	curr = env->list_a;
	while (curr)
	{
		if (*(int*)curr->content < env->three_min
		|| *(int*)curr->content > env->three_max)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	find_bigger(t_env *env)
{
	int index;

	index = get_index(env->list_b, get_bigger_than(env->list_b,
			env->three_max));
	if (index == 1)
		index = 42;
	else if (index > (ft_lst_size(env->list_b) / 2 + 1))
		while (!(index > ft_lst_size(env->list_b)))
		{
			env->tab_order[9](env);
			++index;
		}
	else
		while (index > 1)
		{
			env->tab_order[6](env);
			--index;
		}
	env->tab_order[3](env);
	env->three_max = VAL_A->content;
	env->tab_order[5](env);
}

void	find_smaller(t_env *env)
{
	int index;

	index = get_index(env->list_b, get_lower_than(env->list_b, env->three_min));
	if (index == 1)
		index = 42;
	else if (index > (ft_lst_size(env->list_b) / 2 + 1))
		while (!(index > ft_lst_size(env->list_b)))
		{
			env->tab_order[9](env);
			++index;
		}
	else
		while (index > 1)
		{
			env->tab_order[6](env);
			--index;
		}
	env->tab_order[3](env);
	env->three_min = VAL_A->content;
}

void	sort_three_end(t_env *env)
{
	if (get_index(env->list_a, env->three_min)
		<= (ft_lst_size(env->list_a) / 2))
		while (VAL_A->content != env->three_min)
			env->tab_order[5](env);
	else
		while (VAL_A->content != env->three_min)
			env->tab_order[8](env);
	while (env->list_b)
	{
		if (env->three_max < get_bigger(env->list_b))
			find_bigger(env);
		else if (env->three_min > get_lower(env->list_b))
			find_smaller(env);
	}
}
