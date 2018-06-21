/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_one_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 23:34:48 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/03 23:36:18 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	fill_check_lst_b_inside(t_env *env)
{
	do_the_job_b(env, 1);
	if (env->a_bool && VAL_A->content > VAL_B->content)
		env->rb_bool = 0;
	else if (env->sa_bool
	&& VAL_A->next->content > VAL_B->content)
		env->rb_bool = 0;
	else if (env->rra_bool
	&& *(int*)ft_lst_getend(env->list_a)->content > VAL_B->content)
		env->rb_bool = 0;
	else
	{
		do_the_job_b(env, 0);
		if (env->sa_bool && env->a_bool == 0)
		{
			env->sa_bool = 0;
			env->ra_bool = 1;
		}
	}
}

static void	fill_check_lst_b(t_env *env)
{
	if (env->list_b)
	{
		if (wich_side(env->list_b, VAL_B->content) > 0)
			env->rb_bool = 1;
		if (VAL_B->content < VAL_B->next->content)
			env->sb_bool = 1;
		if (env->rb_bool == 1 && env->sb_bool == 1)
			env->sb_bool = 0;
	}
	if (env->rb_bool)
		fill_check_lst_b_inside(env);
	else if (env->sb_bool)
	{
		do_the_job_b(env, 0);
		if (env->a_bool == 1)
			env->sa_bool = 0;
		env->a_bool = 0;
		env->rra_bool = 0;
	}
	else if (!env->rb_bool && !env->sb_bool)
		do_the_job_b(env, 0);
}

void		check_lst_b(t_env *env)
{
	if (!env->list_b || !env->list_b->next)
		return ;
	if (!env->list_b->next->next
	&& VAL_B->content < VAL_B->next->content)
	{
		do_the_job_b(env, 0);
		if (env->a_bool)
		{
			env->sa_bool = 0;
			env->sb_bool = 1;
			return ;
		}
		if (env->rra_bool == 1)
		{
			env->rrb_bool = 1;
			return ;
		}
		env->sb_bool = 1;
		return ;
	}
	fill_check_lst_b(env);
}

void		do_the_job_b(t_env *env, int half)
{
	int a;
	int b;
	int c;

	a = 0;
	b = 0;
	c = 0;
	(wich_side(env->list_b, VAL_A->content) > 0) ? a = 1 : 0;
	(wich_side(env->list_b, VAL_A->next->content) > 0) ? b = 1 : 0;
	(wich_side(env->list_b, *(int*)ft_lst_getend(env->list_a)->content) > 0)
	? c = 1 : 0;
	keep_big_b(env, a, b, c);
	if (half == 1)
		return ;
	a = 0;
	b = 0;
	c = 0;
	(wich_side(env->list_b, VAL_A->content) <= 0) ? a = 1 : 0;
	(wich_side(env->list_b, VAL_A->next->content) <= 0) ? b = 1 : 0;
	(wich_side(env->list_b, *(int*)ft_lst_getend(env->list_a)->content) <= 0)
	? c = 1 : 0;
	keep_ltl_b(env, a, b, c);
}
