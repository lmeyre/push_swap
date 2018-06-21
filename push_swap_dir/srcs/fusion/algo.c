/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 22:32:53 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/03 22:46:32 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		fill_nelson_exception(t_env *env,
				int *top_a, int *top_b, int stackish)
{
	int tmp_stack;

	tmp_stack = stackish;
	while (tmp_stack || stackish)
	{
		if ((VAL_B->content < VAL_A->content && stackish > 0)
			|| tmp_stack == 0)
		{
			--stackish;
			--(*top_b);
			env->tab_order[3](env);
		}
		else
		{
			--(*top_a);
			--tmp_stack;
		}
		env->tab_order[5](env);
	}
}

static void		fill_nelson_exception_bis(t_env *env,
		int top_a, int top_b, int stack)
{
	while (((top_a > 0 || top_b > 0) && stack > 4))
	{
		if ((VAL_A->content < VAL_B->content && top_a > 0)
			|| top_b == 0)
		{
			--top_a;
			env->tab_order[4](env);
		}
		else
			--top_b;
		env->tab_order[6](env);
	}
}

void			nelson_exception(t_env *env,
				int stack, int stackish, int exception)
{
	static int	trash = 0;
	int			top_a;
	int			top_b;

	if (env->real == 1 && env->anti_static == 42)
	{
		trash = 0;
		env->anti_static = -42;
	}
	top_a = ft_lst_size(env->list_a) % stack;
	top_b = ft_lst_size(env->list_b) % stack;
	((ft_lst_size(env->list_b) / stack) < (ft_lst_size(env->list_a) / stack))
	? top_a += stack : 0;
	((ft_lst_size(env->list_b) / stack) > (ft_lst_size(env->list_a) / stack))
	? top_b += stack : 0;
	if (exception == 1)
		fill_nelson_exception(env, &top_a, &top_b, stackish);
	if (trash == 0 && stack == 4)
		first_loop(env);
	fill_nelson_exception_bis(env, top_a, top_b, stack);
	++trash;
}

void			nelson_grow(t_env *env, int stack, int stackish)
{
	int size;
	int exception;
	int loop;

	size = (ft_lst_size(env->list_b) < ft_lst_size(env->list_a))
	? ft_lst_size(env->list_b) : ft_lst_size(env->list_a);
	exception = 0;
	loop = size / stackish;
	if (loop % 2 == 1)
	{
		loop--;
		exception = 1;
	}
	looping(env, stack, loop, 1);
	if (exception == 1 || ft_lst_size(env->list_b) % stackish > 0
	|| ft_lst_size(env->list_a) % stackish > 0 || ((ft_lst_size(env->list_b)
	/ stackish) != (ft_lst_size(env->list_a) / stackish)))
		nelson_exception(env, stack, stackish, exception);
}
