/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst_four.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 00:05:30 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/04 00:06:48 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_list_four(t_env *env, int off)
{
	if (off)
		put_larger_accessible(env);
	else
		put_smaller_accessible(env);
}

void	put_larger_accessible(t_env *env)
{
	while (env->list_b)
	{
		if (!env->list_b->next)
			env->tab_order[3](env);
		else if ((*(int*)ft_lst_getend(env->list_b)->content
		> VAL_B->next->content)
		&& (*(int*)ft_lst_getend(env->list_b)->content > VAL_B->content))
			env->tab_order[9](env);
		else if ((VAL_B->next->content > VAL_B->content)
		&& (VAL_B->next->content > *(int*)ft_lst_getend(env->list_b)->content))
			env->tab_order[1](env);
		else
			env->tab_order[3](env);
	}
}

void	put_smaller_accessible(t_env *env)
{
	while (env->list_a)
	{
		if (!env->list_a->next)
			env->tab_order[4](env);
		else if ((*(int*)ft_lst_getend(env->list_a)->content
			< VAL_A->next->content)
			&& (*(int*)ft_lst_getend(env->list_a)->content < VAL_A->content))
			env->tab_order[8](env);
		else if ((VAL_A->next->content < VAL_A->content)
		&& (VAL_A->next->content < *(int*)ft_lst_getend(env->list_a)->content))
			env->tab_order[0](env);
		else
			env->tab_order[4](env);
	}
}
