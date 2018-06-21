/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_one_a_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 23:33:01 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/03 23:34:33 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		to_a(t_env *env)
{
	if (env->rrb_bool && env->rra_bool)
		env->tab_order[10](env);
	else if (env->ra_bool && env->rb_bool)
		env->tab_order[7](env);
	else if (env->ra_bool)
		env->tab_order[5](env);
	else if (env->sa_bool && env->sb_bool)
		env->tab_order[2](env);
	else if (env->sa_bool)
		env->tab_order[0](env);
	else if (env->b_bool)
		env->tab_order[3](env);
	else if (env->sb_bool)
		env->tab_order[1](env);
	else if (env->rrb_bool)
		env->tab_order[9](env);
	else if (env->rb_bool)
		env->tab_order[6](env);
	else
		env->tab_order[3](env);
}

static void	fill_keep_big_a(t_env *env, int a, int b, int c)
{
	if (a && c)
	{
		if (VAL_B->content > *(int*)ft_lst_getend(env->list_b)->content)
			env->b_bool = 1;
		else
			env->rrb_bool = 1;
	}
	else if (b && c)
	{
		if (VAL_B->next->content > *(int*)ft_lst_getend(env->list_b)->content)
			env->sb_bool = 1;
		else
			env->rrb_bool = 1;
	}
	else if (a)
		env->b_bool = 1;
	else if (b)
		env->sb_bool = 1;
	else if (c)
		env->rrb_bool = 1;
}

void		keep_big_a(t_env *env, int a, int b, int c)
{
	if (a && b && c)
	{
		if ((VAL_B->content > VAL_B->next->content)
		&& (VAL_B->content > *(int*)ft_lst_getend(env->list_b)->content))
			env->b_bool = 1;
		else if ((VAL_B->next->content > VAL_B->content)
		&& (VAL_B->next->content > *(int*)ft_lst_getend(env->list_b)->content))
			env->sb_bool = 1;
		else
			env->rrb_bool = 1;
	}
	else if (a && b)
	{
		if (VAL_B->content > VAL_B->next->content)
			env->b_bool = 1;
		else
			env->sb_bool = 1;
	}
	else
		fill_keep_big_a(env, a, b, c);
}

static void	fill_keep_ltl_a(t_env *env, int a, int b, int c)
{
	if (a && c)
	{
		if (VAL_B->content < *(int*)ft_lst_getend(env->list_b)->content)
			env->b_bool = 1;
		else
			env->rrb_bool = 1;
	}
	else if (b && c)
	{
		if (VAL_B->next->content < *(int*)ft_lst_getend(env->list_b)->content)
			env->sb_bool = 1;
		else
			env->rrb_bool = 1;
	}
	else if (a)
		env->b_bool = 1;
	else if (b)
		env->sb_bool = 1;
	else if (c)
		env->rrb_bool = 1;
}

void		keep_ltl_a(t_env *env, int a, int b, int c)
{
	if (a && b && c)
	{
		if ((VAL_B->content < VAL_B->next->content)
		&& (VAL_B->content < *(int*)ft_lst_getend(env->list_b)->content))
			env->b_bool = 1;
		else if ((VAL_B->next->content < VAL_B->content)
		&& (VAL_B->next->content < *(int*)ft_lst_getend(env->list_b)->content))
			env->sb_bool = 1;
		else
			env->rrb_bool = 1;
	}
	else if (a && b)
	{
		if (VAL_B->content < VAL_B->next->content)
			env->b_bool = 1;
		else
			env->sb_bool = 1;
	}
	else
		fill_keep_ltl_a(env, a, b, c);
}
