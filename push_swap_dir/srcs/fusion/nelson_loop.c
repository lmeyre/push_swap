/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nelson_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 22:48:48 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/03 23:00:50 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		fill_looping(t_env *env, int tmp_stack, int tmp_stackish, int *way)
{
	if (*way == -1)
	{
		while (tmp_stack > 0 || tmp_stackish > 0)
		{
			if ((VAL_B->content < VAL_A->content
			&& tmp_stackish > 0) || tmp_stack == 0)
			{
				--tmp_stackish;
				env->tab_order[3](env);
			}
			else
				tmp_stack--;
			env->tab_order[5](env);
		}
	}
	*way *= -1;
}

void		looping(t_env *env, int stack, int loop, int way)
{
	int tmp_stack;
	int tmp_stackish;

	while (loop)
	{
		tmp_stackish = stack / 2;
		tmp_stack = stack / 2;
		if (way == 1)
		{
			while (tmp_stack > 0 || tmp_stackish > 0)
			{
				if ((VAL_A->content < VAL_B->content
					&& tmp_stackish > 0) || tmp_stack == 0)
				{
					--tmp_stackish;
					env->tab_order[4](env);
				}
				else
					tmp_stack--;
				env->tab_order[6](env);
			}
		}
		fill_looping(env, tmp_stack, tmp_stackish, &way);
		--loop;
	}
}

static void	mini_fill_loop(t_env *env, int *amount_b)
{
	if (VAL_A->content < VAL_B->content)
	{
		env->tab_order[4](env);
		env->tab_order[6](env);
	}
	else
	{
		env->tab_order[6](env);
		--(*amount_b);
	}
}

static void	fill_first_loop(t_env *env, int amount_b)
{
	mini_fill_loop(env, &amount_b);
	if (amount_b == 0)
	{
		env->tab_order[4](env);
		env->tab_order[6](env);
		env->tab_order[4](env);
		env->tab_order[6](env);
	}
	else if (VAL_A->content < VAL_B->content)
	{
		env->tab_order[4](env);
		env->tab_order[6](env);
		env->tab_order[6](env);
	}
	else
	{
		env->tab_order[6](env);
		env->tab_order[4](env);
		env->tab_order[6](env);
	}
}

void		first_loop(t_env *env)
{
	if (ft_lst_size(env->list_b) % 2 > 0 && ft_lst_size(env->list_a) % 2 > 0)
	{
		if (VAL_A->content < VAL_B->content)
		{
			env->tab_order[4](env);
			env->tab_order[6](env);
			env->tab_order[6](env);
		}
		else
		{
			env->tab_order[6](env);
			env->tab_order[4](env);
			env->tab_order[6](env);
		}
	}
	else if (ft_lst_size(env->list_b) % 2 > 0 &&
			ft_lst_size(env->list_a) % 2 == 0)
		fill_first_loop(env, 1);
	else if (ft_lst_size(env->list_a) % 2 > 0 &&
			ft_lst_size(env->list_b) % 2 == 0)
	{
		env->tab_order[4](env);
		env->tab_order[6](env);
	}
}
