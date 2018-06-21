/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 00:13:47 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/04 00:15:14 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	fill_lst_two(t_env *env)
{
	env->action = env->action_tmp;
	if (env->list_a)
		ft_lst_del_all(&env->list_a);
	if (env->list_b)
		ft_lst_del_all(&env->list_b);
	env->list_a = env->tmp_a;
	env->list_b = env->tmp_b;
	env->tmp_a = NULL;
	env->tmp_b = NULL;
}

int			sort_lst_two(t_env *env)
{
	if (env->list_a)
		if (!(env->tmp_a = ft_lst_int_copy(env->list_a)))
			return (0);
	if (env->list_b)
		if (!(env->tmp_b = ft_lst_int_copy(env->list_b)))
			return (0);
	env->action_tmp = env->action;
	finish_fill_a(env);
	while (env->list_a->next->next != NULL)
		put_lowest(env);
	if (VAL_A->content > VAL_A->next->content)
		env->tab_order[0](env);
	while (env->list_b != NULL)
		env->tab_order[3](env);
	if (env->best_action == 0 || env->best_action > env->action)
	{
		if (!lst_sorted(env->list_a) || env->list_b)
			ft_putendl("ERROR");
		env->best_action = env->action;
		env->jumping = env->fake_jumping;
		env->out = 2;
	}
	fill_lst_two(env);
	return (1);
}

void		put_lowest(t_env *env)
{
	int		lowest;
	int		index;
	t_list	*start;
	int		size;

	size = 0;
	start = env->list_a;
	lowest = get_lower(env->list_a);
	index = get_index(env->list_a, lowest);
	while (env->list_a)
	{
		size++;
		env->list_a = env->list_a->next;
	}
	env->list_a = start;
	if (index > (size / 2) + 1)
		while (VAL_A->content != lowest)
			env->tab_order[8](env);
	else
		while (VAL_A->content != lowest)
			env->tab_order[5](env);
	env->tab_order[4](env);
}

void		put_bigger(t_env *env)
{
	int		bigger;
	int		index;
	t_list	*start;
	int		size;

	size = 0;
	start = env->list_b;
	bigger = get_bigger(env->list_b);
	index = get_index(env->list_b, bigger);
	while (env->list_b)
	{
		size++;
		env->list_b = env->list_b->next;
	}
	env->list_b = start;
	if (index > size / 2)
		while (VAL_B->content != bigger)
			env->tab_order[9](env);
	else
		while (VAL_B->content != bigger)
			env->tab_order[6](env);
	env->tab_order[3](env);
}
