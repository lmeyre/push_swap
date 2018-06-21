/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 00:27:46 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/04 00:29:21 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		ra(t_env *env)
{
	t_list	*tmp;

	if (!env->list_a || !(env->list_a->next))
		return (1);
	(env->both == 0) ? ++(env->action) : 0;
	(env->real && env->both == 0) ? ft_putendl("ra") : 0;
	if (!(tmp = ft_lst_new(sizeof(int*))))
		return (0);
	if (!(ft_lst_add_end(&env->list_a, tmp)))
		return (1);
	tmp = env->list_a;
	while (tmp->next)
		tmp = tmp->next;
	*(int*)tmp->content = VAL_A->content;
	env->list_a = ft_lst_del_one(&env->list_a, 1);
	return (1);
}

int		rb(t_env *env)
{
	t_list	*tmp;

	if (!env->list_b || !(env->list_b->next))
		return (1);
	(env->both == 0) ? ++(env->action) : 0;
	(env->real && env->both == 0) ? ft_putendl("rb") : 0;
	if (!(tmp = ft_lst_new(sizeof(int*))))
		return (0);
	if (!(ft_lst_add_end(&env->list_b, tmp)))
		return (1);
	tmp = env->list_b;
	while (tmp->next)
		tmp = tmp->next;
	*(int*)tmp->content = VAL_B->content;
	env->list_b = ft_lst_del_one(&env->list_b, 1);
	return (1);
}

int		rr(t_env *env)
{
	++(env->action);
	env->both = 1;
	env->real ? ft_putendl("rr") : 0;
	if (!ra(env) || !rb(env))
		return (0);
	env->both = 0;
	return (1);
}
