/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 00:23:02 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/12 00:59:42 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			exception_little(t_env *env)
{
	if (lst_sorted(env->list_a) == 1)
		return (1);
	if (ft_lst_size(env->list_a) == 2)
	{
		env->final = 1;
		if (VAL_A->content > VAL_A->next->content)
			env->tab_order[0](env);
		return (1);
	}
	else if (ft_lst_size(env->list_a) == 3)
	{
		three_elem(env, env->list_a);
		return (1);
	}
	return (0);
}

static void	fill_three_elem(t_env *env, t_list *lst)
{
	if (*(int*)lst->content > *(int*)lst->next->content
			&& *(int*)lst->content < *(int*)lst->next->next->content)
	{
		env->final = 1;
		env->tab_order[0](env);
	}
	else if (*(int*)lst->content < *(int*)lst->next->content
			&& *(int*)lst->content > *(int*)lst->next->next->content)
	{
		env->final = 1;
		env->tab_order[8](env);
	}
}

void		three_elem(t_env *env, t_list *lst)
{
	if (*(int*)lst->content < *(int*)lst->next->content
			&& *(int*)lst->content < *(int*)lst->next->next->content)
	{
		env->tab_order[4](env);
		env->tab_order[0](env);
		env->final = 3;
		env->tab_order[3](env);
	}
	else if (*(int*)lst->content > *(int*)lst->next->content
			&& *(int*)lst->content > *(int*)lst->next->next->content)
	{
		env->final = 1;
		if (VAL_A->next->content > VAL_A->next->next->content)
			env->final = 2;
		env->tab_order[5](env);
		if (VAL_A->content > VAL_A->next->content)
			env->tab_order[0](env);
	}
	else
		fill_three_elem(env, lst);
}

int			five_elem(t_env *env, int x)
{
	t_list *tmp;

	if (!(tmp = ft_lst_int_copy(env->list_a)))
		return (0);
	while (x)
	{
		(wich_side(tmp, VAL_A->content) > 0) ? --x : 0;
		if (wich_side(tmp, VAL_A->content) > 0)
			env->tab_order[4](env);
		else if (wich_side(tmp, VAL_A->content) <= 0
			&& VAL_A->content < VAL_A->next->content)
			env->tab_order[0](env);
		else if (wich_side(tmp, VAL_A->content) <= 0)
		{
			--x;
			env->tab_order[5](env);
		}
	}
	three_elem(env, env->list_a);
	(VAL_B->content < VAL_B->next->content) ? env->tab_order[1](env) : 0;
	env->tab_order[3](env);
	env->final = env->action + 1;
	env->tab_order[3](env);
	ft_lst_del_all(&tmp);
	return (1);
}
