/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 00:18:18 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/04 00:19:25 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	fill_init(t_env *env)
{
	env->tab_order[0] = &sa;
	env->tab_order[1] = &sb;
	env->tab_order[2] = &ss;
	env->tab_order[3] = &pa;
	env->tab_order[4] = &pb;
	env->tab_order[5] = &ra;
	env->tab_order[6] = &rb;
	env->tab_order[7] = &rr;
	env->tab_order[8] = &rra;
	env->tab_order[9] = &rrb;
	env->tab_order[10] = &rrr;
}

int			init_tab(t_env *env)
{
	env->anti_static = 42;
	env->four_opti = 0;
	env->jumping = 0;
	env->fake_jumping = 0;
	env->out = 0;
	env->real = 0;
	env->fusionew = 0;
	env->lst_ltl = 0;
	env->both = 0;
	env->way = 0;
	env->action = 0;
	env->best_action = 0;
	if (!(env->origin_a = ft_lst_int_copy(env->list_a)))
		return (0);
	env->origin_b = NULL;
	env->tmp_a = NULL;
	env->tmp_b = NULL;
	fill_init(env);
	reset_value(env);
	return (1);
}

void		reset_value(t_env *env)
{
	(ft_lst_size(env->list_a) <= 2) ? env->way = 0 : 0;
	if ((ft_lst_size(env->list_b) <= 2) && (lst_sorted(env->list_a) == 0))
		env->way = 1;
	env->sa_bool = 0;
	env->ra_bool = 0;
	env->rra_bool = 0;
	env->sb_bool = 0;
	env->rb_bool = 0;
	env->rrb_bool = 0;
	env->a_bool = 0;
	env->b_bool = 0;
	env->tmp = 0;
}

void		free_env(t_env *env)
{
	if (!env)
		return ;
	if (env->list_a)
		ft_lst_del_all(&(env->list_a));
	if (env->list_b)
		ft_lst_del_all(&(env->list_b));
	if (env->tmp_a)
		ft_lst_del_all(&(env->tmp_a));
	if (env->tmp_b)
		ft_lst_del_all(&(env->tmp_b));
	if (env)
		free(env);
}

int			bonus_flag(t_env *env, char **argv, int *arg)
{
	env->v_flag = 0;
	env->c_flag = 0;
	env->a_flag = 0;
	while (*arg <= 3)
	{
		if (argv[*arg] == NULL)
			return (0);
		if (ft_strcmp(argv[*arg], "-v") == 0)
			env->v_flag = 1;
		else if (ft_strcmp(argv[*arg], "-c") == 0)
			env->c_flag = 1;
		else if (ft_strcmp(argv[*arg], "-a") == 0)
			env->a_flag = 1;
		else
			break ;
		(*arg)++;
	}
	if (argv[*arg] == NULL)
		return (0);
	return (1);
}
