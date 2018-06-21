/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 01:14:22 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/12 01:14:34 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	right_algo(t_env *env)
{
	env->real = 1;
	env->action = 0;
	env->final = 0;
	if (env->list_a)
		ft_lst_del_all(&(env->list_a));
	if (env->list_b)
		ft_lst_del_all(&(env->list_b));
	call_best(env);
	if (env->a_flag == 1)
	{
		ft_putstr("Instructions : ");
		ft_putnbrn(env->action);
	}
}

int		main_ltl_list(t_env *env)
{
	if (ft_lst_size(env->list_a) < 4)
	{
		env->real = 1;
		exception_little(env);
		if (env->a_flag == 1)
		{
			ft_putstr("Instructions : ");
			ft_putnbrn(env->action);
		}
		ft_lst_del_all(&(env->origin_a));
		ft_lst_del_all(&(env->origin_b));
		return (0);
	}
	return (1);
}
