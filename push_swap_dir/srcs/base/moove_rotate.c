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

#include "../../includes/push_swap.h"

void		put_null(t_env *env)
{
	env->list_a = NULL;
	env->list_b = NULL;
	env->tmp_a = NULL;
	env->tmp_b = NULL;
	env->origin_a = NULL;
	env->origin_b = NULL;
}

void		check_flag(t_env *env)
{
	(env->action == env->final && env->c_flag) ? ft_putstr("\x1B[31m") : 0;
	(env->v_flag && env->real) ? print_list(env) : 0;
	(env->action == env->final && env->c_flag)
	? ft_putstr("\x1b[40m\x1B[37m") : 0;
}

void		ra(t_env *env)
{
	t_list	*tmp;

	if (env->both == 0)
		++(env->action);
	(env->action == env->final && env->c_flag && env->both == 0 && env->real)
	? ft_putstr("\x1B[31m") : 0;
	if (env->both == 0 && env->real == 1)
		ft_putendl("ra");
	(env->action == env->final && env->c_flag && env->both == 0 && env->real)
	? ft_putstr("\x1b[40m\x1B[37m") : 0;
	if (!(env->list_a))
	{
		ft_putstr("RA ERROR\n");
		return ;
	}
	if (!(env->list_a->next))
		return ;
	ft_lst_add_end(&env->list_a, ft_lst_new(sizeof(int*)));
	tmp = env->list_a;
	while (tmp->next)
		tmp = tmp->next;
	*(int*)tmp->content = VAL_A->content;
	env->list_a = ft_lst_del_one(&env->list_a, 1);
	if (env->both == 0)
		check_flag(env);
}

void		rb(t_env *env)
{
	t_list	*tmp;

	if (env->both == 0)
		++(env->action);
	(env->action == env->final && env->c_flag && env->both == 0 && env->real)
	? ft_putstr("\x1B[31m") : 0;
	if (env->both == 0 && env->real == 1)
		ft_putendl("rb");
	(env->action == env->final && env->c_flag && env->both == 0 && env->real)
	? ft_putstr("\x1b[40m\x1B[37m") : 0;
	if (!(env->list_b))
		return ;
	if (!(env->list_b->next))
		return ;
	ft_lst_add_end(&env->list_b, ft_lst_new(sizeof(int*)));
	tmp = env->list_b;
	while (tmp->next)
		tmp = tmp->next;
	*(int*)tmp->content = VAL_B->content;
	env->list_b = ft_lst_del_one(&env->list_b, 1);
	if (env->both == 0)
		check_flag(env);
}

void		rr(t_env *env)
{
	++(env->action);
	(env->action == env->final && env->c_flag && env->real == 1)
	? ft_putstr("\x1B[31m") : 0;
	if (env->real == 1)
		ft_putendl("rr");
	(env->action == env->final && env->c_flag && env->real == 1)
	? ft_putstr("\x1b[40m\x1B[37m") : 0;
	env->both = 1;
	ra(env);
	rb(env);
	check_flag(env);
	env->both = 0;
}
