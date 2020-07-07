/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_another_sort.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:02:08 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/28 23:36:21 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

static int		ft_divise(t_pile **a, t_pile **b, t_conv *conv)
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

int				ft_pivot(t_pile **pile)
{
	t_pile	*tmp;
	int		max;
	int		min;

	tmp = *pile;
	max = tmp->index;
	min = tmp->index;
	while ((tmp = tmp->next))
	{
		max = (max < tmp->index ? tmp->index : max);
		min = (min > tmp->index ? tmp->index : min);
	}
	return ((min + max) / 2);
}

int				ft_another_sort(t_pile *a, t_pile *b, t_conv *conv)
{
	ft_divise(&a, &b, conv);
	ft_sort_b(&a, &b, conv);
	ft_pile_del(&a);
	return (1);
}
