/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_swap_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 00:29:29 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/04 00:31:53 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pb(t_env *env)
{
	++(env->action);
	(env->action == env->final && env->c_flag && env->real)
	? ft_putstr("\x1B[31m") : 0;
	if (env->real == 1)
		ft_putendl("pb");
	(env->action == env->final && env->c_flag && env->real)
	? ft_putstr("\x1b[40m\x1B[37m") : 0;
	if (!(env->list_a))
	{
		ft_putstr("PB ERROR\n");
		return ;
	}
	if (env->list_b != NULL)
	{
		ft_lst_add(&(env->list_b), ft_lst_new(sizeof(int*)));
		VAL_B->content = VAL_A->content;
	}
	else if (env->list_b == NULL)
	{
		env->list_b = ft_lst_new(sizeof(int*));
		VAL_B->content = VAL_A->content;
	}
	env->list_a = ft_lst_del_one(&env->list_a, 1);
	check_flag(env);
}

void	pa(t_env *env)
{
	++(env->action);
	(env->action == env->final && env->c_flag && env->real)
	? ft_putstr("\x1B[31m") : 0;
	if (env->real == 1)
		ft_putendl("pa");
	(env->action == env->final && env->c_flag && env->real)
	? ft_putstr("\x1b[40m\x1B[37m") : 0;
	if (!(env->list_b))
	{
		ft_putstr("PA ERROR\n");
		return ;
	}
	if (env->list_a != NULL)
	{
		ft_lst_add(&(env->list_a), ft_lst_new(sizeof(int*)));
		VAL_A->content = VAL_B->content;
	}
	else if (env->list_a == NULL)
	{
		env->list_a = ft_lst_new(sizeof(int*));
		VAL_A->content = VAL_B->content;
	}
	env->list_b = ft_lst_del_one(&env->list_b, 1);
	check_flag(env);
}

void	sa(t_env *env)
{
	t_list	*tmp;

	if (env->both == 0)
		++(env->action);
	(env->action == env->final && env->c_flag && env->both == 0 && env->real)
	? ft_putstr("\x1B[31m") : 0;
	if (env->both == 0 && env->real == 1)
		ft_putendl("sa");
	(env->action == env->final && env->c_flag && env->both == 0 && env->real)
	? ft_putstr("\x1b[40m\x1B[37m") : 0;
	tmp = NULL;
	if (!(env->list_a) || !(env->list_a->next))
		return ;
	if (env->list_a->next->next)
		tmp = env->list_a->next->next;
	else
		tmp = NULL;
	env->list_a->next->next = env->list_a;
	env->list_a->next->prev = env->list_a->prev;
	env->list_a->prev = env->list_a->next;
	env->list_a->next = tmp;
	(tmp) ? tmp->prev = env->list_a : 0;
	env->list_a = env->list_a->prev;
	(env->both == 0) ? check_flag(env) : 0;
}

void	sb(t_env *env)
{
	t_list	*tmp;

	if (env->both == 0)
		++(env->action);
	(env->action == env->final && env->c_flag && env->both == 0 && env->real)
	? ft_putstr("\x1B[31m") : 0;
	if (env->both == 0 && env->real == 1)
		ft_putendl("sb");
	(env->action == env->final && env->c_flag && env->both == 0 && env->real)
	? ft_putstr("\x1b[40m\x1B[37m") : 0;
	tmp = NULL;
	if (!(env->list_b) || !(env->list_b->next))
		return ;
	if (env->list_b->next->next)
		tmp = env->list_b->next->next;
	else
		tmp = NULL;
	env->list_b->next->next = env->list_b;
	env->list_b->next->prev = env->list_b->prev;
	env->list_b->prev = env->list_b->next;
	env->list_b->next = tmp;
	(tmp) ? tmp->prev = env->list_b : 0;
	env->list_b = env->list_b->prev;
	(env->both == 0) ? check_flag(env) : 0;
}

void	ss(t_env *env)
{
	++(env->action);
	(env->action == env->final && env->c_flag && env->real == 1)
	? ft_putstr("\x1B[31m") : 0;
	if (env->real == 1)
		ft_putendl("ss");
	(env->action == env->final && env->c_flag && env->real == 1)
	? ft_putstr("\x1b[40m\x1B[37m") : 0;
	env->both = 1;
	sa(env);
	sb(env);
	check_flag(env);
	env->both = 0;
}
