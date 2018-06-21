/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 00:49:14 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/19 09:26:52 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	fill_checker_global(int i, char *wrote, t_env *env)
{
	if (i >= 11)
	{
		if ((wrote[0]) == 0)
			return (1);
		else
			ft_putendl("Error");
		return (0);
	}
	else
	{
		if (env->tab_order[i](env) == 0)
		{
			ft_putstr("Error\n");
			return (0);
		}
	}
	return (42);
}

static int	checker_global(int argc, t_env *env, char **wrote)
{
	int		i;
	char	**order;
	int		tmp;

	i = 0;
	if (argc < 2)
		return (-1);
	order = ft_strsplit("rra rrb rrr sa sb ss pa pb ra rb rr ", ' ');
	while ((get_next_line(0, wrote)))
	{
		while (order[i] && (ft_strcmp(*wrote, order[i])) != 0)
			++i;
		if ((tmp = fill_checker_global(i, *wrote, env)) != 42)
		{
			ft_strdel(wrote);
			ft_free_strtab(&order);
			return (tmp);
		}
		ft_strdel(wrote);
		i = 0;
		env->v_flag ? print_list(env) : 0;
	}
	ft_free_strtab(&order);
	ft_strdel(wrote);
	return (1);
}

int			main(int argc, char **argv)
{
	t_env	*env;
	char	*wrote;

	wrote = NULL;
	if ((argc == 1) || !(env = initialize_arg(argc, argv)))
		return (0);
	env->v_flag ? print_list(env) : 0;
	if (checker_global(argc, env, &wrote) == 0)
	{
		free_env(env);
		return (0);
	}
	ft_strdel(&wrote);
	if (env->a_flag)
	{
		ft_putstr("Instructions = ");
		ft_putnbrn(env->action);
	}
	if (lst_sorted(env->list_a) && !env->list_b)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	free_env(env);
	return (0);
}
