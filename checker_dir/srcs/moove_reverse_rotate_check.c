/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 00:26:14 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/21 16:26:58 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	free_env(t_env *env)
{
	if (!env)
		return ;
	if (env->list_a)
		ft_lst_del_all(&(env->list_a));
	if (env->list_b)
		ft_lst_del_all(&(env->list_b));
	if (env)
		free(env);
}

int		rra(t_env *env)
{
	t_list	*tmp;

	if (!env->list_a || !(env->list_a->next))
		return (1);
	(env->both == 0) ? ++(env->action) : 0;
	(env->real && env->both == 0) ? ft_putendl("rra") : 0;
	if (!(tmp = ft_lst_new(sizeof(int*))))
		return (0);
	if (!(ft_lst_add(&env->list_a, tmp)))
		return (1);
	tmp = env->list_a;
	while (tmp->next)
		tmp = tmp->next;
	VAL_A->content = *(int*)tmp->content;
	env->list_a = ft_lst_del_last(&env->list_a);
	return (1);
}

int		rrb(t_env *env)
{
	t_list	*tmp;

	if (!env->list_b || !(env->list_b->next))
		return (1);
	(env->both == 0) ? ++(env->action) : 0;
	(env->real && env->both == 0) ? ft_putendl("rrb") : 0;
	if (!(tmp = ft_lst_new(sizeof(int*))))
		return (0);
	if (!(ft_lst_add(&env->list_b, tmp)))
		return (1);
	tmp = env->list_b;
	while (tmp->next)
		tmp = tmp->next;
	VAL_B->content = *(int*)tmp->content;
	env->list_b = ft_lst_del_last(&env->list_b);
	return (1);
}

int		rrr(t_env *env)
{
	++(env->action);
	env->both = 1;
	env->real ? ft_putendl("rrr") : 0;
	if (!rra(env) || !rrb(env))
		return (0);
	env->both = 0;
	return (1);
}
