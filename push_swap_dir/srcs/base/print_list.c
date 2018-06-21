/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 00:32:03 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/04 00:32:51 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
	else
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
