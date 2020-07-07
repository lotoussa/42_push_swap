/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_resort.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/25 02:31:34 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 12:03:18 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

t_pile		*ft_hijack(t_pile *pile)
{
	while (pile->next->next)
		pile = pile->next;
	return (pile);
}

int			ft_norme_sort(t_pile **a, t_pile **b, t_conv *conv)
{
	t_pile	*tmp;
	t_pile	*sw;

	tmp = *a;
	sw = *b;
	if (ft_last(tmp)->index == 0 || ft_last(tmp)->index == tmp->index + 1)
	{
		ft_printf(ft_sort_ra(a, b, conv) ? "ra\n" : "");
		return (1);
	}
	if (ft_last(tmp)->index == ft_hijack(tmp)->index + 1)
	{
		ft_printf(ft_sort_sa(a, b, conv) ? "sa\n" : "");
		return (1);
	}
	return (0);
}

static int	ft_check_position(t_pile **a, t_pile **b, t_conv *conv)
{
	t_pile	*tmp;
	t_pile	*sw;
	int		count;
	int		i;

	tmp = *a;
	sw = *b;
	count = 0;
	i = -1;
	while (ft_last(tmp)->index != tmp->next->next->next->index + 1)
	{
		ft_printf(ft_sort_ra(a, b, conv) ? "ra\n" : "");
		count++;
	}
	ft_printf(ft_sort_pb(a, b, conv) ? "pb\n" : "");
	while (count--)
		ft_printf(ft_sort_rra(a, b, conv) ? "rra\n" : "");
	while (++i < 3)
		ft_printf(ft_sort_rra(a, b, conv) ? "rra\n" : "");
	ft_printf(ft_sort_pa(a, b, conv) ? "pa\n" : "");
	ft_printf(ft_sort_ra(a, b, conv) ? "ra\n" : "");
	return (1);
}

int			ft_check_resort(t_pile **a, t_pile **b, t_conv *conv)
{
	t_pile	*tmp;
	t_pile	*sw;
	int		i;

	tmp = *a;
	sw = *b;
	i = -1;
	while (++i < 3)
		ft_printf(ft_sort_ra(a, b, conv) ? "ra\n" : "");
	while (i--)
		ft_printf(ft_sort_pb(a, b, conv) ? "pb\n" : "");
	ft_three_sort(a, b, conv);
	ft_check_position(a, b, conv);
	while (ft_last(*a)->index == (*a)->index + 1)
		ft_printf(ft_sort_ra(a, b, conv) ? "ra\n" : "");
	while (*b)
		ft_printf(ft_sort_pa(a, b, conv) ? "pa\n" : "");
	return (1);
}
