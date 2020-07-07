/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_exec_ins.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 12:01:40 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 15:21:17 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

static int		ft_check_ins(char *ins, t_type tp)
{
	int		j;

	j = -1;
	while (++j < 11)
		if (!ft_strcmp(ins, tp.type[j]))
			return (1);
	return (0);
}

static void		ft_init_ptr(t_type *tp)
{
	tp->p[0] = &ft_sort_sa_r;
	tp->p[1] = &ft_sort_sb_r;
	tp->p[2] = &ft_sort_ss_r;
	tp->p[3] = &ft_sort_pa_r;
	tp->p[4] = &ft_sort_pb_r;
	tp->p[5] = &ft_sort_ra_r;
	tp->p[6] = &ft_sort_rb_r;
	tp->p[7] = &ft_sort_rr_r;
	tp->p[8] = &ft_sort_rra_r;
	tp->p[9] = &ft_sort_rrb_r;
	tp->p[10] = &ft_sort_rrr_r;
	tp->type[0] = ft_strdup("sa");
	tp->type[1] = ft_strdup("sb");
	tp->type[2] = ft_strdup("ss");
	tp->type[3] = ft_strdup("pa");
	tp->type[4] = ft_strdup("pb");
	tp->type[5] = ft_strdup("ra");
	tp->type[6] = ft_strdup("rb");
	tp->type[7] = ft_strdup("rr");
	tp->type[8] = ft_strdup("rra");
	tp->type[9] = ft_strdup("rrb");
	tp->type[10] = ft_strdup("rrr");
}

static void		ft_free_ptr(t_type *tp)
{
	int		j;

	j = -1;
	while (++j < 11)
		ft_strdel(&tp->type[j]);
	j = -1;
	while (++j < 11)
		tp->p[j] = NULL;
}

int				ft_exec_sort(t_type tp, char *ins, t_pile **a, t_pile **b)
{
	int		j;

	j = -1;
	while (++j < 11)
		if (!ft_strcmp(ins, tp.type[j]))
			break ;
	return (tp.p[j](a, b) ? 1 : 0);
}

int				ft_exec_ins(char **ins, t_pile **a, t_pile **b)
{
	int		i;
	t_type	tp;

	if (*ins == NULL)
		return (1);
	i = -1;
	ft_init_ptr(&tp);
	while (ins[++i])
		if (!(ft_check_ins(ins[i], tp)))
		{
			ft_free_ptr(&tp);
			return (0);
		}
	i = -1;
	while (ins[++i])
		if (!(ft_exec_sort(tp, ins[i], a, b)))
		{
			ft_free_ptr(&tp);
			return (0);
		}
	ft_free_ptr(&tp);
	return (1);
}
