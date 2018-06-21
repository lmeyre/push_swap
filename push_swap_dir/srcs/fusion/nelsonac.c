/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nelsonac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 23:01:22 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/03 23:07:19 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		fill_nelson_two(t_env *env, int size)
{
	while (size)
	{
		if (VAL_A->content > VAL_A->next->content
			&& VAL_B->content > VAL_B->next->content)
			env->tab_order[2](env);
		else if (VAL_A->content > VAL_A->next->content)
			env->tab_order[0](env);
		else if (VAL_B->content > VAL_B->next->content)
			env->tab_order[1](env);
		env->tab_order[7](env);
		env->tab_order[7](env);
		size -= 2;
	}
}

static void		nelson_two(t_env *env)
{
	int size;
	int exception;

	exception = 0;
	size = ft_lst_size(env->list_b);
	size = (size / 2) * 2;
	if ((ft_lst_size(env->list_a) - (size)) == 2)
		exception = 1;
	fill_nelson_two(env, size);
	if (exception == 1)
	{
		if (VAL_A->content > VAL_A->next->content)
			env->tab_order[0](env);
		env->tab_order[7](env);
		env->tab_order[5](env);
	}
	if ((ft_lst_size(env->list_a) % ((ft_lst_size(env->list_a) / 2) * 2)) == 1)
	{
		if ((ft_lst_size(env->list_b) % ((ft_lst_size(env->list_b) / 2)
			* 2)) == 1)
			env->tab_order[7](env);
		else
			env->tab_order[5](env);
	}
}

static void		put_b_except_trash(t_env *env, int stack_a, int stack_b)
{
	while (stack_a || stack_b)
	{
		if (stack_b && ((VAL_B->content < VAL_A->content)
			|| stack_a == 0))
		{
			--stack_b;
			env->tab_order[3](env);
		}
		else
			--stack_a;
		env->tab_order[5](env);
	}
}

static void		merge_trash(t_env *env, int ltl_trash, int total, int trash_b)
{
	if (ltl_trash > 0)
	{
		while (total--)
		{
			if (trash_b == 0 ||
			(ltl_trash > 0 && VAL_A->content < VAL_B->content))
			{
				env->tab_order[4](env);
				--ltl_trash;
			}
			else
				--trash_b;
			(ft_lst_size(env->list_b) > 1) ? env->tab_order[6](env) : 0;
		}
	}
	total = ft_lst_size(env->list_a);
	while (env->list_b || total)
	{
		if (env->list_b && ((VAL_B->content < VAL_A->content)
			|| total == 0))
			env->tab_order[3](env);
		else
			--total;
		env->tab_order[5](env);
	}
}

void			launch_nelson(t_env *env, int ltl_trash, int stack, int size)
{
	size = ft_lst_size(env->list_a) / 2;
	while (size)
	{
		env->tab_order[4](env);
		size--;
	}
	size = ft_lst_size(env->list_a);
	nelson_two(env);
	stack = 4;
	size = ft_lst_size(env->list_b);
	while (stack <= size)
	{
		nelson_grow(env, stack, stack / 2);
		stack *= 2;
	}
	stack /= 2;
	ltl_trash = ft_lst_size(env->list_a) - stack;
	put_b_except_trash(env, stack, stack);
	merge_trash(env, ltl_trash, (ft_lst_size(env->list_b) + ltl_trash),
				ft_lst_size(env->list_b));
}
