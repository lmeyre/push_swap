/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_three_special_util.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 23:17:38 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/03 23:18:39 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			scan_list_special(t_env *env)
{
	t_list *curr;

	curr = env->list_b;
	while (curr)
	{
		if (*(int*)curr->content >= env->three_min
			&& *(int*)curr->content <= env->three_max)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void		sort_three_special_end(t_env *env)
{
	t_list *curr;

	if (get_index(env->list_b, env->three_max)
		<= (ft_lst_size(env->list_b) / 2))
		while (VAL_B->content != env->three_max)
			env->tab_order[6](env);
	else
		while (VAL_B->content != env->three_max)
			env->tab_order[9](env);
	while (scan_list_special(env) == 0)
	{
		curr = env->list_b;
		if (*(int*)curr->content <= env->three_max
			&& *(int*)curr->content >= env->three_min)
			env->tab_order[3](env);
		else
			env->tab_order[6](env);
	}
	while (env->list_b)
	{
		if (env->three_max < get_bigger(env->list_b))
			find_bigger(env);
		else if (env->three_min > get_lower(env->list_b))
			find_smaller(env);
	}
}
