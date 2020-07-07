/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recursive.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 19:33:34 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 20:10:36 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

void			ft_recursive_a(t_pile **a, t_pile **b, t_conv *conv, int send)
{
	t_norm	n;

	n.count = 0;
	n.ra = 0;
	n.pivot = send % 2 == 0 ? ft_p_l(a, send, conv) : ft_p_l(a, send, conv) - 1;
	if (send < 3)
	{
		if (ft_last(*a)->index > ft_hijack(*a)->index)
			ft_printf(ft_sort_sa(a, b, conv) ? "sa\n" : "");
		while (send--)
			ft_printf(ft_sort_ra(a, b, conv) ? "ra\n" : "");
		return ;
	}
	while (n.count < send / 2)
	{
		n.count += ft_last(*a)->index > n.pivot ? 0 : 1;
		n.ra += ft_last(*a)->index > n.pivot ? 1 : 0;
		ft_printf(ft_last(*a)->index > n.pivot ? "ra\n" : "pb\n");
		ft_last(*a)->index > n.pivot ?
			ft_sort_ra(a, b, conv) : ft_sort_pb(a, b, conv);
	}
	while (n.ra-- > 0)
		ft_printf(ft_sort_rra(a, b, conv) ? "rra\n" : "");
	ft_recursive_b(a, b, conv);
	ft_recursive_a(a, b, conv, send - n.count);
}

void			ft_recursive_b(t_pile **a, t_pile **b, t_conv *conv)
{
	int		pivot;
	int		size;
	int		send;

	size = ft_pile_size(*b);
	pivot = size % 2 == 0 ? ft_pivot(b) : ft_pivot(b) - 1;
	send = 0;
	if (ft_pile_size(*b) < 3)
	{
		size = (*b)->next ? 2 : 1;
		ft_place_last(a, b, conv, size);
		ft_end_recursive_b(a, b, conv, size);
		return ;
	}
	while (ft_pile_size(*b) != size / 2)
	{
		send += ft_last(*b)->index > pivot ? 1 : 0;
		ft_printf(ft_last(*b)->index > pivot ? "pa\n" : "rb\n");
		ft_last(*b)->index > pivot ?
			ft_sort_pa(a, b, conv) : ft_sort_rb(a, b, conv);
	}
	ft_recursive_b(a, b, conv);
	ft_recursive_a(a, b, conv, send);
}

void			ft_next_split(t_pile **a, t_pile **b, t_conv *conv)
{
	int		size;

	size = conv->len % 2 == 0 ? conv->len / 2 : conv->len / 2 + 1;
	while (ft_pile_size(*b) != size)
		ft_printf(ft_sort_pb(a, b, conv) ? "pb\n" : "");
	ft_recursive_b(a, b, conv);
}

int				ft_recursive(t_pile *a, t_pile *b, t_conv *conv)
{
	ft_split_pile(&a, &b, conv);
	ft_recursive_b(&a, &b, conv);
	ft_next_split(&a, &b, conv);
	ft_pile_del(&a);
	return (1);
}
