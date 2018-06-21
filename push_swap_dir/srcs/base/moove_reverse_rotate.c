/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 00:26:14 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/04 00:27:38 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		rra(t_env *env)
{
	t_list	*tmp;

	if (env->both == 0)
		++(env->action);
	(env->action == env->final && env->c_flag && env->real && env->both == 0)
	? ft_putstr("\x1B[31m") : 0;
	if (env->both == 0 && env->real == 1)
		ft_putendl("rra");
	(env->action == env->final && env->c_flag && env->real && env->both == 0)
	? ft_putstr("\x1b[40m\x1B[37m") : 0;
	if (!(env->list_a))
	{
		ft_putstr("RRA ERROR\n");
		return ;
	}
	if (!(env->list_a->next))
		return ;
	ft_lst_add(&env->list_a, ft_lst_new(sizeof(int*)));
	tmp = env->list_a;
	while (tmp->next)
		tmp = tmp->next;
	VAL_A->content = *(int*)tmp->content;
	env->list_a = ft_lst_del_last(&env->list_a);
	if (env->both == 0)
		check_flag(env);
}

void		rrb(t_env *env)
{
	t_list	*tmp;

	if (env->both == 0)
		++(env->action);
	(env->action == env->final && env->c_flag && env->real && env->both == 0)
	? ft_putstr("\x1B[31m") : 0;
	if (env->both == 0 && env->real == 1)
		ft_putendl("rrb");
	(env->action == env->final && env->c_flag && env->real && env->both == 0)
	? ft_putstr("\x1b[40m\x1B[37m") : 0;
	if (!(env->list_b))
	{
		ft_putstr("RRB ERROR\n");
		return ;
	}
	if (!(env->list_b->next))
		return ;
	ft_lst_add(&env->list_b, ft_lst_new(sizeof(int*)));
	tmp = env->list_b;
	while (tmp->next)
		tmp = tmp->next;
	VAL_B->content = *(int*)tmp->content;
	env->list_b = ft_lst_del_last(&env->list_b);
	if (env->both == 0)
		check_flag(env);
}

void		rrr(t_env *env)
{
	++(env->action);
	(env->action == env->final && env->c_flag && env->real == 1)
	? ft_putstr("\x1B[31m") : 0;
	if (env->real == 1)
		ft_putendl("rrr");
	(env->action == env->final && env->c_flag && env->real == 1)
	? ft_putstr("\x1b[40m\x1B[37m") : 0;
	env->both = 1;
	rra(env);
	rrb(env);
	check_flag(env);
	env->both = 0;
}
