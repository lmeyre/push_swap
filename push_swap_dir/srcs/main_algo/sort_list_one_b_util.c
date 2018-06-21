/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_one_b_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 23:36:33 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/03 23:37:47 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		to_b(t_env *env)
{
	if (env->rrb_bool && env->rra_bool)
		env->tab_order[10](env);
	else if (env->rb_bool && env->ra_bool)
		env->tab_order[7](env);
	else if (env->rb_bool)
		env->tab_order[6](env);
	else if (env->sb_bool && env->sa_bool)
		env->tab_order[2](env);
	else if (env->sb_bool)
		env->tab_order[1](env);
	else if (env->a_bool)
		env->tab_order[4](env);
	else if (env->sa_bool)
		env->tab_order[0](env);
	else if (env->ra_bool)
		env->tab_order[5](env);
	else if (env->rra_bool)
		env->tab_order[8](env);
	else
		env->tab_order[4](env);
}

static void	fill_keep_big_b(t_env *env, int a, int b, int c)
{
	if (a && c)
	{
		if (VAL_A->content > *(int*)ft_lst_getend(env->list_a)->content)
			env->a_bool = 1;
		else
			env->rra_bool = 1;
	}
	else if (b && c)
	{
		if (VAL_A->next->content > *(int*)ft_lst_getend(env->list_a)->content)
			env->sa_bool = 1;
		else
			env->rra_bool = 1;
	}
	else if (a)
		env->a_bool = 1;
	else if (b)
		env->sa_bool = 1;
	else if (c)
		env->rra_bool = 1;
}

void		keep_big_b(t_env *env, int a, int b, int c)
{
	if (a && b && c)
	{
		if ((VAL_A->content > VAL_A->next->content)
		&& (VAL_A->content > *(int*)ft_lst_getend(env->list_a)->content))
			env->a_bool = 1;
		else if ((VAL_A->next->content > VAL_A->content)
		&& (VAL_A->next->content > *(int*)ft_lst_getend(env->list_a)->content))
			env->sa_bool = 1;
		else
			env->rra_bool = 1;
	}
	else if (a && b)
	{
		if (VAL_A->content > VAL_A->next->content)
			env->a_bool = 1;
		else
			env->sa_bool = 1;
	}
	else
		fill_keep_big_b(env, a, b, c);
}

static void	fill_keep_ltl_b(t_env *env, int a, int b, int c)
{
	if (a && c)
	{
		if (VAL_A->content < *(int*)ft_lst_getend(env->list_a)->content)
			env->a_bool = 1;
		else
			env->rra_bool = 1;
	}
	else if (b && c)
	{
		if (VAL_A->next->content < *(int*)ft_lst_getend(env->list_a)->content)
			env->sa_bool = 1;
		else
			env->rra_bool = 1;
	}
	else if (a)
		env->a_bool = 1;
	else if (b)
		env->sa_bool = 1;
	else if (c)
		env->rra_bool = 1;
}

void		keep_ltl_b(t_env *env, int a, int b, int c)
{
	if (a && b && c)
	{
		if ((VAL_A->content < VAL_A->next->content)
		&& (VAL_A->content < *(int*)ft_lst_getend(env->list_a)->content))
			env->a_bool = 1;
		else if ((VAL_A->next->content < VAL_A->content)
		&& (VAL_A->next->content < *(int*)ft_lst_getend(env->list_a)->content))
			env->sa_bool = 1;
		else
			env->rra_bool = 1;
	}
	else if (a && b)
	{
		if (VAL_A->content < VAL_A->next->content)
			env->a_bool = 1;
		else
			env->sa_bool = 1;
	}
	else
		fill_keep_ltl_b(env, a, b, c);
}
