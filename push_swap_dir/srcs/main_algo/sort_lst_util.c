/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 00:16:22 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/04 00:17:37 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		wich_side(t_list *lst, int value)
{
	int balance;

	balance = 0;
	while (lst)
	{
		if (*(int*)lst->content > value)
			balance++;
		if (*(int*)lst->content < value)
			balance--;
		lst = lst->next;
	}
	return (balance);
}

int		lst_sorted(t_list *lst)
{
	t_list			*tmp;
	long long int	bigger;

	if (lst == NULL)
		return (0);
	bigger = *(int*)lst->content;
	tmp = lst->next;
	while (tmp)
	{
		if (*(int*)tmp->content <= bigger)
			return (0);
		else
			bigger = *(int*)tmp->content;
		tmp = tmp->next;
	}
	return (1);
}

void	finish_fill_b(t_env *env)
{
	if (env->list_a)
	{
		if (wich_side(env->list_b, VAL_A->content) > 0
		&& wich_side(env->list_b, VAL_A->next->content) > 0
		&& VAL_A->content < VAL_A->next->content)
			env->tab_order[0](env);
		env->tab_order[4](env);
		if (wich_side(env->list_b, VAL_B->content) > 0)
			env->tab_order[6](env);
		else if (VAL_B->content < VAL_B->next->content)
			env->tab_order[1](env);
		env->tab_order[4](env);
		if (wich_side(env->list_b, VAL_B->content) > 0)
			env->tab_order[6](env);
		else if (VAL_B->content < VAL_B->next->content)
			env->tab_order[1](env);
	}
}

void	finish_fill_a(t_env *env)
{
	if (env->list_b)
	{
		if (wich_side(env->list_a, VAL_B->content) <= 0
		&& wich_side(env->list_a, VAL_B->next->content) <= 0
		&& VAL_B->content > VAL_B->next->content)
			env->tab_order[1](env);
		env->tab_order[3](env);
		if (wich_side(env->list_a, VAL_A->content) <= 0)
			env->tab_order[5](env);
		else if (VAL_A->content > VAL_A->next->content)
			env->tab_order[0](env);
		env->tab_order[3](env);
		if (wich_side(env->list_a, VAL_A->content) <= 0)
			env->tab_order[5](env);
		else if (VAL_A->content > VAL_A->next->content)
			env->tab_order[0](env);
	}
}
