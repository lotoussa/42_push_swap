/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_max.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 02:13:07 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/28 22:10:05 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

int		ft_pile_max(t_pile *pile, int *size)
{
	int		max;

	max = pile ? pile->data : 0;
	while (pile)
	{
		max = (max < pile->data ? pile->data : max);
		pile = pile->next;
		size++;
	}
	return (max);
}

t_pile	*ft_last(t_pile *pile)
{
	while (pile->next)
		pile = pile->next;
	return (pile);
}

int		ft_pile_second_max(t_pile *pile)
{
	int		max;
	int		current;

	max = ft_pile_max(pile, 0);
	current = ft_last(pile)->data;
	while (pile)
	{
		if (pile->data > current && pile->data != max && pile->data != current)
			return (0);
		pile = pile->next;
	}
	return (1);
}

int		ft_three_sort(t_pile **a, t_pile **b, t_conv *conv)
{
	t_pile	*t;
	t_pile	*g;

	t = *a;
	g = *b;
	if (g->index < g->next->index && g->next->index < ft_last(g)->index)
		return (1);
	else if (ft_last(g)->index > g->index && g->index > g->next->index)
	{
		ft_printf(ft_sort_sb(a, b, conv) ? "sb\n" : "");
		ft_printf(ft_sort_rb(a, b, conv) ? "rb\n" : "");
	}
	else if (ft_last(g)->index < g->index && g->index < g->next->index)
		ft_printf(ft_sort_rb(a, b, conv) ? "rb\n" : "");
	else if (g->index > g->next->index && g->next->index > ft_last(g)->index)
	{
		ft_printf(ft_sort_sb(a, b, conv) ? "sb\n" : "");
		ft_printf(ft_sort_rrb(a, b, conv) ? "rrb\n" : "");
	}
	else if (g->index < g->next->index && g->next->index > ft_last(g)->index)
		ft_printf(ft_sort_sb(a, b, conv) ? "sb\n" : "");
	else if (g->index > g->next->index && g->next->index < ft_last(g)->index)
		ft_printf(ft_sort_rrb(a, b, conv) ? "rrb\n" : "");
	return (1);
}
