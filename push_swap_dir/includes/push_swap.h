/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:47:29 by lmeyre            #+#    #+#             */
/*   Updated: 2018/03/03 19:27:20 by lmeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../../libft/includes/libft.h"
# define VAL_A *(int*)env->list_a
# define VAL_B *(int*)env->list_b

typedef	struct		s_env
{
	t_list			*list_a;
	t_list			*list_b;
	t_list			*tmp_a;
	t_list			*tmp_b;
	t_list			*origin_a;
	t_list			*origin_b;
	int				both;
	void			(*tab_order[11])(struct s_env *env);
	int				way;
	int				a_bool;
	int				sa_bool;
	int				ra_bool;
	int				rra_bool;
	int				b_bool;
	int				sb_bool;
	int				rb_bool;
	int				rrb_bool;
	int				tmp;
	int				action;
	int				action_tmp;
	int				best_action;
	int				best_index;
	int				three_max;
	int				three_min;
	int				four_opti;
	int				fusionew;
	int				lst_ltl;
	int				real;
	int				jumping;
	int				fake_jumping;
	int				out;
	int				anti_static;
	int				v_flag;
	int				c_flag;
	int				a_flag;
	int				final;
}					t_env;

int					calling_algo(t_env *env);
void				call_best(t_env *env);
t_env				*initialize_arg(int argc, char **argv, int arg);
int					init_tab(t_env *env);
void				free_env(t_env *env);
void				right_algo(t_env *env);
int					main_ltl_list(t_env *env);
void				put_null(t_env *env);

int					exception_little(t_env *env);
void				three_elem(t_env *env, t_list *lst);
void				four_elem(t_env *env);
int					four_elem_opti(t_env *env);
int					five_elem(t_env *env, int x);

void				sort_jumping(t_env *env);
int					sort_all(t_env *env);

void				sort_lst_one(t_env *env);
void				lst_one_exception(t_env *env, int tmp);
int					prepare_transition(t_env *env, int tmp);
void				check_lst_b(t_env *env);
void				to_b(t_env *env);
void				do_the_job_b(t_env *env, int half);
void				keep_ltl_b(t_env *env, int a, int b, int c);
void				keep_big_b(t_env *env, int a, int b, int c);
void				check_lst_a(t_env *env);
void				to_a(t_env *env);
void				do_the_job_a(t_env *env, int half);
void				keep_ltl_a(t_env *env, int a, int b, int c);
void				keep_big_a(t_env *env, int a, int b, int c);

int					sort_lst_two(t_env *env);
int					sort_lst_two_reverse(t_env *env);
void				put_lowest(t_env *env);
void				put_bigger(t_env *env);

void				sort_lst_three(t_env *env);
void				sort_three_end(t_env *env);
void				find_bigger(t_env *env);
void				find_smaller(t_env *env);
void				longest_sequence_base(t_env *env);
int					actual_sequence_base(t_env *env, int index);
int					scan_list(t_env *env);

void				sort_lst_three_special(t_env *env);
void				sort_three_special_end(t_env *env);
void				longest_sequence_special(t_env *env);
int					actual_sequence_special(t_env *env, int index);
int					scan_list_special(t_env *env);

void				sort_list_four(t_env *env, int off);
void				put_larger_accessible(t_env *env);
void				put_smaller_accessible(t_env *env);

int					wich_side(t_list *lst, int value);
int					get_lower(t_list *lst);
int					get_bigger(t_list *lst);
int					get_bigger_than(t_list *lst, int i);
int					get_lower_than(t_list *lst, int i);
int					get_index(t_list *lst, int elem);

void				launch_nelson(t_env *env, int ltl_trash,
					int stack, int size);
void				looping(t_env *env, int stack,
					int loop, int way);
void				first_loop(t_env *env);
void				nelson_grow(t_env *env, int stack, int stackish);
void				nelson_exception(t_env *env, int stack,
					int stackish, int exception);

int					lst_sorted(t_list *lst);
void				reset_value(t_env *env);
void				pa(t_env *env);
void				pb(t_env *env);
void				sa(t_env *env);
void				sb(t_env *env);
void				ss(t_env *env);
void				ra(t_env *env);
void				rb(t_env *env);
void				rr(t_env *env);
void				rra(t_env *env);
void				rrb(t_env *env);
void				rrr(t_env *env);

void				finish_fill_b(t_env *env);
void				finish_fill_a(t_env *env);

int					bonus_flag(t_env *env, char **argv, int *arg);
void				print_list(t_env *env);
void				check_flag(t_env *env);
#endif
