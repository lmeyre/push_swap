/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 22:28:19 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/12 01:14:10 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	choose_algo_fill(t_env *env)
{
	if (ft_lst_size(env->list_a) == 4 || ft_lst_size(env->list_a) == 5)
	{
		if (!(env->tmp_a = ft_lst_int_copy(env->list_a)))
			return (0);
		if (ft_lst_size(env->list_a) == 4 && four_elem_opti(env) == 0)
		{
			env->action = 0;
			ft_lst_del_all(&(env->list_a));
			env->list_a = env->tmp_a;
			if (!(env->tmp_a = ft_lst_int_copy(env->list_a)))
				return (0);
			four_elem(env);
		}
		else if ((ft_lst_size(env->list_a) == 5) && !(five_elem(env, 5)))
			return (0);
		if (lst_sorted(env->list_a) == 0 || env->list_b)
			env->action = 0;
		env->lst_ltl = env->action;
		env->action = 0;
		ft_lst_del_all(&(env->list_a));
		env->list_a = env->tmp_a;
		env->tmp_a = NULL;
	}
	return (1);
}

int			calling_algo(t_env *env)
{
	if (!(choose_algo_fill(env)))
		return (0);
	if (!(env->tmp_a = ft_lst_int_copy(env->list_a)))
		return (0);
	if (ft_lst_size(env->list_a) > 4)
		launch_nelson(env, 0, 0, 0);
	if (lst_sorted(env->list_a) == 0 || env->list_b)
		env->action = 0;
	if (env->list_a)
		ft_lst_del_all(&(env->list_a));
	if (env->list_b)
		ft_lst_del_all(&(env->list_b));
	env->list_b = NULL;
	env->list_a = env->tmp_a;
	env->tmp_a = NULL;
	env->fusionew = env->action;
	env->action = 0;
	if (ft_lst_size(env->list_a) != 4)
		sort_all(env);
	if (lst_sorted(env->list_a) == 0 || env->list_b)
		env->action = 0;
	return (1);
}

void		call_best(t_env *env)
{
	env->list_a = env->origin_a;
	env->list_b = env->origin_b;
	if (env->lst_ltl != 0 && env->lst_ltl != env->four_opti)
		env->final = env->lst_ltl;
	else if (env->four_opti != 0)
		env->final = env->four_opti;
	if (env->fusionew != 0)
		if (env->final == 0 || env->final > env->fusionew)
			env->final = env->fusionew;
	if (env->best_action != 0)
		if (env->final == 0 || env->final > env->best_action)
			env->final = env->best_action;
	if (env->final == env->four_opti)
		four_elem_opti(env);
	else if (env->final == env->lst_ltl)
	{
		if (ft_lst_size(env->list_a) == 4)
			four_elem(env);
		else
			five_elem(env, 5);
	}
	else if (env->final == env->fusionew)
		launch_nelson(env, 0, 0, 0);
	else
		sort_jumping(env);
}

int			main(int argc, char **argv)
{
	t_env		*env;

	env = NULL;
	if (argc < 2 || !(env = initialize_arg(argc, argv, 1)))
	{
		free_env(env);
		return (-1);
	}
	if (lst_sorted(env->list_a) == 1 && env->list_b == NULL)
	{
		ft_lst_del_all(&(env->origin_a));
		ft_lst_del_all(&(env->origin_b));
		free_env(env);
		return (0);
	}
	if (!(main_ltl_list(env)) || (!(calling_algo(env))))
	{
		free_env(env);
		return (0);
	}
	right_algo(env);
	free_env(env);
	return (0);
}
