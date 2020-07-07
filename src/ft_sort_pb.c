/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_pb.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 14:47:26 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 19:16:57 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header.h"

static int			ft_del_elem(t_pile **pile)
{
	t_pile		*tmp;
	t_pile		*prev;
	int			size;

	prev = *pile;
	size = (ft_pile_size(prev) - 2);
	if (size < 0)
	{
		free(*pile);
		*pile = NULL;
		return (1);
	}
	while (size-- > 0)
		prev = prev->next;
	tmp = prev->next;
	prev->next = NULL;
	free(tmp);
	return (1);
}

int					ft_sort_pb(t_pile **a, t_pile **b, t_conv *conv)
{
	t_pile	*last;
	t_pile	*tmp;

	if (!*a)
		return (1);
	last = ft_last(*a);
	if (!*b)
		*b = ft_recreate_elem(last->data, conv);
	else
	{
		tmp = ft_last(*b);
		tmp->next = ft_recreate_elem(last->data, conv);
	}
	return (ft_del_elem(a));
}
