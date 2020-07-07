/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_pile.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/27 19:16:21 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 02:35:14 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

void		ft_sort_a(t_pile **a, t_pile **b, t_conv *conv)
{
	int		max;

	max = ft_pile_max(*a, 0);
	while (!ft_another_check_sort(*a, *b))
		if (ft_last(*a)->data == max || ft_pile_second_max(*a))
			ft_printf(ft_sort_ra(a, b, conv) ? "ra\n" : "");
		else if (!ft_another_check_sort(*a, *b))
			ft_printf(ft_sort_pb(a, b, conv) ? "pb\n" : "");
	while (*b)
	{
		if (ft_last(*b)->data == ft_pile_max(*b, 0))
			ft_printf(ft_sort_pa(a, b, conv) ? "pa\n" : "");
		else if (ft_hijack(*b)->index == ft_last(*a)->index - 1
				&& ft_last(*b)->index == ft_last(*a)->index - 2)
			ft_printf(ft_sort_sb(a, b, conv) ? "sb\n" : "");
		else if (ft_data_side(*b))
			ft_printf(ft_sort_rrb(a, b, conv) ? "rrb\n" : "");
		else
			ft_printf(ft_sort_rb(a, b, conv) ? "rb\n" : "");
	}
}

int			ft_b_position(t_pile **b)
{
	t_pile	*tmp;
	int		pivot;
	int		size;
	int		i;

	tmp = *b;
	size = ft_pile_size(tmp);
	pivot = size % 2 == 0 ? ft_pivot(b) : ft_pivot(b) - 1;
	i = 0;
	while (tmp)
	{
		if (tmp->index > pivot && i < size / 2)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void		ft_sort_b(t_pile **a, t_pile **b, t_conv *conv)
{
	int		pivot;
	int		size;

	size = ft_pile_size(*b);
	pivot = size % 2 == 0 ? ft_pivot(b) : ft_pivot(b) - 1;
	if (size <= conv->len / 3 || ft_b_position(b))
		return (ft_sort_a(a, b, conv));
	while ((*b)->next->next && ft_pile_size(*b) != size / 2)
	{
		ft_printf(ft_last(*b)->index > pivot ? "pa\n" : "rb\n");
		ft_last(*b)->index > pivot ?
			ft_sort_pa(a, b, conv) : ft_sort_rb(a, b, conv);
	}
	ft_sort_b(a, b, conv);
}
