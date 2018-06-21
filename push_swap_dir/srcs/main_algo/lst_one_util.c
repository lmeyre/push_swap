/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_one_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 23:08:18 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/03 23:14:58 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		mini_reset(t_env *env, int x)
{
	if (x == 1)
	{
		env->a_bool = 0;
		env->sa_bool = 0;
		env->rra_bool = 0;
		env->ra_bool = 0;
	}
	else
	{
		env->b_bool = 0;
		env->sb_bool = 0;
		env->rrb_bool = 0;
		env->rb_bool = 0;
	}
}

void			lst_one_exception(t_env *env, int tmp)
{
	if (tmp == 1)
	{
		check_lst_b(env);
		mini_reset(env, 1);
		if (env->rb_bool && VAL_A->content > VAL_A->next->content)
			env->ra_bool = 1;
		else if (env->sb_bool
			&& VAL_A->content > VAL_A->next->content)
			env->sa_bool = 1;
		else if (VAL_A->content > VAL_A->next->content)
			env->sa_bool = 1;
		(env->rb_bool || env->sb_bool || env->sa_bool) ? to_b(env) : 0;
	}
	else if (tmp == 0)
	{
		check_lst_a(env);
		mini_reset(env, 0);
		if (env->ra_bool && VAL_B->content < VAL_B->next->content)
			env->rb_bool = 1;
		if (env->sa_bool && VAL_B->content < VAL_B->next->content)
			env->sb_bool = 1;
		else if (VAL_B->content < VAL_B->next->content)
			env->sb_bool = 1;
		(env->ra_bool || env->sa_bool || env->sb_bool) ? to_a(env) : 0;
	}
}

static void		fill_transition(t_env *env)
{
	finish_fill_a(env);
	sort_lst_three(env);
	if (env->best_action == 0 || env->best_action > env->action)
	{
		if (!lst_sorted(env->list_a) || env->list_b)
			ft_putendl("ERROR");
		env->best_action = env->action;
		env->jumping = env->fake_jumping;
		env->out = 3;
	}
	env->action = env->action_tmp;
	if (env->list_a)
		ft_lst_del_all(&env->list_a);
	if (env->list_b)
		ft_lst_del_all(&env->list_b);
	env->list_a = env->tmp_a;
	env->list_b = env->tmp_b;
	env->tmp_a = NULL;
	env->tmp_b = NULL;
}

static void		fill_transition_bis(t_env *env)
{
	finish_fill_b(env);
	sort_lst_three_special(env);
	if (env->best_action == 0 || env->best_action > env->action)
	{
		if (!lst_sorted(env->list_a) || env->list_b)
			ft_putendl("ERROR");
		env->best_action = env->action;
		env->jumping = env->fake_jumping;
		env->out = -3;
	}
	env->action = env->action_tmp;
	if (env->list_a)
		ft_lst_del_all(&env->list_a);
	if (env->list_b)
		ft_lst_del_all(&env->list_b);
	env->list_a = env->tmp_a;
	env->list_b = env->tmp_b;
	env->tmp_a = NULL;
	env->tmp_b = NULL;
}

int				prepare_transition(t_env *env, int tmp)
{
	if (env->list_a)
		if (!(env->tmp_a = ft_lst_int_copy(env->list_a)))
			return (0);
	if (env->list_b)
		if (!(env->tmp_b = ft_lst_int_copy(env->list_b)))
			return (0);
	env->action_tmp = env->action;
	if (tmp == 1)
		fill_transition_bis(env);
	else if (tmp == 0)
		fill_transition(env);
	return (1);
}
