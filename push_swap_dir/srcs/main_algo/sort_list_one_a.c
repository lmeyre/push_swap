/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_one_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 23:30:27 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/03 23:32:45 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	fill_check_lst_a_inside(t_env *env)
{
	do_the_job_a(env, 1);
	if (env->b_bool == 1 && VAL_B->content < VAL_A->content)
		env->ra_bool = 0;
	else if (env->sb_bool == 1 && VAL_B->content < VAL_A->content)
		env->ra_bool = 0;
	else if (env->rrb_bool == 1
		&& VAL_B->content < VAL_A->content)
		env->ra_bool = 0;
	else
	{
		do_the_job_a(env, 0);
		env->b_bool = 0;
		env->rrb_bool = 0;
		if (env->sb_bool == 1 && env->b_bool == 0)
		{
			env->sb_bool = 0;
			env->rb_bool = 1;
		}
	}
}

static void	fill_check_lst_a(t_env *env)
{
	if (wich_side(env->list_a, VAL_A->content) <= 0)
		env->ra_bool = 1;
	if (VAL_A->content > VAL_A->next->content)
		env->sa_bool = 1;
	if (env->ra_bool == 1 && env->sa_bool == 1)
		env->sa_bool = 0;
	if (env->ra_bool)
		fill_check_lst_a_inside(env);
	else if (env->sa_bool)
	{
		do_the_job_a(env, 0);
		if (env->b_bool == 1)
			env->sb_bool = 0;
		env->b_bool = 0;
		env->rrb_bool = 0;
	}
	else if (!env->ra_bool && !env->sa_bool)
		do_the_job_a(env, 0);
}

void		check_lst_a(t_env *env)
{
	if (!env->list_a || !env->list_a->next)
		return ;
	if (!env->list_b->next)
		return ;
	if (!env->list_a->next->next
		&& VAL_A->content > VAL_A->next->content)
	{
		do_the_job_a(env, 0);
		if (env->b_bool)
		{
			env->sb_bool = 0;
			env->sa_bool = 1;
			return ;
		}
		if (env->rrb_bool == 1)
		{
			env->rra_bool = 1;
			return ;
		}
		env->sa_bool = 1;
		return ;
	}
	fill_check_lst_a(env);
}

void		do_the_job_a(t_env *env, int half)
{
	int a;
	int b;
	int c;

	a = 0;
	b = 0;
	c = 0;
	(wich_side(env->list_a, VAL_B->content) <= 0) ? a = 1 : 0;
	(wich_side(env->list_a, VAL_B->next->content) <= 0) ? b = 1 : 0;
	(wich_side(env->list_a, *(int*)ft_lst_getend(env->list_b)->content) <= 0)
	? c = 1 : 0;
	keep_ltl_a(env, a, b, c);
	if (half == 1)
		return ;
	a = 0;
	b = 0;
	c = 0;
	(wich_side(env->list_a, VAL_B->content) > 0) ? a = 1 : 0;
	(wich_side(env->list_a, VAL_B->next->content) > 0) ? b = 1 : 0;
	(wich_side(env->list_a, *(int*)ft_lst_getend(env->list_b)->content) > 0)
	? c = 1 : 0;
	keep_big_a(env, a, b, c);
}
