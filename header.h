/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 13:08:24 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 16:29:30 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_pile
{
	struct s_pile	*next;
	int				data;
	int				index;
}					t_pile;

typedef struct		s_conv
{
	int				*tab;
	int				len;
}					t_conv;

typedef struct		s_type
{
	int				(*p[11]) (t_pile **a, t_pile **b);
	char			*type[11];
}					t_type;

typedef struct		s_back
{
	int				(*p[3]) (t_pile **a, t_pile **b, t_conv *conv);
	char			*type[3];
	char			*save;
}					t_back;

typedef struct		s_norm
{
	int				count;
	int				pivot;
	int				ra;
}					t_norm;

int					main(int argc, char **argv);
int					ft_fill_a(t_pile **pile, int argc, char **argv);
char				**ft_read_stdin();
long				ft_atol(const char *str, int *check);
int					ft_exec_ins(char **ins, t_pile **a, t_pile **b);
int					ft_sort_sa_r(t_pile **a, t_pile **b);
int					ft_sort_sb_r(t_pile **a, t_pile **b);
int					ft_sort_ss_r(t_pile **a, t_pile **b);
int					ft_sort_pa_r(t_pile **a, t_pile **b);
int					ft_sort_pb_r(t_pile **a, t_pile **b);
int					ft_sort_ra_r(t_pile **a, t_pile **b);
int					ft_sort_rb_r(t_pile **a, t_pile **b);
int					ft_sort_rr_r(t_pile **a, t_pile **b);
int					ft_sort_rra_r(t_pile **a, t_pile **b);
int					ft_sort_rrb_r(t_pile **a, t_pile **b);
int					ft_sort_rrr_r(t_pile **a, t_pile **b);
int					ft_sort_sa(t_pile **a, t_pile **b, t_conv *conv);
int					ft_sort_sb(t_pile **a, t_pile **b, t_conv *conv);
int					ft_sort_ss(t_pile **a, t_pile **b, t_conv *conv);
int					ft_sort_pa(t_pile **a, t_pile **b, t_conv *conv);
int					ft_sort_pb(t_pile **a, t_pile **b, t_conv *conv);
int					ft_sort_ra(t_pile **a, t_pile **b, t_conv *conv);
int					ft_sort_rb(t_pile **a, t_pile **b, t_conv *conv);
int					ft_sort_rr(t_pile **a, t_pile **b, t_conv *conv);
int					ft_sort_rra(t_pile **a, t_pile **b, t_conv *conv);
int					ft_sort_rrb(t_pile **a, t_pile **b, t_conv *conv);
int					ft_sort_rrr(t_pile **a, t_pile **b, t_conv *conv);
t_pile				*ft_recreate_elem_r(int data);
t_pile				*ft_recreate_elem(int data, t_conv *conv);
int					ft_pile_size(t_pile *pile);
int					ft_check_sort(t_pile *a, t_pile *b);
int					ft_try_sort(t_pile *a, t_pile *b, t_conv *conv);
int					ft_pile_max(t_pile *pile, int *size);
t_pile				*ft_last(t_pile *pile);
void				ft_pile_del(t_pile **pile);
int					ft_little_sort(t_pile *a, t_conv *conv);
int					ft_pile_second_max(t_pile *pile);
int					ft_convert_tab(t_pile **a, t_conv *conv);
void				ft_fill_index(t_pile **a, t_conv *conv);
int					ft_reset_conv(t_conv *conv);
int					ft_backtracking_sort(t_pile *a, t_pile *b, t_conv *conv);
int					ft_another_sort(t_pile *a, t_pile *b, t_conv *conv);
int					ft_three_sort(t_pile **a, t_pile **b, t_conv *conv);
int					ft_check_resort(t_pile **a, t_pile **b, t_conv *conv);
t_pile				*ft_hijack(t_pile *pile);
int					ft_norme_sort(t_pile **a, t_pile **b, t_conv *conv);
int					ft_data_side(t_pile *pile);
int					ft_first_repush(t_pile **a, t_pile **b, t_conv *conv);
void				ft_sort_a(t_pile **a, t_pile **b, t_conv *conv);
void				ft_sort_b(t_pile **a, t_pile **b, t_conv *conv);
int					ft_pivot(t_pile **pile);
int					ft_another_check_sort(t_pile *pile, t_pile *b);
int					ft_recursive(t_pile *a, t_pile *b, t_conv *conv);
void				ft_recursive_b(t_pile **a, t_pile **b, t_conv *conv);
void				ft_recursive_a(t_pile **a, t_pile **b,
		t_conv *conv, int send);
int					ft_p_l(t_pile **pile, int send, t_conv *conv);
int					ft_split_pile(t_pile **a, t_pile **b, t_conv *conv);
void				ft_place_last(t_pile **a, t_pile **b, t_conv *conv, int nb);
void				ft_end_recursive_b(t_pile **a, t_pile **b,
		t_conv *conv, int nb);
void				ft_print(t_pile **pile);

#endif
