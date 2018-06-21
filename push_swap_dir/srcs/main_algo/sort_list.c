/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 23:20:40 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/03 23:30:15 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		sort_lst_one(t_env *env)
{
	int tmp;

	reset_value(env);
	tmp = env->way;
	while (1)
	{
		if (tmp != env->way)
		{
			lst_one_exception(env, tmp);
			break ;
		}
		tmp = env->way;
		reset_value(env);
		if (!env->list_b && lst_sorted(env->list_a))
			return ;
		env->way ? check_lst_b(env) : check_lst_a(env);
		env->way ? to_b(env) : to_a(env);
		reset_value(env);
	}
}

static void	fill_sort_all(t_env *env, int *off)
{
	if (*off)
	{
		sort_lst_one(env);
		finish_fill_a(env);
		++(env->fake_jumping);
		*off = 0;
	}
	else
	{
		sort_lst_one(env);
		finish_fill_b(env);
		++(env->fake_jumping);
		*off = 1;
	}
}

int			sort_all(t_env *env)
{
	int off;

	if (lst_sorted(env->list_a) && env->list_b == NULL)
		return (1);
	off = 0;
	while (lst_sorted(env->list_a) == 0 || env->list_b)
	{
		if (env->action > env->best_action)
			break ;
		if (!(prepare_transition(env, off)))
			return (0);
		if (off)
		{
			if (!(sort_lst_two_reverse(env)))
				return (0);
		}
		else if (!(sort_lst_two(env)))
			return (0);
		fill_sort_all(env, &off);
	}
	return (1);
}

static void	fill_sort_jumping(t_env *env, int *off)
{
	while (env->jumping)
	{
		if (*off)
		{
			sort_lst_one(env);
			finish_fill_a(env);
			*off = 0;
		}
		else
		{
			sort_lst_one(env);
			finish_fill_b(env);
			*off = 1;
		}
		--(env->jumping);
	}
}

void		sort_jumping(t_env *env)
{
	int off;

	if (lst_sorted(env->list_a) && env->list_b == NULL)
		return ;
	off = 0;
	fill_sort_jumping(env, &off);
	if (env->out == 2)
	{
		while (env->list_a->next->next != NULL)
			put_lowest(env);
		if (VAL_A->content > VAL_A->next->content)
			env->tab_order[0](env);
		while (env->list_b != NULL)
			env->tab_order[3](env);
	}
	else if (env->out == -2)
		while (env->list_b)
			put_bigger(env);
	else if (env->out == 3)
		sort_lst_three(env);
	else if (env->out == -3)
		sort_lst_three_special(env);
}
