/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 00:04:51 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/12 00:06:08 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../../libft/includes/libft.h"
# define VAL_A *(int*)env->list_a
# define VAL_B *(int*)env->list_b

typedef	struct		s_env
{
	t_list			*list_a;
	t_list			*list_b;
	int				(*tab_order[11])(struct s_env *env);
	int				tmp;
	int				both;
	int				action;
	int				real;
	int				a_flag;
	int				v_flag;
}					t_env;

t_env				*initialize_arg(int argc, char **argv);
int					init_tab(t_env *env);
void				free_env(t_env *env);
int					lst_sorted(t_list *lst);
int					bonus_flag(t_env *env, char **argv, int *arg);
int					pa(t_env *env);
int					pb(t_env *env);
int					sa(t_env *env);
int					sb(t_env *env);
int					ss(t_env *env);
int					ra(t_env *env);
int					rb(t_env *env);
int					rr(t_env *env);
int					rra(t_env *env);
int					rrb(t_env *env);
int					rrr(t_env *env);

void				print_list(t_env *env);
#endif
