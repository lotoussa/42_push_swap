/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recursive.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 19:33:34 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 06:39:33 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

int		ft_split_pile(t_pile **a, t_pile **b, t_conv *conv)
{
	int		middle;
	t_pile	*tmp;

	tmp = *a;
	middle = conv->len / 2;
	while (ft_pile_size(*b) != middle)
	{
		tmp = *a;
		if (ft_last(tmp)->index >= middle)
			ft_printf(ft_sort_ra(a, b, conv) ? "ra\n" : "");
		else
			ft_printf(ft_sort_pb(a, b, conv) ? "pb\n" : "");
	}
	return (1);
}

int		ft_p_l(t_pile **pile, int send, t_conv *conv)
{
	t_pile	*tmp;
	int		min;
	int		max;
	int		i;

	i = -1;
	while (++i < send)
		ft_sort_ra(pile, NULL, conv);
	i = 0;
	max = (*pile)->index;
	min = (*pile)->index;
	tmp = *pile;
	while (++i < send && (tmp = tmp->next))
	{
		max = (max < tmp->index ? tmp->index : max);
		min = (min > tmp->index ? tmp->index : min);
	}
	while (send--)
		ft_sort_rra(pile, NULL, conv);
	return ((min + max) / 2);
}

void	ft_place_last(t_pile **a, t_pile **b, t_conv *conv, int nb)
{
	if (nb == 2)
		if ((*b)->index > (*b)->next->index)
			ft_printf(ft_sort_sb(a, b, conv) ? "sb\n" : "");
	while (*b)
		ft_printf(ft_sort_pa(a, b, conv) ? "pa\n" : "");
}

void	ft_end_recursive_b(t_pile **a, t_pile **b, t_conv *conv, int nb)
{
	while (nb--)
		if (ft_last(*a)->index == 0
				|| ft_last(*a)->index == (*a)->index + 1)
			ft_printf(ft_sort_ra(a, b, conv) ? "ra\n" : "");
}
