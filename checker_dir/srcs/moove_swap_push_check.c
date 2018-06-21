/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_swap_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 00:29:29 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/12 00:07:31 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int			pb(t_env *env)
{
	t_list *tmp;

	if (!(env->list_a))
		return (1);
	++(env->action);
	(env->real) ? ft_putendl("pb") : 0;
	if (env->list_b != NULL)
	{
		if (!(tmp = ft_lst_new(sizeof(int*))))
			return (0);
		if (!(ft_lst_add(&(env->list_b), tmp)))
			return (1);
		VAL_B->content = VAL_A->content;
	}
	else if (env->list_b == NULL)
	{
		if (!(env->list_b = ft_lst_new(sizeof(int*))))
			return (0);
		VAL_B->content = VAL_A->content;
	}
	env->list_a = ft_lst_del_one(&env->list_a, 1);
	return (1);
}

int			pa(t_env *env)
{
	t_list *tmp;

	if (!(env->list_b))
		return (1);
	++(env->action);
	(env->real) ? ft_putendl("pa") : 0;
	if (env->list_a != NULL)
	{
		if (!(tmp = ft_lst_new(sizeof(int*))))
			return (0);
		if (!(ft_lst_add(&(env->list_a), tmp)))
			return (1);
		VAL_A->content = VAL_B->content;
	}
	else if (env->list_a == NULL)
	{
		if (!(env->list_a = ft_lst_new(sizeof(int*))))
			return (0);
		VAL_A->content = VAL_B->content;
	}
	env->list_b = ft_lst_del_one(&env->list_b, 1);
	return (1);
}

int			sa(t_env *env)
{
	t_list	*tmp;

	tmp = NULL;
	if (!(env->list_a) || !(env->list_a->next))
		return (1);
	(env->both == 0) ? ++(env->action) : 0;
	(env->real && env->both == 0) ? ft_putendl("sa") : 0;
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
	return (1);
}

int			sb(t_env *env)
{
	t_list	*tmp;

	tmp = NULL;
	if (!(env->list_b) || !(env->list_b->next))
		return (1);
	(env->both == 0) ? ++(env->action) : 0;
	(env->real && env->both == 0) ? ft_putendl("sb") : 0;
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
	return (1);
}

int			ss(t_env *env)
{
	env->both = 1;
	++(env->action);
	env->real ? ft_putendl("ss") : 0;
	if (!sa(env) || !sb(env))
		return (0);
	env->both = 0;
	return (1);
}
