/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 00:10:58 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/04 00:13:32 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			sort_lst_two_reverse(t_env *env)
{
	if (env->list_a && !(env->tmp_a = ft_lst_int_copy(env->list_a)))
		return (0);
	if (env->list_b && !(env->tmp_b = ft_lst_int_copy(env->list_b)))
		return (0);
	env->action_tmp = env->action;
	finish_fill_b(env);
	while (env->list_b)
		put_bigger(env);
	if (env->best_action == 0 || env->best_action > env->action)
	{
		if (!lst_sorted(env->list_a) || env->list_b)
			ft_putendl("ERROR");
		env->best_action = env->action;
		env->jumping = env->fake_jumping;
		env->out = -2;
	}
	env->action = env->action_tmp;
	(env->list_a) ? ft_lst_del_all(&env->list_a) : 0;
	if (env->list_b)
		ft_lst_del_all(&env->list_b);
	env->list_a = env->tmp_a;
	env->list_b = env->tmp_b;
	env->tmp_a = NULL;
	env->tmp_b = NULL;
	return (1);
}

void		sort_lst_three_special(t_env *env)
{
	longest_sequence_special(env);
	sort_three_special_end(env);
}

void		sort_lst_three(t_env *env)
{
	t_list *curr;

	longest_sequence_base(env);
	while (scan_list(env) == 0)
	{
		curr = env->list_a;
		if (*(int*)curr->content > env->three_max
		|| *(int*)curr->content < env->three_min)
			env->tab_order[4](env);
		else
			env->tab_order[5](env);
	}
	sort_three_end(env);
}

void		four_elem(t_env *env)
{
	put_lowest(env);
	put_lowest(env);
	if (VAL_A->content > VAL_A->next->content
	&& VAL_B->content < VAL_B->next->content)
		env->tab_order[2](env);
	else if (VAL_A->content > VAL_A->next->content)
		env->tab_order[0](env);
	else if (VAL_B->content < VAL_B->next->content)
		env->tab_order[1](env);
	env->tab_order[3](env);
	env->tab_order[3](env);
}

int			four_elem_opti(t_env *env)
{
	if (VAL_A->content > VAL_A->next->content)
		env->tab_order[0](env);
	if (lst_sorted(env->list_a) == 1)
	{
		env->four_opti = env->action;
		return (1);
	}
	env->tab_order[5](env);
	env->tab_order[5](env);
	if (VAL_A->content > VAL_A->next->content)
		env->tab_order[0](env);
	if (lst_sorted(env->list_a) == 1)
	{
		env->four_opti = env->action;
		return (1);
	}
	env->tab_order[5](env);
	env->tab_order[5](env);
	if (lst_sorted(env->list_a) == 1)
	{
		env->four_opti = env->action;
		return (1);
	}
	return (0);
}
