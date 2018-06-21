/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 00:07:53 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/12 00:08:22 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int			lst_sorted(t_list *lst)
{
	t_list			*tmp;
	long long int	bigger;

	if (lst == NULL)
		return (0);
	bigger = *(int*)lst->content;
	tmp = lst->next;
	while (tmp)
	{
		if (*(int*)tmp->content <= bigger)
			return (0);
		else
			bigger = *(int*)tmp->content;
		tmp = tmp->next;
	}
	return (1);
}

int			init_tab(t_env *env)
{
	env->tmp = 0;
	env->both = 0;
	env->action = 0;
	env->list_b = NULL;
	env->tab_order[0] = &rra;
	env->tab_order[1] = &rrb;
	env->tab_order[2] = &rrr;
	env->tab_order[3] = &sa;
	env->tab_order[4] = &sb;
	env->tab_order[5] = &ss;
	env->tab_order[6] = &pa;
	env->tab_order[7] = &pb;
	env->tab_order[8] = &ra;
	env->tab_order[9] = &rb;
	env->tab_order[10] = &rr;
	return (1);
}

static void	print_a(t_env *env)
{
	while (env->list_a->prev)
		env->list_a = env->list_a->prev;
	while (env->list_a->next)
	{
		ft_putnbrn(VAL_A->content);
		env->list_a = env->list_a->next;
	}
	if (env->list_a->content)
		ft_putnbrn(VAL_A->content);
	while (env->list_a->prev)
		env->list_a = env->list_a->prev;
}

void		print_list(t_env *env)
{
	ft_putendl("Liste A --|");
	if (env->list_a == NULL)
		ft_putendl("NULL");
	else
		print_a(env);
	ft_putendl("Liste B --|");
	if (env->list_b == NULL)
		ft_putendl("NULL");
	else
	{
		while (env->list_b->prev)
			env->list_b = env->list_b->prev;
		while (env->list_b->next)
		{
			ft_putnbrn(VAL_B->content);
			env->list_b = env->list_b->next;
		}
		if (env->list_b->content)
			ft_putnbrn(VAL_B->content);
		while (env->list_b->prev)
			env->list_b = env->list_b->prev;
	}
	ft_putchar('\n');
}

int			bonus_flag(t_env *env, char **argv, int *arg)
{
	env->v_flag = 0;
	env->a_flag = 0;
	env->real = 0;
	while (*arg <= 3)
	{
		if (argv[*arg] == NULL)
			return (0);
		if (ft_strcmp(argv[*arg], "-v") == 0)
			env->v_flag = 1;
		else if (ft_strcmp(argv[*arg], "-r") == 0)
			env->real = 1;
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
