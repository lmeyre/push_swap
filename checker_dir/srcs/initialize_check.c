/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 00:19:36 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/12 00:09:36 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	verif(int argc, char **argv, int j)
{
	int i;

	i = 0;
	--j;
	while (++j < argc)
	{
		while (argv[j][i])
		{
			if ((ft_isdigit(argv[j][i]) != 1 && argv[j][i] != ' '
				&& argv[j][i] != '-')
				|| (argv[j][i] == '-' && !((i == 0 || argv[j][i - 1] == ' ')
				&& (argv[j][i + 1] <= '9' && argv[j][i + 1] >= '0'))))
				return (-1);
			++i;
		}
		i = 0;
	}
	return (0);
}

static int	verif_double(t_list *lst, t_env *env)
{
	t_list	*check;
	int		i;
	int		j;

	i = 0;
	j = 0;
	check = env->list_a;
	while (lst)
	{
		while (check)
		{
			if (*(int*)check->content == *(int*)lst->content && j != i)
			{
				ft_putendl("Error");
				return (0);
			}
			check = check->next;
			++j;
		}
		j = 0;
		++i;
		lst = lst->next;
		check = env->list_a;
	}
	return (1);
}

static int	fill_arg(t_env *env, int arg, char **argv, char **tab_arg)
{
	t_list	*tmp;

	env->list_b = NULL;
	tmp = env->list_a;
	while (argv[arg])
	{
		if (!(ft_lst_add_end(&tmp, ft_lst_new(sizeof(int*)))))
			return (0);
		tmp = tmp->next;
		if (ft_is_integer(tab_arg[env->tmp]) == 0)
		{
			ft_putstr("Error\n");
			return (0);
		}
		(*(int*)tmp->content) = ft_atoi(tab_arg[(env->tmp)++]);
		if (tab_arg[env->tmp] == NULL)
		{
			env->tmp = 0;
			arg++;
			ft_free_strtab(&tab_arg);
			if (argv[arg] && !(tab_arg = ft_strsplit(argv[arg], ' ')))
				return (0);
		}
	}
	return (1);
}

static int	get_arg(t_env *env, int arg, char **argv, int argc)
{
	char **tab_arg;

	env->tmp = 0;
	if (!(env->list_a = ft_lst_new(sizeof(int*)))
		|| !(tab_arg = ft_strsplit(argv[arg], ' ')))
		return (0);
	if (ft_is_integer(tab_arg[env->tmp]) == 0)
	{
		ft_putstr("Error\n");
		ft_free_strtab(&tab_arg);
		return (0);
	}
	(VAL_A->content) = ft_atoi(tab_arg[(env->tmp)++]);
	if (tab_arg[env->tmp] == NULL)
	{
		ft_free_strtab(&tab_arg);
		env->tmp = 0;
		arg++;
		if (argc == 2)
			return (1);
		if (argv[arg] && !(tab_arg = ft_strsplit(argv[arg], ' ')))
			return (0);
	}
	return (fill_arg(env, arg, argv, tab_arg));
}

t_env		*initialize_arg(int argc, char **argv)
{
	t_env	*env;
	int		arg;

	arg = 1;
	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	env->list_a = NULL;
	env->list_b = NULL;
	if (!(bonus_flag(env, argv, &arg)) || (verif(argc, argv, arg) == -1))
	{
		ft_putendl("Error");
		free(env);
		return (NULL);
	}
	if (!(get_arg(env, arg, argv, argc)) || init_tab(env) == 0)
	{
		free_env(env);
		return (NULL);
	}
	if (verif_double(env->list_a, env) == 0)
	{
		free_env(env);
		return (NULL);
	}
	return (env);
}
